#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using T = ll;
const int MM = 3e5+5;

int m, n, ptr;

struct node{
    T val, lp;
    void apply(T v){
        val = min(val, v);
        lp = min(lp, v);
    }
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node tree[MM*4];
    T DEF = 1e16;
    //default value
    
    T merge(T va, T vb){
        return min(va, vb);
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    
    // node with lazy val means yet to push to children (but updated itself)
    void push_down(int rt, int nl, int nr){
        T &val = tree[rt].lp;
        if(nl != nr){
            tree[lc].apply(val);
            tree[rc].apply(val);
        }
        val = DEF;
    }
    
    void build(int l = 1, int r = ptr, int rt = 1){
        int nl = l, nr = r;
        tree[rt].val = DEF;
        tree[rt].lp = DEF;
        if(l == r)
            return;
        build(l, nm, lc);
        build(nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, T val, int nl = 1, int nr = ptr, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            tree[rt].apply(val);
            return;
        }
        push_down(rt, nl, nr);
        update(l, r, val, nl, nm, lc);
        update(l, r, val, nm+1, nr, rc);
        push_up(rt);
    }
    
    T query(int l, int r, int nl = 1, int nr = ptr, int rt = 1){
        if(r < nl || l > nr)
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt].val;
        push_down(rt, nl, nr);
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
#undef lc
#undef rc
#undef nm
} TL, TR;

ll ans = 1e16;
map<int, int> mx;
int ia[MM], ib[MM], ic[MM];
ll id[MM];

int main(){
    scan(m, n);
    for(int i = 0; i < m; i++){
        scan(ia[i], ib[i], ic[i], id[i]);
        mx[ia[i]] = mx[ib[i]] = mx[ic[i]] = 0;
    }
    mx[1] = mx[n] = 0;
    for(auto &i: mx)
        i.second = ++ptr;
    TL.build();
    TR.build();
    TL.update(1, 1, 0);
    TR.update(ptr, ptr, 0);
    for(int i = 0,a,b,c; i < m; i++){
        a = mx[ia[i]], b = mx[ib[i]], c = mx[ic[i]];
        ll d = id[i];
        ll v = TL.query(a, b);
        TL.update(c, c, v+d);
        
        ll v2 = TR.query(a, b);
        TR.update(c, c, v2+d);
        
        ans = min(ans, v+v2+d);
    }
    
    if(ans == 1e16)
        ans = -1;
    print(ans);
    
    return 0;
}