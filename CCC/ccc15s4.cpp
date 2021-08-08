#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 2002, MN = 202;

int K, N, M, dis[MM][MN], A, B;
bool inq[MM];
struct edge{
    int d, t, h;
};
vector<edge> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    
    scanf("%d%d%d", &K, &N, &M);
    
    for(int i = 0,a,b,t,h; i < M; i++){
        scanf("%d%d%d%d", &a, &b, &t, &h);
        adj[a].push_back({b,t,h});
        adj[b].push_back({a,t,h});
    }
    
    scanf("%d%d", &A, &B);
    
    memset(dis, 0x3f, sizeof dis);
    
    dis[A][0] = 0;
    
    q.push({0, A});
    
    while(!q.empty()){
        
        int cur = q.top().second;
        q.pop();
        inq[cur] = 0;
        
        for(auto &e: adj[cur]){
            for(int k = e.h; k < K; k++){
                if(dis[cur][k-e.h] + e.t < dis[e.d][k]){
                    dis[e.d][k] = dis[cur][k-e.h] + e.t;
                    if(!inq[e.d]){
                        inq[e.d] = 1;
                        q.push({dis[e.d][k], e.d});
                    }
                }
            }
        }
    }
    
    int ans = *min_element(dis[B], dis[B]+K);
    
    if(ans == 0x3f3f3f3f)
        puts("-1");
    else
        printf("%d\n", ans);
    
    return 0;
}