#include <bits/stdc++.h>
#define MM 502
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
vector<pii> adj[MM];
int dis[MM],cnt[MM],T,N,M,W,a,b,t;
bool inq[MM],br;
queue<int> q;
int main(){
    scanf("%d",&T);
    for(int tc = 0; tc < T; tc++){
        for(int i = 0; i < MM; i++)
            adj[i].clear();
        while(!q.empty())
            q.pop();
        scanf("%d%d%d",&N,&M,&W);
        while(M--){
            scanf("%d%d%d",&a,&b,&t);
            adj[a].push_back({b,t});
            adj[b].push_back({a,t});
        }
        while(W--){
            scanf("%d%d%d",&a,&b,&t);
            adj[a].push_back({b,-t});
        }
        br = 0;
        memset(cnt,0,sizeof(cnt));
        memset(inq,0,sizeof(inq));
        memset(dis,0x3f,sizeof(dis));
        q.push(1); dis[1] = 0; inq[1] = 1; cnt[1] = 1;
        while(!q.empty()){
            int cur = q.front(); q.pop(); inq[cur] = 0;
            for(const auto &e: adj[cur]){
                if(dis[cur] + e.s < dis[e.f]){
                    dis[e.f] = dis[cur] + e.s;
                    if(!inq[e.f]){
                        q.push(e.f);
                        inq[e.f] = 1;
                        cnt[e.f]++;
                        if(cnt[e.f] > N){
                            br = 1;
                            break;
                        }
                    }
                }
            }
            if(br) break;
        }
        printf(br? "YES\n": "NO\n");
    }
    return 0;
}