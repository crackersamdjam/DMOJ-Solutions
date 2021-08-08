#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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
const int MM = 2e5+5, LOG = 16;
const ll mod = 998244353;

ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}

struct node{
    T val, lp, sum;
    void apply(T v){
        val += v*sum;
        val %= mod;
        lp += v;
    }
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node tree[MM*4];
    T DEF = 0;
    
    T merge(T va, T vb){
        return (va + vb) % mod;
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
        tree[rt].sum = merge(tree[lc].sum, tree[rc].sum);
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
    
    void build(int l = 0, int r = MM-1, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            tree[rt].val = DEF;
            tree[rt].lp = 0;
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
            if(val < 0)
                tree[rt].sum = -val;
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
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt].val;
        push_down(rt, nl, nr);
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
#undef lc
#undef rc
#undef nm
} t;

int n, q, k;
vector<int> adj[MM];

int par[MM], dep[MM], heavy[MM], head[MM], pos[MM], ptr;

int dfs(int cur, int pre){
    int size = 1, maxsz = 0;
    for(int u : adj[cur]){
        if(u == pre)
            continue;
        par[u] = cur, dep[u] = dep[cur]+1;
        int szu = dfs(u, cur);
        size += szu;
        if(szu > maxsz)
            maxsz = szu, heavy[cur] = u;
    }
    return size;
}

void decompose(int cur, int id){
    head[cur] = id, pos[cur] = ++ptr;
    if(~heavy[cur])
        decompose(heavy[cur], id);
    for(int u: adj[cur]){
        if(u != par[cur] && u != heavy[cur])
            decompose(u, u);
    }
}

void init(){
    memset(heavy, -1, sizeof heavy);
    ptr = 0;
    adj[0].push_back(1);
    dfs(0, -1);
    decompose(1, 1);
    t.build();
}

int query(int a, int b){
    int res = 0;
    for(; head[a] != head[b]; b = par[head[b]]){
        if(dep[head[a]] > dep[head[b]])
            swap(a, b);
        res += t.query(pos[head[b]], pos[b]);
        res %= mod;
    }
    if(a != b){
        if(dep[a] > dep[b])
            swap(a, b);
        res += t.query(pos[a]+1, pos[b]);
        res %= mod;
    }
    return res;
}

void update(int a, int b, ll v = 1){
    for(; head[a] != head[b]; b = par[head[b]]){
        if(dep[head[a]] > dep[head[b]])
            swap(a, b);
        int l = pos[head[b]], r = pos[b];
        t.update(l, r, v);
    }
    if(a != b){
        if(dep[a] > dep[b])
            swap(a, b);
        t.update(pos[a]+1, pos[b], v);
    }
}

struct st{
    int x, y, i;
} a[MM];
int out[MM];

int main(){
    
    scan(n, q, k);
    
    for(int i = 2,p; i <= n; i++){
        scan(p);
        adj[p].push_back(i);
    }
    
    init();
    for(int i = 1; i <= n; i++){
        ll v = fpow(dep[i], k, mod) - fpow(dep[i]-1, k, mod);
        if(v < 0)
            v += mod;
        update(par[i], i, -v);
    }
    
    for(int i = 0; i < q; i++){
        scan(a[i].x, a[i].y);
        a[i].i = i;
    }
    
    sort(a, a+q, [](st x, st y){
        return x.x < y.x;
    });
    
    for(int i = 1, l = 0; i <= n; i++){
        update(0, i);
        while(a[l].x == i){
//            print(a[l].x, a[l].y, a[l].i, i);
            out[a[l].i] = query(0, a[l].y);
            l++;
        }
    }
    
    for(int i = 0; i < q; i++)
        print(out[i]);
    
    return 0;
}
/*
5 4 2
1
2
3
4
1 3
5 3
2 4
4 2
 
 */