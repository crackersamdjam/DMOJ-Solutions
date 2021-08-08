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
typedef long long ll;
const int MM = 2e5+1;

int N, M, Q, in[MM];

struct node{
    int l, r;
    ll val, lp;
} a[MM*3];

inline void push_up(int rt){
    a[rt].val = a[lc].val + a[rc].val;
}

inline void push_down(int rt){
    ll val = a[rt].lp;
    if(val && nl^nr){
        a[lc].lp += val;
        a[lc].val += (m-nl+1)*val;
        a[rc].lp += val;
        a[rc].val += (nr-m)*val;
    }
    a[rt].lp = 0;
}

void update(int l, int r, ll val, int rt = 1){
    if(r < nl || l > nr)
        return;
    if(l <= nl && r >= nr){
        a[rt].val += (nr-nl+1)*val;
        a[rt].lp += val;
        return;
    }
    push_down(rt);
    update(l, r, val, lc);
    update(l, r, val, rc);
    push_up(rt);
}

ll query(int l, int r, int rt = 1){
    if(r < nl || l > nr)
        return 0;
    if(l <= nl && r >= nr)
        return a[rt].val;
    push_down(rt);
    return query(l, r, lc) + query(l, r, rc);
}

void build(int l, int r, int rt){
    a[rt].l = l, a[rt].r = r;
    if(l == r){
        a[rt].val = in[l];
        return;
    }
    build(l, m, lc);
    build(m+1, r, rc);
    push_up(rt);
}


int main(){

    scan(M, N, Q);

    for(int i = 1; i <= N; i++)
        scan(in[i]);

    build(1, N, 1);

    for(int i = 0, op, l, r; i < Q; i++){
        scan(op, l, r);
        if(op == 1){
            ll val;
            scan(val);
            update(l, r, val);
        }
        else
            print(query(l, r) % M);
    }

    return 0;
}