#include <bits/stdc++.h>
using namespace std;
#define MM 500003
#define f first
#define s second
vector<pair<int,int>> adj[MM], adjr[MM];
vector<pair<pair<int,int>,int>> adjc;
int dpf[MM], dps[MM];
int main() {
    memset(dpf, 0x3f, sizeof(dpf));
    memset(dps, 0x3f, sizeof(dps));
    int n,m; scanf("%d%d",&n,&m);
    for(int i = 0,a,b,k; i < m; i++){
        scanf("%d%d%d",&a,&b,&k);
        adj[a].push_back({b,k});
        //adj[b].push_back({a,k});
        adjr[b].push_back({a,k});
    }
    int d; scanf("%d",&d);
    for(int i = 0,a,b,g; i < d; i++){
        scanf("%d%d%d",&a,&b,&g);
        adjc.push_back({{a,b},g});
    }
    priority_queue<int,vector<int>,greater<int>> q;
    q.push(1); dpf[1] = 0;
    while(!q.empty()){
        int cur = q.top(); q.pop();
        for(auto e: adj[cur]){
            if(dpf[cur]+e.s < dpf[e.f]){
                dpf[e.f] = dpf[cur]+e.s;
                q.push(e.f);
            }
        }
    }
    int dis = dpf[n];
    q.push(n); dps[n] = 0;
    while(!q.empty()){
        int cur = q.top(); q.pop();
        for(auto e: adjr[cur]){
            if(dps[cur]+e.s < dps[e.f]){
                dps[e.f] = dps[cur]+e.s;
                q.push(e.f);
            }
        }
    }
    for(auto e: adjc){
        dis = min(dis, dpf[e.f.f] + dps[e.f.s] + e.s);
        //dis = min(dis, dps[e.f.f] + dpf[e.f.s] + e.s);
    }
    printf("%d\n", dis == 0x3f3f3f3f? -1: dis);
    return 0;
}