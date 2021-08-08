#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int n, m;
vector<int> adj[MM], to[MM];
int par[MM], in[MM], out[MM], t;
int bad[MM];
bool vis[MM];
int indeg[MM], b4[MM];

void dfs(int cur, int pre){
	par[cur] = pre;
	in[cur] = ++t;
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
	out[cur] = t;
}

void go(int cur){
	if(bad[cur])
		return;
	bad[cur] = 1;
	for(int u: adj[cur])
		if(u != par[cur])
			go(u);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
		indeg[a]++;
		indeg[b]++;
	}
	for(int i = 0,a,b; i < m; i++){
		cin>>a>>b;
		to[a].emplace_back(b);
		b4[b]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(indeg[i] == 1 and !b4[i]){
			vis[i] = 1;
			q.emplace(i);
		}
	}
	int cnt = 0, last = 0;
	while(size(q)){
		int cur = q.front(); q.pop();
		cnt++;
		last = cur;
		for(int u: adj[cur]){
			indeg[u]--;
			if(!vis[u] and indeg[u] <= 1 and !b4[u]){
				vis[u] = 1;
				q.emplace(u);
			}
		}
		for(int u: to[cur]){
			b4[u]--;
			if(!vis[u] and indeg[u] <= 1 and !b4[u]){
				vis[u] = 1;
				q.emplace(u);
			}
		}
	}

	dfs(last, 0);

	int no = cnt < n;
	
	if(!no)
	for(int a = 1; a <= n; a++){
		for(int b: to[a]){
			if(in[a] <= in[b] and in[b] <= out[a]){
				no = 1;
				abort();
			}
			go(a);
		}
	}

	for(int i = 1; i <= n; i++){
		cout<<(!no and !bad[i])<<'\n';
	}
}

/*
can not split component in two, because then impossible
so can only take leaves

first try to get any answer
set last node as root

if there exists answers, then for every [a, b] requirment, it is guaranteed that b is NOT in a's subtree
so just always mark a's subtree as bad

*/