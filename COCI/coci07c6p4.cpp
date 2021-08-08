#include <bits/stdc++.h>
#define MM 1002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
struct edge{
    int b,c,st,ed;
};
vector<edge> adj[MM];
int dis[MM],N,M,A,B,K,G,g,a,b,l,t,st,ed,temp,temp2,dist,cur;
queue<int> path;
priority_queue<pii, vector<pii>, greater<pii>> q;
int main(){
    scanf("%d%d%d%d%d%d",&N,&M,&A,&B,&K,&G);
    while(G--){
        scanf("%d",&g);
        path.push(g);
    }
    while(M--){
        scanf("%d%d%d",&a,&b,&l);
        adj[a].push_back({b,l,-1,-1});
        adj[b].push_back({a,l,-1,-1});
    }
    t = 0;
    while(path.size() > 1){
        st = path.front(); path.pop();
        ed = path.front();
        for(auto &e: adj[st]){
            if(e.b == ed){
                temp = e.st = t;
                t += e.c;
                temp2 = e.ed = t;
                break;
            }
        }
        for(auto &e: adj[ed]){
            if(e.b == st){
                e.st = temp;
                e.ed = temp2;
                break;
            }
        }
    }
    memset(dis,0x3f,sizeof(dis));
    dis[A] = K;
    q.push({K, A});
    while(!q.empty()){
        dist = q.top().f, cur = q.top().s; q.pop();
        for(const auto &e: adj[cur]){
            if(dis[cur]+ e.c < dis[e.b]){
                if(e.st == -1 || dist < e.st || dist > e.ed){
                    dis[e.b] = dis[cur] + e.c;
                    q.push({dis[e.b], e.b});
                }else if(e.ed + e.c < dis[e.b]){
                    dis[e.b] = e.ed + e.c;
                    q.push({dis[e.b], e.b});
                }
            }
        }
    }
    printf("%d\n", dis[B] - dis[A]);
    return 0;
}