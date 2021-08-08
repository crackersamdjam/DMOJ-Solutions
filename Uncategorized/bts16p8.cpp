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

using namespace std;
typedef long long ll;
const int MM = (5e5+2)*3, mod = 1e9+7;

int N;
ll ans;
map<int, int> mp;
int rx[MM];

struct node{
    int l, r, v, lp;
} tree[MM*3];

void build(int l, int r, int rt = 1){
    nl = l, nr = r;
    if(l == r)
        return;
    build(l, m, lc);
    build(m+1, r, rc);
}

void push_up(int rt){
    tree[rt].v = max(tree[lc].v, tree[rc].v);
}

void push_down(int rt){
    int &v = tree[rt].lp;
    if((nl ^ nr) && v){
        tree[lc].v = max(tree[lc].v, v);
        tree[lc].lp = max(tree[lc].lp, v);
        tree[rc].v = max(tree[rc].v, v);
        tree[rc].lp = max(tree[rc].lp, v);
    }
    v = 0;
}

int query(int l, int r, int rt = 1){
    if(r < nl || nr < l)
        return 0;
    if(l <= nl && nr <= r)
        return tree[rt].v;
    push_down(rt);
    return max(query(l, r, lc), query(l, r, rc));
}

void update(int l, int r, int v, int rt = 1){
    if(r < nl || l > nr)
        return;
    if(l <= nl && r >= nr){
        tree[rt].v = v;
        tree[rt].lp = v;
        return;
    }
    push_down(rt);
    update(l, r, v, lc);
    update(l, r, v, rc);
    push_up(rt);
}

struct st{
    int s, l, w;
} q[MM];

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        scan(q[i].s, q[i].l, q[i].w);
        mp[q[i].s] = mp[q[i].s-1] = mp[q[i].s+q[i].l-1] = 0;
    }
    
    int t = 0;
    
    for(auto &it: mp){
        it.second = ++t;
        rx[t] = it.first;
    }
    
    build(1, t);
    
    for(int i = 0; i < N; i++){
        
        int s = mp[q[i].s], l = mp[q[i].s+q[i].l-1], w = q[i].w;
        
        ans -= (ll)q[i].l*w;
        int h = query(s, l) + w;
        update(s, l, h);
    }
    
    for(int i = 1; i <= t; i++)
        ans += (ll)query(i, i)*(rx[i]-rx[i-1]);
    
    print(ans%mod);
    
    return 0;
}