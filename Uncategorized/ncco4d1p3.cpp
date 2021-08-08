#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MM = 5e3+2;
vector<pii> adj[MM];
int N,M;
ll dis[MM], dis2[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main() {
  scanf("%d%d",&N,&M);
  for(int i = 0,a,b,c; i < M; i++){
      scanf("%d%d%d",&a,&b,&c);
      adj[a].push_back({b,c});
      adj[b].push_back({a,c});
  }
  memset(dis, 0x3f, sizeof(dis));
  memset(dis2, 0x3f, sizeof(dis2));
  q.push({0,1});
  dis[1] = 0;
  while(!q.empty()){
    int cur = q.top().s; q.pop();
    for(const auto &e: adj[cur]){
      if(dis[cur] + e.s < dis[e.f]){
        dis2[e.f] = dis[e.f];
        dis[e.f] = dis[cur] + e.s;
        q.push({dis[e.f], e.f});
      }else if(dis[cur] + e.s < dis2[e.f] && dis[cur] + e.s > dis[e.f]){
        dis2[e.f] = dis[cur] + e.s;
          q.push({dis2[e.f], e.f});
      }else if(dis2[cur] + e.s < dis2[e.f] && dis2[cur] + e.s > dis[e.f]){
        dis2[e.f] = dis2[cur] + e.s;
        q.push({dis2[e.f], e.f});
      }
    }
  }
  printf("%lld\n", dis2[N]);
}