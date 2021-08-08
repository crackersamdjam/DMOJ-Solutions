#include <bits/stdc++.h>
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nl a[rt].l
#define nr a[rt].r
#define m ((nl+nr)>>1)
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 250001;

int N, M, v[MM];

struct node{
    int l, r, val[11], lp;
} a[MM*4];

inline int sum(int rt){
    int ret = 0;
    for(int i = 1; i <= 9; i++)
        ret += i*a[rt].val[i];
    return ret;
}

inline void push_up(int rt){
    for(int i = 0; i <= 9; i++)
        a[rt].val[i] = a[lc].val[i] + a[rc].val[i];
}

void build(int l, int r, int rt = 1){
    a[rt].l = l, a[rt].r = r;
    if(nl == nr){
        a[rt].val[v[l]] = 1;
        return;
    }
    build(l, m, lc);
    build(m+1, r, rc);
    push_up(rt);
}

inline void shift(int rt, int k){
    node &n = a[rt];
    while(k--){
        for(int i = 10; i; i--)
            n.val[i] = n.val[i-1];
        n.val[0] = n.val[10];
    }
}

inline void push_down(int rt){
    int val = a[rt].lp % 10;
    if(val && nl^nr){
        a[lc].lp += val;
        a[rc].lp += val;
        shift(lc, val);
        shift(rc, val);
    }
    a[rt].lp = 0;
}

void update(int l, int r, int rt = 1){
    if(nl > r || nr < l)
        return;
    if(l <= nl && r >= nr){
        a[rt].lp++;
        shift(rt, 1);
        return;
    }
    push_down(rt);
    update(l, r, lc);
    update(l, r, rc);
    push_up(rt);
}

int query(int l, int r, int rt = 1){
    if(nl > r || nr < l)
        return 0;
    if(l <= nl && r >= nr)
        return sum(rt);

    push_down(rt);
    return query(l, r, lc) + query(l, r, rc);
}

int main(){
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++)
        v[i] = gc-'0';
    
    build(1, N);
    
    for(int i = 0,l,r; i < M; i++){
        scan(l, r);
        print(query(l, r));
        update(l, r, 1);
    }
    
    return 0;
}