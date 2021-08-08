#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+1;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nl a[rt].l
#define nr a[rt].r
#define nm ((nl+nr)>>1)

int N, Q;
ll v[MM];

struct node{
    int l, r;
    ll sum, max, pre, suf;
} a[MM*3];

void merge(node &n, node l, node r){
    n.sum = l.sum + r.sum;
    n.max = max(max(l.max, r.max), l.suf + r.pre);
    n.pre = max(l.pre, l.sum + r.pre);
    n.suf = max(r.suf, r.sum + l.suf);
}

void push_up(int rt){
    merge(a[rt], a[lc], a[rc]);
}

void build(int l, int r, int rt = 1){
    nl = l, nr = r;
    if(l == r){
        a[rt].sum = a[rt].max = a[rt].pre = a[rt].suf = v[l];
        return;
    }
    build(l, nm, lc);
    build(nm+1, nr, rc);
    push_up(rt);
}

node query(int l, int r, int rt = 1){
    if(l <= nl && nr <= r)
        return a[rt];
    if(r <= nm)
        return query(l, r, lc);
    if(l > nm)
        return query(l, r, rc);
    node ret;
    merge(ret, query(l, r, lc), query(l, r, rc));
    return ret;
}

void update(int l, int val, int rt = 1){
    if(nl == nr){
        a[rt].sum = a[rt].max = a[rt].pre = a[rt].suf = val;
        return;
    }
    update(l, val, l <= nm ? lc : rc);
    push_up(rt);
}

int main(){
    
    scan(N, Q);
    
    for(int i = 1; i <= N; i++)
        scan(v[i]);
    
    build(1, N);
    
    for(int i = 0,op,f,s; i < Q; i++){
        op = gc;
        scan(f, s);
        if(op == 'S')
            update(f, s);
        else
            print(query(f, s).max);
    }
    
    return 0;
}