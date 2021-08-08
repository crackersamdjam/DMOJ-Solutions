#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 105;

int n, m;
set<int> adj[MM];

bool vis[MM];
int mt[MM];

int dfs(int cur){
	if(vis[cur]) return 0;
	vis[cur] = 1;
	for(int u: adj[cur]){
		if(!mt[u] or dfs(mt[u])){
			mt[u] = cur;
			return 1;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	cin>>n>>m;
	for(int i = 1,k; i <= n; i++){
		cin>>k;
		while(k--){
			int a;
			cin>>a;
			if(i == 1){
				adj[i].insert(a);
			}
			else{
				if(adj[1].count(a)){
					adj[i].insert(a);
				}
			}
		}
	}

	for(int i = 2; i <= n; i++){
		memset(vis, 0, sizeof vis);
		dfs(i);
	}

	int ans = 0;
	for(int u: adj[1]){
		if(!mt[u]){
			ans++;
		}
	}
	cout<<ans<<'\n';
}