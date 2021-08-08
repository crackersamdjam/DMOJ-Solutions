#include <bits/stdc++.h>
using namespace std;
#define MM 200001
#define f first
#define s second
typedef pair<pair<int,int>,int> edg;
vector<edg> edgs;
int par[MM];
vector<pair<int,int>> adj[MM];
bool vis[MM];
int val[MM];
bool cmp(edg x, edg y){
    return x.s > y.s;
}
int root(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    } return x;
}
void dfs(int cur, int pre){
    for(auto u: adj[cur]){
        if(!vis[u.f]/* || val[cur] + u.s < val[u.f]*/){
            vis[u.f] = true;
            val[u.f] = min(val[cur], u.s);
            dfs(u.f, cur);
        }
        //if(u.f == pre) continue;
        /*if(!dis[u.f] && u.f!=1){
            dis[u.f] = dis[cur] + u.s;
            val = min(val, u.s);
            dfs(u.f, cur, val);
        }*/
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1, a, b, p; i <= m; i++){
        scanf("%d%d%d", &a, &b, &p);
        edgs.push_back({{a, b}, p});
    }
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
    sort(edgs.begin(), edgs.end(), cmp);
    int E = 0;
    for(auto e: edgs){
        if(root(e.f.f) != root(e.f.s)){
            par[root(e.f.f)] = root(e.f.s);
            adj[e.f.f].push_back(make_pair(e.f.s, e.s));
            adj[e.f.s].push_back(make_pair(e.f.f, e.s));
            E++;
            if(E == n-1) break;
        }
    }
    /*for(int i = 1; i <= n; i++){
        for(auto j : adj[i]){
            printf("%d %d %d\n", i, j.f, j.s);
        }
    }*/
    vis[1] = true;
    val[1] = INT_MAX;
    dfs(1, 0);
    printf("%d\n", 0);
    for(int i = 2; i <= n; i++) printf("%d\n", val[i]);
    return 0;
}
/*
5 6
1 2 3
2 3 3
1 3 7
1 4 4
1 5 5
4 5 5
 */