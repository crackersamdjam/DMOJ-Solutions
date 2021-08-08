#include <bits/stdc++.h>
using namespace std;
typedef pair<double,int> rpi;
#define MM 1002
#define f first
#define s second
vector<pair<int,double>> adj[MM];
pair<double,int> dis[MM];
int main() {
    int V,E; scanf("%d%d",&V,&E);
    for(int i = 0,m,n,d,s; i < E; i++){
        scanf("%d%d%d%d",&m,&n,&d,&s);
        adj[m].push_back({n,60.0*d/s});
        adj[n].push_back({m,60.0*d/s});
    }
    for(int i = 0; i < MM; i++)
        dis[i] = {999999.9,0};
    //memset(dis,0x3f,sizeof(dis));
    priority_queue<rpi,vector<rpi>,greater<rpi>> q;
    q.push({0,1}); //dis, node
    dis[1] = {0,0};
    while(!q.empty()){
        int cur = q.top().s; q.pop();
        //printf("%d\n",cur);
        for(auto e: adj[cur]){
            //printf("%f %f %f\n",dis[cur].f,e.s,dis[e.f].f);
            if(dis[cur].f + e.s < dis[e.f].f){
                dis[e.f].f = dis[cur].f + e.s;
                dis[e.f].s = dis[cur].s + 1;
                q.push({dis[e.f].f,e.f});
            }else if(dis[cur].f + e.s == dis[e.f].f && dis[cur].s + 1 < dis[e.f].s){
                dis[e.f].s = dis[cur].s + 1;
                q.push({dis[e.f].f,e.f});
            }
        }
    }
    printf("%d\n%d\n",dis[V].s,(int)round(dis[V].f*4/3 - dis[V].f));
    return 0;
}