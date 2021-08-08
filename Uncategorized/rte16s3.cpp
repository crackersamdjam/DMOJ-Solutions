#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 6005, LOG = 15;

int n, q, sp[LOG][MM];
ll val[LOG][MM];
vector<pair<int, int>> adj[MM];
int dep[MM];

void dfs(int cur, int pre, int w){
	if(cur) dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	val[0][cur] = w;
	for(auto e: adj[cur]){
		int u = e.first;
		if(u != pre){
			dfs(u, cur, e.second);
		}
	}
}

ll query(int a, int b){
	ll ret = 0;
	if(dep[a] < dep[b])
		swap(a, b);
	for(int i = LOG-1; i >= 0; i--)
		if(dep[a]-(1<<i) >= dep[b]){
			ret += val[i][a];
			a = sp[i][a];
		}
	if(a == b)
		return ret;	
	for(int i = LOG-1; i >= 0; i--){
		if(sp[i][a] != sp[i][b]){
			ret += val[i][a];
			a = sp[i][a];
			ret += val[i][b];
			b = sp[i][b];
		}
	}
	ret += val[0][a];
	ret += val[0][b];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i = 0,a,b,c; i < n-1; i++){
		cin>>a>>b>>c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	memset(sp, -1, sizeof sp);
	dfs(0, -1, 0);

	for(int i = 1; i < LOG; i++){
		for(int j = 0; j < n; j++){
			int u = sp[i-1][j];
			if(~u){
				sp[i][j] = sp[i-1][u];
				val[i][j] = val[i-1][j] + val[i-1][u];
			}
		}
	}
	cin>>q;
	while(q--){
		int a, b;
		cin>>a>>b;
		cout<<query(a, b)<<'\n';
	}
}