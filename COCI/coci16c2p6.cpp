#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 405;

bool dp[MM][1<<20];
vector<int> adj[MM];
int dep[MM], par[MM];
vector<int> v;
int n, k;

void dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	par[cur] = pre;
	if(dep[cur] == k){
		v.emplace_back(cur);
		return;
	}
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
}

int getlca(int a, int b){
	while(a != b){
		if(dep[a] > dep[b])
			a = par[a];
		else
			b = par[b];
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;

	if(k*k+1 > n){
		cout<<"DA\n";
		return 0;
	}

	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	v.emplace_back(-1);
	dep[0] = -1;
	dfs(1, 0);
	memset(dp[0], 1, sizeof dp[0]);
	for(int i = 1; i < size(v); i++){
		int lca = v[i];
		for(int j = i; j > 0; j--){
			lca = getlca(v[i], v[j]);
			for(int l = lca; l > 1; l = par[l]){
				int b = 1<<dep[l]-1;
				for(int m = 0; m < (1<<k); m++){
					if(m&b)
						dp[i][m] |= dp[j-1][m^b];
				}
			}
		}
	}
	if(dp[size(v)-1][(1<<k)-1])
		cout<<"DA\n";
	else
		cout<<"NE\n";
}