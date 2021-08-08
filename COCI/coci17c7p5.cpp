#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 505;

int n, m, v[MM];
int dp[MM][MM][2];
vector<int> adj[MM];

void dfs(int cur, int pre){
	for(int i = m; i > 0; i--){
		for(int t = 0; t < 2; t++)
			dp[cur][i][t] = max(dp[cur][i][t], dp[cur][i-1][t]+v[cur]);
	}
	for(int u: adj[cur]){
		if(u == pre) continue;
		dfs(u, cur);
		for(int i = m; i >= 0; i--){
			for(int j = 0; j <= m; j++){
				if(i-j-2 >= 0)
					dp[cur][i][0] = max(dp[cur][i][0], dp[cur][j][0] + dp[u][i-j-2][0]);
				if(i-j-2 >= 0)
					dp[cur][i][1] = max(dp[cur][i][1], dp[cur][j][1] + dp[u][i-j-2][0]);
				if(i-j-1 >= 0)
					dp[cur][i][1] = max(dp[cur][i][1], dp[cur][j][0] + dp[u][i-j-1][1]);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>v[i];
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1, 0);
	cout<<dp[1][m][1]<<'\n';
}