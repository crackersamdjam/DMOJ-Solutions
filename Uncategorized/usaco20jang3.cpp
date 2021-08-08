#include <bits/stdc++.h>
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
const int MM = 2e5+5;

ll n;
int k;
ll ans, dp[MM], lx[MM], ly[MM], rx[MM], ry[MM], d[MM];

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

struct node{
    T val;
};

struct segtree{
    
    node tree[MM*4];
    T DEF = 0;
    //default value
    
    T merge(T va, T vb){
        return max(va, vb);
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    
    void build(int l = 0, int r = MM-1, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            tree[rt].val = DEF;
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
            tree[rt].val = max(tree[rt].val, val);
            return;
        }
        update(l, r, val, nl, nm, lc);
        update(l, r, val, nm+1, nr, rc);
        push_up(rt);
    }
    
    T query(int l, int r, int nl = 0, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt].val;
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
} t;

struct st{
    int op; ll x, y; int i;
    //op 0 = query, op 1 = update (for segment i)
    bool operator<(const st &o) const{
        if(x != o.x)
            return x > o.x; //high x
        if(y != o.y)
            return y > o.y; //high y
        return op > o.op;
        //update first
    }
};
vector<st> v;
map<int, int> my;

int main(){
    //freopen("boards.in", "r", stdin); freopen("boards.out", "w", stdout);
    t.build();
    scan(n, k);
    for(int i = 0; i < k; i++){
        scan(lx[i], ly[i], rx[i], ry[i]);
        d[i] = rx[i]-lx[i]+ry[i]-ly[i];
        v.push_back({0, rx[i], ry[i], i});
        v.push_back({1, lx[i], ly[i], i});
    }
    //v.push_back({0, 0, 0, k});
    
    for(auto &i: v)
        my[i.y] = 0;
    int x = 1;
    for(auto &i: my)
        i.second = ++x;
    
    sort(v.begin(), v.end());
    for(auto p: v){
        //print(p.op, p.x, p.y, p.i);
        p.y = my[p.y];
        if(p.op == 0){
            dp[p.i] = t.query(p.y, MM-1) + d[p.i];
            ans = max(ans, dp[p.i]);
        }
        else{
            t.update(p.y, p.y, dp[p.i]);
        }
        //print(dp[p.i]);
    }
    
    print(2*n - ans);
    
    return 0;
}