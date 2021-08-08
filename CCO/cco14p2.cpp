#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5+1;

int N, M, A, B, Q, dis[MM], disr[MM];
pii ans[MM];
queue<int> q;
bool inq[MM];
struct edge{
    int a,b,c,d;
};
vector<edge> adj[MM], adjr[MM], edges;

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> A >> B;
    
    for(int i = 0,a,b,c,d; i < M; i++){
        cin >> a >> b >> d >> c;
        adj[a].push_back({a, b, c, d});
        adjr[b].push_back({b, a, c, d});
        edges.push_back({a, b, c, d});
    }
    
    memset(dis, 0x3f, sizeof dis);
    memset(disr, 0x3f, sizeof disr);
    
    dis[A] = 0;
    q.push(A);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        inq[cur] = 0;
        for(auto &e: adj[cur]){
            if(dis[cur] + e.d < dis[e.b]){
                dis[e.b] = dis[cur] + e.d;
                if(!inq[e.b]){
                    inq[e.b] = 1;
                    q.push(e.b);
                }
            }
        }
    }
    
    disr[B] = 0;
    q.push(B);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        inq[cur] = 0;
        for(auto &e: adjr[cur]){
            if(disr[cur] + e.d < disr[e.b]){
                disr[e.b] = disr[cur] + e.d;
                if(!inq[e.b]){
                    inq[e.b] = 1;
                    q.push(e.b);
                }
            }
        }
    }
    
    for(int i = 1; i <= M; i++){
        edge &e = edges[i-1];
        ans[i].first = e.d + dis[e.a] + disr[e.b];
        ans[i].second = e.c;
    }
    
    sort(ans+1, ans+M+1);
    
    for(int i = 1; i <= M; i++)
        ans[i].second += ans[i-1].second;
    
    cin >> Q;
    
    for(int i = 0,q; i < Q; i++){
        cin >> q;
        printf("%d\n", (upper_bound(ans, ans+M+1, pii(q,1e9))-1)->second);
    }
    
    return 0;
}