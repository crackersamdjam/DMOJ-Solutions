#include <bits/stdc++.h>
using namespace std;
#define MM 200005
#define f first
#define s second
vector<pair<int,int>> adj[MM];
int dis[MM], dp1[MM], dp2[MM];
bool vis[MM];
int tot = 0;
int main() {
    int n, t;
    scanf("%d%d",&n,&t);
    for(int i = 1,a,b,c; i < n; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        tot += c;
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0; vis[1] = true;
    int maxl = 0, end = -1;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto e: adj[cur]){
            if(!vis[e.f]){
                vis[e.f] = true;
                q.push(e.f);
                dis[e.f] = dis[cur]+e.s;
                if(dis[e.f] > maxl){
                    maxl = dis[e.f];
                    end = e.f;
                }
            }
        }
    }
    memset(vis, false, sizeof(vis));
    q.push(end);
    dp1[end] = 0; vis[end] = true;
    maxl = 0, end = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto e: adj[cur]){
            if(!vis[e.f]){
                vis[e.f] = true;
                q.push(e.f);
                dp1[e.f] = dp1[cur]+e.s;
                if(dp1[e.f] > maxl){
                    maxl = dp1[e.f];
                    end = e.f;
                }
            }
        }
    }
    memset(vis, false, sizeof(vis));
    q.push(end);
    dp2[end] = 0; vis[end] = true;
    maxl = 0, end = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto e: adj[cur]){
            if(!vis[e.f]){
                vis[e.f] = true;
                q.push(e.f);
                dp2[e.f] = dp2[cur]+e.s;
                if(dp2[e.f] > maxl){
                    maxl = dp2[e.f];
                    end = e.f;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(adj[i].size()==t){
            printf("%d %d\n", i, tot*2 - max(dp1[i],dp2[i]));
        }
    }
    return 0;
}