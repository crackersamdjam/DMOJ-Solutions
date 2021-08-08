#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MM = 3e4+2;
struct{
    int l,r,val,lp;
} a[3*MM];
int N,Q,n[MM];
inline void push_up(int rt){
    a[rt].val = min(a[rt<<1].val, a[rt<<1 | 1].val);
}
inline void push_down(int rt){
    int &val = a[rt].lp;
    if(val && a[rt].l != a[rt].r){
        a[rt<<1].lp += val;
        a[rt<<1].val -= val;
        a[rt<<1].val = max(a[rt<<1].val, 0);
        a[rt<<1 | 1].lp += a[rt].lp;
        a[rt<<1 | 1].val -= val;
        a[rt<<1 | 1].val = max(a[rt<<1 | 1].val, 0);
    }
    val = 0;
}
void build(int l, int r, int rt){
    a[rt].l = l, a[rt].r = r;
    if(l == r){
        a[rt].val = n[l];
        return;
    }
    int m = (l+r)>>1;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1 | 1);
    push_up(rt);
}
void update(int l, int r, int rt, int val){
    int nl = a[rt].l, nr = a[rt].r;
    if(r < nl || l > nr)
        return;
    if(l <= nl && r >= nr){
        a[rt].val = max(0, a[rt].val - val);
        a[rt].lp += val;
        return;
    }
    push_down(rt);
    update(l, r, rt<<1, val);
    update(l, r, rt<<1 | 1, val);
    push_up(rt);
}
int query(int l, int r, int rt){
    int nl = a[rt].l, nr = a[rt].r;
    if(l <= nl && r >= nr)
        return a[rt].val;
    if(r < nl || l > nr)
        return 0x3f3f3f3f;
    push_down(rt);
    return min(query(l, r, rt<<1), query(l, r, rt<<1 | 1));
}
int main(){
    sc(N); sc(Q);
    for(int i = 1; i <= N; i++)
        sc(n[i]);
    
    build(1, N, 1);
    for(int i = 0,a,b,c; i < Q; i++){
        sc(a); sc(b); sc(c);
        update(a, b, 1, c);
        printf("%d %d\n", query(a, b, 1), query(1, N, 1));
    }
    return 0;
}