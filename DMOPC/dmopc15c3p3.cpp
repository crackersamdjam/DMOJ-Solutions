#include <bits/stdc++.h>
//change to <bits/stdc++.h> for submission on dmoj
using namespace std;
vector<int> adj[21];
int vis[21];
int dis[21];
bool contains = false;

void dfs(int cur, int pre){
    if(contains) return;
    vis[cur] = 1;
    for(int i: adj[cur]){
        if(vis[i] == 0){
            dis[i] = dis[cur]+1;
            dfs(i, cur);
        }else if(vis[i]==1 && dis[cur]-dis[i]+1==6){
            contains = true;
            return;
        }
    }
    vis[cur] = 2;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0, a, b; i < m; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i < 21; i++){
        if(vis[i] == 0){
            dfs(i, 0);
            if(contains) break;
        }
    }
    printf(contains ? "YES" : "NO");
    return 0;
}