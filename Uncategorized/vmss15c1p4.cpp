#include <bits/stdc++.h>
#define MM 100002
#define f first
#define s second
typedef std::pair<int,int> pii;
std::vector<pii> adj[MM];
int dis[MM],T,N,M,G,g,a,b,l,cnt=0;
std::vector<int> fb;
int main(){
    scanf("%d%d%d%d",&T,&N,&M,&G);
    while(G--){
        scanf("%d",&g);
        fb.push_back(g);
    }
    while(M--){
        scanf("%d%d%d",&a,&b,&l);
        adj[a].push_back({b,l});
    }
    std::priority_queue<pii,std::vector<pii>,std::greater<pii>> q;
    memset(dis,0x3f,sizeof(dis));
    q.push({0,0}); dis[0] = 0;
    while(!q.empty()){
        int cur = q.top().s; q.pop();
        for(auto e: adj[cur]){
            if(dis[cur] + e.s < dis[e.f]){
                dis[e.f] = dis[cur] + e.s;
                q.push({dis[e.f],e.f});
            }
        }
    }
    for(int i: fb){
        if(dis[i] <= T)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}