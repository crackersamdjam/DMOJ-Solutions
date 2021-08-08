#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 5e5+5;

int n, c[MM];
vector<int> adj[MM];
ll dp[MM];
//cost to make this subtree valid
ll sz[MM];

void dfs(int cur, int pre){
	sz[cur] = c[cur];
	vector<ll> v;
	for(int u: adj[cur]){
		if(u == pre) continue;
		dfs(u, cur);
		sz[cur] += sz[u];
		dp[cur] += sz[u];
		v.emplace_back(dp[u]-sz[u]);
		//those I can keep
	}
	sort(all(v));

	for(int i = 0; i < min(2 + (cur == 1), (int)size(v)); i++)
		dp[cur] += v[i];
	// pr(cur, pre, dp[cur], sz[cur]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 2; i <= n; i++)
		cin>>c[i];
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1, 0);
	cout<<dp[1]<<'\n';
}