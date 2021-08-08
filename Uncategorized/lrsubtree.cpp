#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define mp make_pair
using namespace std;
typedef long long ll;
constexpr int MM = 5e5+5;

int n, q, in[MM], out[MM], dep[MM], t;
ll dp[MM];
vector<pair<int, ll>> v[MM];
vector<int> adj[MM];

ll dfs(int cur, int pre){
    in[cur] = t++;
    dep[cur] = dep[pre]+1;
    for(int u: adj[cur])
        if(u != pre)
            dp[cur] += dfs(u, cur);
    
    out[cur] = t;
    v[dep[cur]].emplace_back(in[cur], dp[cur]);
    return dp[cur];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>dp[i];
    for(int i = 0,a,b; i < n-1; i++){
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int i = 0; i <= n; i++)
        v[i].emplace_back(-1, 0);
    dfs(1, 0);
    for(int i = 0; i <= n; i++){
        for(int j =  1; j < v[i].size(); j++)
            v[i][j].second += v[i][j-1].second;
        v[i].emplace_back(MM, v[i].back().second);
    }
    
    ll last = 0;
    while(q--){
        ll u, l, r;
        cin>>u>>l>>r;
        u ^= last, l ^= last, r ^= last;
        ll ans = 0;
        l += dep[u];
        r += dep[u]+1;
        if(l <= n){
            ans += (--upper_bound(all(v[l]), mp(out[u], -1LL)))->second;
            ans -= (--upper_bound(all(v[l]), mp(in[u], -1LL)))->second;
        }
        if(r <= n){
            ans -= (--upper_bound(all(v[r]), mp(out[u], -1LL)))->second;
            ans += (--upper_bound(all(v[r]), mp(in[u], -1LL)))->second;
        }
        
        last = ans = max(ans, 0LL);
        cout<<ans<<'\n';
    }
}