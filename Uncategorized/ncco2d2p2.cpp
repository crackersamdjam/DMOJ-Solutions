#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

//#define ONLINE_JUDGE

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
using pii = pair<int, int>;
const int MM = 1e5+5, LOG = 18;

int sp[LOG][MM], dep[MM];

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && (dep[sp[i][u]] >= dep[v]))
            u = sp[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~sp[i][u] && ~sp[i][v] && (sp[i][u] != sp[i][v])){
            u = sp[i][u];
            v = sp[i][v];
        }
    }
    return sp[0][u];
}

int n, a[MM][4], c[MM], par[MM], pp[MM];
map<pii, int> mp;
set<int> adj[MM];
vector<int> v[MM];

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

void dfs(int cur, int pre){
    pp[cur] = pre;
    dep[cur] = dep[pre] + 1;
    sp[0][cur] = pre;
    
    printerr("dfs", cur, dep[cur]);
    
    for(int u: adj[cur])
        if(u != pre)
            dfs(u, cur);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scan(n);
    for(int i = 1; i <= n-2; i++){
        scan(a[i][0], a[i][1], a[i][2], a[i][3]);
        c[i] = a[i][3];
        v[c[i]].emplace_back(i);
        sort(a[i], a[i]+3);
        pii in;
        in = {a[i][0], a[i][1]};
        if(mp[in]){
            adj[i].insert(mp[in]);
            adj[mp[in]].insert(i);
            printerr("connect", i, mp[in]);
        }
        mp[in] = i;
        
        in = {a[i][0], a[i][2]};
        if(mp[in]){
            adj[i].insert(mp[in]);
            adj[mp[in]].insert(i);
            printerr("connect", i, mp[in]);
        }
        mp[in] = i;
        
        in = {a[i][1], a[i][2]};
        if(mp[in]){
            adj[i].insert(mp[in]);
            adj[mp[in]].insert(i);
            printerr("connect", i, mp[in]);
        }
        mp[in] = i;
    }
    set<int> in;
    int rt = 0;
    for(int i = 1; i <= n-2; i++){
        in.insert(i);
        par[i] = i;
        if(adj[i].size() <= 1){
            rt = i;
        }
    }
    
    memset(sp, -1, sizeof sp);
    assert(rt);
    dfs(rt, 0);
    
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n-2; j++){
            if(~sp[i-1][j])
                sp[i][j] = sp[i-1][ sp[i-1][j] ];
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(v[i].empty())
            continue;
        int lca = v[i][0];
        for(int u: v[i]){
            lca = getlca(lca, u);
        }
        printerr("col", i, lca);
        
        lca = find(lca);
        for(int u: v[i]){
            u = find(u);
            while(dep[u] > dep[lca]){
                // pp[u] = pp[lca]; //so that next time jump up more
                par[u] = par[find(lca)];
                u = pp[u];
                //u = pp[u] = find(pp[u]);
            }
        }
    }
    
    set<int> all;
    for(int i = 1; i <= n-2; i++){
        all.insert(find(i));
        printerr(i, find(i), dep[i], c[i]);
    }
    
    print(all.size()-1);
    
    return 0;
}
/*
is not a linear graph

6
1 2 3 1
3 4 5 1
1 3 5 2
5 6 1 1


 */