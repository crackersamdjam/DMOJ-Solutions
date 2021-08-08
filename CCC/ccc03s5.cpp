// CCC '03 S5 Trucking Troubles
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define MM 100002
#define f first
#define s second
#define inf 0x3f3f3f3f
vector<pii> adj[MM];
priority_queue<pii,vector<pii>,less<pii>> q;
int dis[MM];
bool vis[MM];
vector<int> dests;
int main() {
    memset(dis,0,sizeof(dis));
    int V, E, D; scanf("%d%d%d",&V,&E,&D);
    for(int i = 0,a,b,c; i < E; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int d;
    while(D--){
        scanf("%d",&d);
        dests.push_back(d);
    }
    dis[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        int cur = q.top().second; q.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto e: adj[cur]){
            if(e.s > dis[e.f]){
                dis[e.f] = e.s;
                q.push({e.s, e.f});
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int u: dests){
        ans = min(ans, dis[u]);
    }
    printf("%d\n",ans);
    /*int sum = 0;
    for(int i = 1; i <= V; i++){
        printf("%d ",dis[i]);
        sum += dis[i];
    }
    printf("%d\n",sum);*/
    return 0;
}