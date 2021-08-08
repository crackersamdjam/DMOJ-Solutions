#include "factories.h"
#include <bits/stdc++.h>

#define min(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;
const int MM = 500000;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int N, sz[MM], tot, par[MM], dep[MM], path[MM], t;
ll dis[20][MM], best[MM];
bool vis[MM];
std::vector<std::pair<int, int>> adj[MM];

int getsz(int cur, int pre){
    sz[cur] = 1;
    for(auto e: adj[cur]){
        if(e.first != pre && !vis[e.first])
            sz[cur] += getsz(e.first, cur);
    }
    return sz[cur];
}

int findcent(int cur, int pre){
    for(auto e: adj[cur]){
        if(!vis[e.first] && e.first != pre && sz[e.first]*2 > tot)
            return findcent(e.first, cur);
    }
    return cur;
}

int dfs(int cur, int pre, int l){
    sz[cur] = 1;
    for(auto u: adj[cur]){
        if(u.first == pre || vis[u.first])
            continue;
        dis[l][u.first] = dis[l][cur] + u.second;
        sz[cur] += dfs(u.first, cur, l);
    }
    return sz[cur];
}

void go(int root, int pre, int l){
    
    tot = sz[root];
    
    if(tot == 1){
        dep[root] = l;
        par[root] = pre;
        return;
    }
    
    int cent = findcent(root, -1);
    
    dep[cent] = l;
    vis[cent] = 1;
    par[cent] = pre;
    
    for(auto u: adj[cent]){
        if(!vis[u.first]){
            dis[l][u.first] = u.second;
            dfs(u.first, cent, l);
            go(u.first, cent, l+1);
        }
    }
}

void Init(int n, int a[], int b[], int d[]){
    memset(best, 0x3f, sizeof best);
    N = n;
    for(int i = 0; i < N-1; i++){
        adj[a[i]].push_back({b[i], d[i]});
        adj[b[i]].push_back({a[i], d[i]});
    }
    for(int i = 0; i < N; i++){
        if(adj[i].size() == 1){
            getsz(i, -1);
            go(i, -1, 0);
            break;
        }
    }
}

ll Query(int S, int x[], int T, int y[]){
    ll ans = inf;
    for(int i = 0; i < S; i++){
        int n = x[i];
        while(~n){
            if(best[n] == inf)
                path[t++] = n;
            best[n] = min(best[n], dis[dep[n]][x[i]]);
            n = par[n];
        }
    }
    
    for(int i = 0; i < T; i++){
        ll ret = inf;
        int n = y[i];
        while(~n){
            ret = min(ret, best[n] + dis[dep[n]][y[i]]);
            n = par[n];
        }
        ans = min(ans, ret);
    }
    
    for(int i = 0; i < t; i++)
        best[path[i]] = inf;
    t = 0;
    
    return ans;
}