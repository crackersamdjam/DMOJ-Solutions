#include <bits/stdc++.h>
using namespace std;
#define MM 1000002
vector<int> adj[MM];
bool vis[MM];
int dis[MM];
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 0,x,y; i < m; i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s,t;
    scanf("%d%d",&s,&t);
    queue<int> q;
    q.push(s); vis[s] = true; dis[s] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int u: adj[cur]){
            if(!vis[u]){
                vis[u] = true;
                dis[u] = dis[cur]+1;
                q.push(u);
            }
        }
    }
    printf("%d\n",m-dis[t]);
    return 0;
}