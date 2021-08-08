#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const ll mod = 998244353;
const int MM = 5e5+5;

int tc, n, m;
vector<int> adj[MM];
int dfn[MM], low[MM], t, id[MM];
stack<int> stk;
int psa[MM];
ll ans;

void dfs(int cur, int pre){
	dfn[cur] = low[cur] = ++t;
	stk.push(cur);
	
	for(auto u: adj[cur]){
		if(u == pre) continue;
		if(!dfn[u]){
			dfs(u, cur);
			low[cur] = min(low[cur], low[u]);
			psa[cur] += psa[u];
		}
		else{
			low[cur] = min(low[cur], dfn[u]);
			if(dfn[u] < dfn[cur])
				psa[cur]++;
			else
				psa[cur]--;
		}
	}
	
	if(dfn[cur] == low[cur]){
		int u = -1;
		while(u != cur){
			u = stk.top(); stk.pop();
			id[u] = cur;
		}
	}

	if(psa[cur] > 1)
		ans = 0;
}

ll ways[MM];
ll dp[MM][2];
// dp[node][whether a child goes up past this one]

void go(int cur, int pre){
	dp[cur][0] = 1;

	int tt = 0;
	for(int i = 0; i < size(adj[cur]); i++){
		int u = adj[cur][i];
		if(u == pre or id[u] == id[cur])
			continue;
		tt++;
		go(u, cur);
		dp[cur][0] = dp[cur][0]*(dp[u][0]+dp[u][1])%mod;
	}
	if(tt) dp[cur][1] = dp[cur][0]*ways[tt-1]%mod*tt%mod;
	// choose a child to go up

	dp[cur][0] = dp[cur][0]*ways[tt]%mod;
}

/*
both dp[u][0]+dp[u][1] because
dp[u][0] could be to sibling or none
dp[u][1] could be to sibling or to cur
so for all cases of ways[tt] (whether u is matched or not),
the count is correct
*/

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ways[0] = ways[1] = 1;
	for(int i = 2; i < MM; i++){
		ways[i] = (ways[i-1] + ways[i-2]*(i-1))%mod;
		// ways to make pairs from i items
	}
	
	cin>>tc;
	while(tc--){
		ans = 1;
		cin>>n>>m;
		for(int i = 0,a,b; i < m; i++){
			cin>>a>>b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		dfs(1, -1);

		if(ans)
			for(int i = 1; i <= n; i++){
				if(!dp[i][0]){
					go(i, 0);
					ans = (ans*dp[i][0])%mod;
				}
			}

		cout<<ans<<'\n';

		t = 0;
		for(int i = 1; i <= n; i++){
			adj[i].clear();
			dp[i][0] = dp[i][1] = 0;
			psa[i] = low[i] = dfn[i] = id[i] = 0;
		}
	}
}
/*
2
5 4
1 2
2 3
2 4
1 5
7 7
1 2
2 3
2 4
1 5
1 6
6 7
7 1

*/