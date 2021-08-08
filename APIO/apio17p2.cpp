#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
constexpr int MM = 102, MN = 1002;
constexpr ll inf = LLONG_MAX/2;

int n, m, K;
ll adj[MM][MM], a[MM][MN], b[MM][MN]; // a buy, b sell
ll dis[MM][MM], dp[MM][MM];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>K;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= K; j++){
            cin>>a[i][j]>>b[i][j];
            assert(a[i][j] == -1 or a[i][j] >= b[i][j]);
        }
    }
    for(int i = 0,u,v; i < m; i++){
        ll c;
        cin>>u>>v>>c;
        if(!adj[u][v])
            adj[u][v] = c;
        else
            adj[u][v] = min(adj[u][v], c);
    }
    
    ll lo = 1, mid, hi = 1e9;
    while(lo <= hi){
        mid = (lo+hi)/2;
        
        //initialize distances
        
        memset(dis, 0x3f, sizeof dis);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][j])
                    dis[i][j] = adj[i][j]*mid;
                else
                    dis[i][j] = inf;
            }
        }
    
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        
        memset(dp, -0x3f, sizeof dp);
        //buy and sell dp
        for(int k = 1; k <= K; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dp[i][j] = max(dp[i][j], -dis[i][j]);
                    if(~b[j][k] and ~a[i][k])
                        dp[i][j] = max(dp[i][j], b[j][k] - a[i][k] - dis[i][j]);
                }
            }
        }
        
        //using dp distances, find if cycle with w <= 0
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        for(int i = 1; i <= n; i++){
            if(dp[i][i] >= 0){
                lo = mid+1;
                goto out;
            }
        }
        
        hi = mid-1;
        out:;
    }
    
    cout << hi << '\n';
    
    return 0;
}