#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MM = 5005;
const ll mod = 1e9+7;

ll dp[MM], cnt[MM], ans[MM];
int n, m, dis[MM];
struct st{
    int u, w, id;
};
vector<st> adj[MM];

ll go(int cur){
    if(~dp[cur])
        return dp[cur];
    dp[cur] = 1; //to itself
    for(auto e: adj[cur]){
        if(dis[cur] + e.w == dis[e.u]){
            dp[cur] += go(e.u);
            dp[cur] %= mod;
            
            ans[e.id] += cnt[cur]*go(e.u);
            ans[e.id] %= mod;
        }
    }
    
    return dp[cur];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0,a,b,c; i < m; i++){
        cin>>a>>b>>c;
        adj[a].push_back({b, c, i});
    }
    for(int st = 1; st <= n; st++){
        for(int i = 1; i <= n; i++){
            dp[i] = -1;
            dis[i] = INT_MAX/2;
            cnt[i] = 0;
        }
        dis[st] = 0;
        cnt[st] = 1;
        
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.emplace(0, st);
        while(q.size()){
            int cur = q.top().second, curd = q.top().first; q.pop();
            if(curd > dis[cur])
                continue;
            for(auto e: adj[cur]){
                if(curd + e.w < dis[e.u]){
                    cnt[e.u] = cnt[cur];
                    dis[e.u] = curd+e.w;
                    q.emplace(dis[e.u], e.u);
                }
                else if(curd + e.w == dis[e.u]){
                    cnt[e.u] += cnt[cur];
                    cnt[e.u] %= mod;
                }
            }
        }
        
        go(st);
    }
    
    for(int i = 0; i < m; i++)
        cout<<ans[i]<<'\n';
}