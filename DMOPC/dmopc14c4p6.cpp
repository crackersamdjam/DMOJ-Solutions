#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 500002;
vector<int> adj[MAX];
bool vis[MAX];
int dis[MAX], dp1[MAX], dp2[MAX];
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1, a, b; i < n; i++){
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vis[1] = true;
    dis[1] = 0;
    int endint = 0, len = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(dis[cur] > len){
            len = dis[cur];
            endint = cur;
        }
        for(int i: adj[cur]){
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
                dis[i] = dis[cur] + 1;
            }
        }
    }
    q.push(endint);
    len = 0;
    //fill_n(vis, n+2, false);
    //fill_n(dis, n+2, 0);
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    vis[endint] = true;
    dis[endint] = 0;
    endint = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i: adj[cur]){
            if(dis[cur] > len){
                len = dis[cur];
                endint = cur;
            }
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
                dis[i] = dis[cur] + 1;
                dp1[i] = dis[cur] + 1;
            }
        }
    }

    q.push(endint);
    int len2 = 0;
    //fill_n(vis, n+2, false);
    //fill_n(dis, n+2, 0);
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    vis[endint] = true;
    dis[endint] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i: adj[cur]){
            if(dis[cur] > len2){
                len2 = dis[cur];
            }
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
                dis[i] = dis[cur] + 1;
                dp2[i] = dis[cur] + 1;
                //printf("%d a %d\n", dp2[i], i);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d\n", max(dp1[i], dp2[i]) +1);
    }
    return 0;
}