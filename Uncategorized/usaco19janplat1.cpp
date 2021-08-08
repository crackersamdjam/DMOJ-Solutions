#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
using T = int;
const int MM = 6e5+9, adj = 3e5+3;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

int n, k, dp[MM], ps[MM];
map<int, int> st[MM];

struct node{
    int val;
};

struct segtree{
    
    node tree[MM*4];
    T DEF = INT_MAX/2;
    //default value
    
    T merge(T va, T vb){
        return min(va, vb);
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    
    void build(int l = 1, int r = MM-1, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            st[l][DEF] = 1;
            tree[rt].val = DEF;
            return;
        }
        build(l, nm, lc);
        build(nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, T val, int op, int nl = 1, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            if(op == 1) st[l][val]++;
            else if(!--st[l][val])
                st[l].erase(val);
            tree[rt].val = st[l].begin()->first;
            return;
        }
        update(l, r, val, op, nl, nm, lc);
        update(l, r, val, op, nm+1, nr, rc);
        push_up(rt);
    }
    
    T query(int l, int r, int nl = 1, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt].val;
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
} seg;

int main(){
    
    scan(n, k);
    
    seg.build();
    seg.update(adj, adj, 0, 1);
    
    for(int i = 1; i <= n; i++){
        ps[i] = ps[i-1] + (gc == 'G' ? 1 : -1);
        dp[i] = min(seg.query(1, ps[i]+adj)+1, seg.query(ps[i]+1+adj, n+adj));
        seg.update(ps[i]+adj, ps[i]+adj, dp[i], 1);
        if(i >= k) seg.update(ps[i-k]+adj, ps[i-k]+adj, dp[i-k], 0);
    }
    
    print(dp[n]);
    
    return 0;
}