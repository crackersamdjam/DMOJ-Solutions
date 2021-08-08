#include <bits/stdc++.h>
using namespace std;
static bool rab[200001];
static bool vis[200001];
static vector<int> adj[200001];
static unsigned long long dis[200001];
static int x, y;
static vector<int> path;
int dfs(int cur){
    vis[cur] = true;
    if(rab[cur]) dis[cur] = 0;
    for(int i: adj[cur]){
        if(!vis[i]){
            if(dfs(i) + 1 < dis[cur])
                dis[cur] = dfs(i) + 1;
        }else{
            if(dis[i]+1 < dis[cur])
                dis[cur] = dis[i] + 1;
        }
    }
    return dis[cur];
}
static bool re;
void dfs2(int cur){
    vis[cur] = true;
    //printf("path add %d\n", cur);
    path.push_back(cur);
    if(cur == y){
        re = true;
        return;
    }
    if(rab[cur]) dis[cur] = 0;
    for(int i: adj[cur]){
        if(!vis[i]){
            dfs2(i);
        }
        if(re) return;
    }
    //printf("path remove %d\n", cur);
    path.erase(remove(path.begin(), path.end(), cur), path.end());
}

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    for(int i = 1, a, b; i < n; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0, ar; i < r; i++){
        scanf("%d", &ar);
        rab[ar] = true;
    }
    scanf("%d%d", &x, &y);
    memset(dis, n+2, sizeof(dis));
    int z = dfs(x);
    /*for(int i = 1; i <= n; i++){
        printf("%d\n", dis[i]);
    }*/
    memset(vis, false, sizeof(vis));
    dfs2(x);
    unsigned long long d = ULLONG_MAX;
    for(int i: path){
        if(dis[i] < d)
            d = dis[i];
        //printf("%d\n", i);
    }
    printf("%lu\n", d);
    return 0;
}