#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n, a[MM], b[MM], c[MM], par[MM];
vector<int> adj[MM];
ll v[MM], ans;

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

void dfs(int cur, int pre, ll sum){
	sum += v[cur];
	ans = max(ans, sum);
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur, sum);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>v[i];
		par[i] = i;
	}
	for(int i = 0; i < n-1; i++){
		cin>>a[i]>>b[i]>>c[i];
		if(c[i] > 1){
			v[find(b[i])] += v[find(a[i])];
			par[find(a[i])] = find(b[i]);
		}
	}
	for(int i = 0; i < n-1; i++){
		if(c[i] == 1){
			adj[find(a[i])].emplace_back(find(b[i]));
			adj[find(b[i])].emplace_back(find(a[i]));
		}
	}
	dfs(find(1), 0, 0);
	cout<<ans<<'\n';
}