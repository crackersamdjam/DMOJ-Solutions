#include <bits/stdc++.h>
using namespace std;
#define MM 2003
#define f first
#define s second
vector<pair<int,int>> adj[MM];
int dp[MM];
int main() {
    int n,m,b,q;
    scanf("%d%d%d%d",&n,&m,&b,&q);
    for(int i = 0, x,y,z; i < m; i++){
        scanf("%d%d%d", &x,&y,&z);
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    priority_queue<int,vector<int>,less<int>> qu;
    fill(dp, dp+n+1, INT_MAX);
    //for(int i = 0; i < n; i++) printf("%d\n", dp[i]);
    qu.push(b);
    dp[b] = 0;
    while(!qu.empty()){
        int cur = qu.top(); qu.pop();
        for(auto e: adj[cur]){
            if(dp[cur]+e.s < dp[e.f]){
                dp[e.f] = dp[cur]+e.s;
                qu.push(e.f);
            }
        }
    }
    for(int i = 0, a; i < q; i++){
        scanf("%d",&a);
        printf("%d\n", dp[a]==INT_MAX? -1: dp[a]);
    }
    return 0;
}