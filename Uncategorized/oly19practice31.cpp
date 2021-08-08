#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}
const int MM = 3e5+5;
using ll = long long;
using T = ll;

constexpr ll inf = 1e15;

struct node{
    T val, lp;
    bool up;
    void apply(T v){
        val += v;
        lp += v;
        up = 1;
    }
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node tree[MM*4];
    T DEF = 0;
    //default value
    
    T merge(T va, T vb){
        return max(va, vb);
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    
    // node with lazy val means yet to push to children (but updated itself)
    void push_down(int rt, int nl, int nr){
        T &val = tree[rt].lp;
        if(tree[rt].up && nl != nr){
            tree[lc].apply(val);
            tree[rc].apply(val);
        }
        val = DEF;
        tree[rt].up = 0;
    }
    
    void build(int l = 0, int r = MM-1, int rt = 1){
        int nl = l, nr = r;
        tree[rt].val = DEF;
        tree[rt].lp = 0;
        tree[rt].up = 0;
        if(l == r){
            return;
        }
        build(l, nm, lc);
        build(nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, T val, int nl = 0, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            if(val == 0){
                tree[rt].val = tree[rt].lp = 0;
            }
            else
                tree[rt].apply(val);
            return;
        }
        push_down(rt, nl, nr);
        update(l, r, val, nl, nm, lc);
        update(l, r, val, nm+1, nr, rc);
        push_up(rt);
    }
    
    T query(int l, int r, int nl = 0, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return -inf;
        if(l <= nl && r >= nr)
            return tree[rt].val;
        push_down(rt, nl, nr);
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
#undef lc
#undef rc
#undef nm
} t;

struct node2{
    T val, lp;
    bool up;
    void apply(T v){
        val += v;
        lp += v;
        up = 1;
    }
};

struct segtree2{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node2 tree[MM*4];
    T DEF = 0;
    //default value
    
    T merge(T va, T vb){
        return va + vb;
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    
    // node with lazy val means yet to push to children (but updated itself)
    void push_down(int rt, int nl, int nr){
        T &val = tree[rt].lp;
        if(tree[rt].up && nl != nr){
            tree[lc].apply(val);
            tree[rc].apply(val);
        }
        val = DEF;
        tree[rt].up = 0;
    }
    
    void build(int l = 0, int r = MM-1, int rt = 1){
        int nl = l, nr = r;
        tree[rt].val = DEF;
        tree[rt].lp = 0;
        tree[rt].up = 0;
        if(l == r){
            return;
        }
        build(l, nm, lc);
        build(nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, T val, int nl = 0, int nr = MM-1, int rt = 1){
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
    
    T query(int l, int r, int nl = 0, int nr = MM-1, int rt = 1){
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
} t2;

int hi, lo = 1e9;
int n, a[MM],id[MM], b[MM];
ll cnt, best;
set<pair<int, int>> rm;

int main(){
    init();
    scan(n);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        cnt += t2.query(a[i], MM-1);
        t2.update(a[i], a[i], 1);
        if(a[i] > hi){
            hi = a[i];
            id[i] = 1;
        }
    }
    for(int i = n; i; i--){
        if(a[i] < lo){
            lo = a[i];
            id[i] = 2;
        }
    }

    t.build();
    t.update(0, MM-1, -inf);
    int hii = 0;

    for(int i = 1; i <= n; i++){
        if(!id[i]){
            t.update(a[i], hii, 1);
            rm.insert({a[i], hii});
        }
        else if(id[i] == 1){
            hii = a[i];
            t.update(a[i], a[i], 0);
        }
        else{
            while(rm.size() and rm.begin()->first < a[i]){
                t.update(rm.begin()->first, rm.begin()->second, -1);
                rm.erase(rm.begin());
            }
            best = max(best, 2*t.query(a[i], MM-1));
        }
    }

    print(cnt-best);

    return 0;
}