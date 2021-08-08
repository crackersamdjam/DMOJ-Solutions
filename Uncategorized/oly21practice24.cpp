#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 3e5+5;

int n, q, dis[MM], par[MM], pw[MM], dep[MM], head[MM], heavy[MM];
vector<pair<int, int>> adj[MM];
array<int, 4> v[MM];

int dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	par[cur] = pre;
	int sz = 1, mx = 0;
	for(auto [u, w]: adj[cur]){
		if(u == pre){
			pw[cur] = w;
			continue;
		}
		dis[u] = dis[cur]+w;
		int su = dfs(u, cur);
		sz += su;
		if(su > mx){
			mx = su;
			heavy[cur] = u;
		}
	}
	return ++sz;
}

void hld(int cur, int h){
	head[cur] = h;
	if(heavy[cur])
		hld(heavy[cur], h);
	for(auto [u, w]: adj[cur]){
		if(u != par[cur] and u != heavy[cur])
			hld(u, u);
	}
}

int getlca(int a, int b){
	while(head[a] != head[b]){
		if(dep[head[a]] < dep[head[b]])
			b = par[head[b]];
		else
			a = par[head[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

int dif[MM], k, mx;

int prop(int cur){
	for(auto [u, w]: adj[cur]){
		if(u != par[cur])
			dif[cur] += prop(u);
	}
	if(dif[cur] == k){
		mx = max(mx, pw[cur]);
	}
	return dif[cur];
}

bool go(int m){
	k = mx = 0;
	memset(dif, 0, sizeof dif);
	for(auto [a, b, lca, len] : v){
		if(len <= m)
			break;
		k++;
		dif[a]++;
		dif[b]++;
		dif[lca] -= 2;
	}
	prop(1);
	return v[0][3]-mx <= m;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>q;
	for(int i = 0,a,b,c; i < n-1; i++){
		cin>>a>>b>>c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	dfs(1, 0);
	hld(1, 1);
	for(int i = 0,a,b; i < q; i++){
		cin>>a>>b;
		int lca = getlca(a, b);
		int len = dis[a] + dis[b] - 2*dis[lca];
		v[i] = {a, b, lca, len};
	}
	sort(v, v+q, [](auto x, auto y){
		return x[3] > y[3];
	});

	int l = 0, m, r = 3e8;
	while(l <= r){
		m = l+r>>1;
		if(go(m))
			r = m-1;
		else
			l = m+1;
	}
	cout<<l<<'\n';
}