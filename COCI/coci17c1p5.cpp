#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define nl tree[rt].l
#define nr tree[rt].r
#define m ((nl+nr)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define v tree[rt].val

using namespace std;
const int MM = 2e5+1;

int N, Q;

struct node{
    int l, r, val;
} tree[MM*3];

void build(int l = 1, int r = N, int rt = 1){
    nl = l, nr = r, v = INT_MAX;
    if(nl == nr)
        return;
    build(l, m, lc);
    build(m+1, r, rc);
}

void update(int l, int n, int rt = 1){
    if(nl == nr){
        assert(nl == l);
        v = n;
        return;
    }
    update(l, n, (l <= m) ? lc: rc);
    v = min(tree[lc].val, tree[rc].val);
}

int query(int l, int n, int rt = 1){
    
    if(nl == nr){
        return (v <= n) ? nl : INT_MAX;
    }
    if((l <= m) && tree[lc].val <= n){
        int t = query(l, n, lc);
        if(t ^ INT_MAX) return t;
    }
    return query(l, n, rc);
}

int main(){
    
    scan(N, Q);
    
    build();
    
    for(int i = 0,a,b; i < Q; i++){
        if(gc == 'M'){
            scan(a, b);
            update(b, a);
        }
        else{
            scan(a, b);
            int ans = query(b, a);
            print(ans == INT_MAX? -1: ans);
        }
    }
    
    return 0;
}