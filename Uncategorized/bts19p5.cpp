#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int n, q;
vector<int> adj[MM], v[MM];
int one[MM], bestdown[MM], bestup[MM], upone[MM], uptwo[MM];
int par[MM];

void dfs1(int cur, int pre){
	int f = 0, s = 0;
	par[cur] = pre;
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		dfs1(u, cur);
		if(one[u] > f)
			s = f, f = one[u];
		else if(one[u] > s)
			s = one[u];
		bestdown[cur] = max(bestdown[cur], bestdown[u]);
	}
	one[cur] = f+1;
	bestdown[cur] = max(bestdown[cur], f+s+1);
}

void dfs2(int cur, int pre){
	int f, s, o;
	o = 0;
	f = upone[cur], s = 0;
	for(int u: adj[cur]){
		if(u == pre)
			continue;

		if(f > upone[u]){
			uptwo[u] = upone[u], upone[u] = f;
			if(s > uptwo[u])
				uptwo[u] = s;
		}
		else if(f > uptwo[u])
			uptwo[u] = f;

		if(one[u] > f)
			s = f, f = one[u];
		else if(one[u] > s)
			s = one[u];

		bestup[u] = max(bestup[u], o);
		o = max(o, bestdown[u]);
	}

	reverse(all(adj[cur]));
	o = 0;
	f = 0, s = 0;
	for(int u: adj[cur]){
		if(u == pre)
			continue;

		if(f > upone[u]){
			uptwo[u] = upone[u], upone[u] = f;
			if(s > uptwo[u])
				uptwo[u] = s;
		}
		else if(f > uptwo[u])
			uptwo[u] = f;

		if(one[u] > f)
			s = f, f = one[u];
		else if(one[u] > s)
			s = one[u];

		bestup[u] = max(bestup[u], max(bestup[cur], upone[u]+uptwo[u]+1));
		upone[u]++;
		bestup[u] = max(bestup[u], o);
		o = max(o, bestdown[u]);
		dfs2(u, cur);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>q;
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for(int i = 1; i <= n; i++){
		for(int u: adj[i]){
			if(u == par[i])
				v[i].emplace_back(bestup[i]);
			else
				v[i].emplace_back(bestdown[u]);
		}
		sort(all(v[i]), greater<>());
	}

	while(q--){
		int a, i; cin>>a>>i;
		if(i > size(v[a]))
			cout<<"-1\n";
		else
			cout<<v[a][i-1]<<'\n';		
	}
}