#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
constexpr int MM = 50005;

int n, m, k, val[MM], dfn[MM], low[MM], t, id[MM], path[MM], ptr, in[MM];
vector<int> adj[MM];
bool ins[MM];
queue<int> q;
int nid;
vector<int> adj2[MM];
int take[MM];

bitset<MM> vis[MM];

bitset<MM> go(int cur){
	if(vis[cur][cur]) return vis[cur];
	vis[cur][cur] = 1;
	for(int u: adj2[cur]){
		vis[cur] |= go(u);
	}
	return vis[cur];
}

void dfs(int cur){
	ins[cur] = 1;
	path[++ptr] = cur;
	dfn[cur] = low[cur] = ++t;
	
	for(int u: adj[cur]){
		if(!dfn[u]){
			dfs(u);
			low[cur] = min(low[cur], low[u]);
		}
		else if(ins[u])
			low[cur] = min(low[cur], dfn[u]);
	}
	if(dfn[cur] == low[cur]){
		int u = -1;
		nid++;
		while(u ^ cur){
			u = path[ptr--];
			ins[u] = 0;
			id[u] = nid;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;    
	for(int i = 0,a; i < k; i++){
		cin>>a;
		a--;
		val[a<<1] = 1;
	}
	
	string str;
	for(int i = 0,a,b; i < m; i++){
		cin>>str>>a>>b;
		a--, b--;
		a <<= 1, b <<= 1;
		if(str == "FRIENDS"){
			// a nxor b
			adj[a].push_back(b);
			adj[b].push_back(a);
			adj[a|1].push_back(b|1);
			adj[b|1].push_back(a|1);
		}
		else if(str == "ENEMIES"){
			// a nand b
			adj[a].push_back(b|1);
			adj[b].push_back(a|1);
		}
		else if(str == "PARTNERS"){
			// a xor b
			adj[a|1].push_back(b);
			adj[b|1].push_back(a);
			adj[a].push_back(b|1);
			adj[b].push_back(a|1);
		}
		else if(str == "GROUP"){
			// a or b
			adj[a|1].push_back(b);
			adj[b|1].push_back(a);
		}
	}
	
	for(int i = 0; i < n*2; i++){
		if(!dfn[i])
			dfs(i);
	}

	for(int i = 0; i < n*2; i += 2){
		if(id[i] == id[i|1]){
			cout<<"NO\n";
			return 0;
		}
	}
	
	for(int i = 0; i < n*2; i++){
		for(int j: adj[i]){
			if(id[i] != id[j]){
				adj2[id[i]].emplace_back(id[j]);
			}
		}
	}

	for(int i = 0; i < n*2; i += 2){
		int a = id[i], b = id[i|1];
		if(go(a)[b]){
			take[b] = 1;
			q.push(b);
		}
		else if(go(b)[a]){
			take[a] = 1;
			q.push(a);
		}
	}

	for(int i = 0; i < 2*n; i++){
		if(val[i]){
			take[id[i]] = 1;
			q.push(id[i]);
		}
	}
	
	while(size(q)){
		int cur = q.front(); q.pop();

		for(int u: adj2[cur]){
			if(!take[u]){
				take[u] = 1;
				q.push(u);
			}
		}
	}

	cout<<"YES\n";
	
	for(int i = 0; i < n*2; i += 2){
		if(take[id[i]])
			cout<<1;
		else if(take[id[i|1]])
			cout<<0;
		else
			cout<<'?';
	}
	cout<<'\n';
}