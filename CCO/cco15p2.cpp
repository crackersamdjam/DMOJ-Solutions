#include <bits/stdc++.h>
#define MM 20
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int N,M,dis[MM][1<<MM],ans;
vector<pii> adj[MM];
queue<pii> q;
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0,a,b,c; i < M; i++){
        scanf("%d%d%d",&a,&b,&c);
        adj[a].push_back({b,c});
    }
    q.push({0,1});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto &e: adj[cur.f]){
            if(!(cur.s & (1<<e.f))){
                if(dis[cur.f][cur.s] + e.s > dis[e.f][cur.s | (1<<e.f)]){
                    dis[e.f][cur.s | (1<<e.f)] = dis[cur.f][cur.s] + e.s;
                    q.push({e.f, cur.s | (1<<e.f)});
                }
            }
        }
    }
    for(int i = 0; i <= (1<<N); i++){
        ans = max(ans, dis[N-1][i]);
    }
    printf("%d\n", ans);
#ifdef def
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= (1<<N); j++){
            printf("%d ", dis[i][j]);
        }
        printf("\n");
    }
#endif
    return 0;
}