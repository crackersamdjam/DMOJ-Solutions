#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using pii = pair<int, int>;
const int MM = 5005;

int n, m, qs;
vector<int> adj[MM], adj2[MM];
int dfn[MM], low[MM], id[MM], t, sz[MM];
stack<int> stk;
bool ins[MM];

void dfs(int cur, int pre){
	dfn[cur] = low[cur] = ++t;
	ins[cur] = 1;
	stk.push(cur);

	for(int u: adj[cur]){
		if(u == pre)
			continue;
	
		if(!dfn[u]){
			dfs(u, cur);
			low[cur] = min(low[cur], low[u]);
		}
		else if(ins[u])
			low[cur] = min(low[cur], dfn[u]);
	}
	if(low[cur] == dfn[cur]){
		int u;
		while(1){
			u = stk.top(); stk.pop();
			ins[u] = 0;
			id[u] = cur;
			sz[cur]++;
			if(u == cur)
				break;
		}
	}
}

int dis[MM][MM];
priority_queue<pii> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>qs;
	for(int i = 0,a,b; i < m; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i]){
			dfs(i, 0);
		}
	}
	swap(adj, adj2);
	for(int i = 1; i <= n; i++){
		for(int j: adj2[i]){
			if(id[i] != id[j]){
				adj[id[i]].emplace_back(id[j]);
			}
		}
	}

	memset(dis, -1, sizeof dis);

	for(int st = 1; st <= n; st++){
		q.emplace(dis[st][st] = -sz[st], st);
		while(size(q)){
			auto [curd, cur] = q.top(); q.pop();
			for(int u: adj[cur]){
				if(curd+sz[cur] > dis[st][u]){
					q.emplace(dis[st][u] = curd+sz[cur], u);
				}
			}
		}
	}
	while(qs--){
		int a, b; cin>>a>>b;
		int aa = id[a], bb = id[b];
		if(aa == bb){
			cout<<"Indeterminate\n";
			continue;
		}
		if(~dis[aa][bb]){
			cout<<a<<' '<<dis[aa][bb]<<'\n';
			continue;
		}
		if(~dis[bb][aa]){
			cout<<b<<' '<<dis[bb][aa]<<'\n';
			continue;
		}
		cout<<"Indeterminate\n";
	}
}