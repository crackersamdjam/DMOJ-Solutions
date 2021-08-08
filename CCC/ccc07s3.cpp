#include <bits/stdc++.h>
using namespace std;
#define MM 10002
vector<int> adj[MM];
int vis[MM], dis[MM],a=1,b=1,n;
bool cycle;
void dfs(int cur){
    if(cycle) return;
    vis[cur] = 1;
    for(int u : adj[cur]){
        if(vis[u] == 2) continue;
        if(vis[u]==1 && u == a && vis[b]==1){
            cycle = true;
            return;
        }else if(!vis[u]){
            dfs(u);
        }
    }
    vis[cur] = 2;
    return;
}
int main() {
    scanf("%d",&n);
    for(int i = 0,x,y; i < n; i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
    }
    while(a!=0 || b!=0){
        scanf("%d%d",&a,&b);
        if(a == 0 && b == 0) break;
        cycle = false;
        memset(vis, 0, sizeof(vis));
        dfs(a);
        if(cycle){
            int ans = -1;
            memset(vis, 0, sizeof(vis));
            queue<int> q;
            q.push(a);
            vis[a] = 1;
            dis[a] = 0;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                if(cur == b){
                    ans = dis[b]-1;
                    break;
                }
                for(int u: adj[cur]){
                    if(!vis[u]){
                        vis[u] = 1;
                        dis[u] = dis[cur]+1;
                        q.push(u);
                    }
                }
            }
            printf("Yes %d\n", ans);
        }else printf("No\n");
    }
    return 0;
}