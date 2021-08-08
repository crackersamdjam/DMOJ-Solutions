#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+2;
int N,K,Q;
struct node{
    int l, r;
    ll val, lp;
} a[MM*3];
void build(int l, int r, int rt){
    a[rt].l = l, a[rt].r = r;
    if(l == r)
        return;
    int m = (l+r)/2;
    build(l, m, rt*2);
    build(m+1, r, rt*2+1);
}
inline void push_down(int rt){
    if(a[rt].l != a[rt].r && a[rt].lp){
        a[rt*2].lp += a[rt].lp;
        a[rt*2].val += a[rt].lp;
        a[rt*2+1].lp += a[rt].lp;
        a[rt*2+1].val += a[rt].lp;
    }
    a[rt].lp = 0;
}
void update(int l, int r, int rt, int val){
    if(a[rt].l > r || a[rt].r < l)
        return;
    if(a[rt].l >= l && a[rt].r <= r){
        a[rt].val += val;
        a[rt].lp += val;
        return;
    }
    push_down(rt);
    update(l, r, rt*2, val);
    update(l, r, rt*2+1, val);
    a[rt].val = max(a[rt*2].val, a[rt*2+1].val);
}
ll query(int l, int r, int rt){
    if(l <= a[rt].l && r >= a[rt].r)
        return a[rt].val;
    push_down(rt);
    int m = (a[rt].l + a[rt].r)/2;
    if(r <= m)
        return query(l, r, rt*2);
    else if(l > m)
        return query(l, r, rt*2+1);
    else
        return max(query(l, m, rt*2), query(m+1, r, rt*2+1));
}
int main(){
    scanf("%d%d%d",&N,&K,&Q);
    build(1, N+2, 1);
    int op,a,b;
    while(Q--){
        scanf("%d%d%d",&op,&a,&b);
        if(!op){
            a++;
            update(max(1, a-K+1), a, 1, b);
        }else{
            a++, b++;
            printf("%lld\n", query(a, b, 1));
        }
    }
    return 0;
}