#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 2e5+5, LOG = 20;

int n, k, ans = INT_MAX;
vector<int> adj[MM];
int c[MM], sz[MM];
vector<int> in[MM];
bool vis[MM];
int id[MM];
int par[MM];

set<int> ins[LOG][MM];
//pls

int getsz(int cur, int pre){
	sz[cur] = 1;
	for(int u: adj[cur]){
		if(u != pre and !vis[u])
			sz[cur] += getsz(u, cur);
	}
	return sz[cur];
}

int getcent(int cur, int pre, int tot){
	for(int u: adj[cur]){
		if(u != pre and !vis[u] and sz[u]*2 > tot)
			return getcent(u, cur, tot);
	}
	return cur;
}

void dfs(int cur, int pre, int cent, int lvl){
	par[cur] = pre;
	id[cur] = cent;

	ins[lvl][c[cur]].insert(cent);

	for(int u: adj[cur]){
		if(u != pre and !vis[u])
			dfs(u, cur, cent, lvl);
	}
}

void go(int rt, int lvl){
	int tot = getsz(rt, 0);
	int cent = getcent(rt, 0, tot);
	
	vis[cent] = 1;
	dfs(cent, 0, cent, lvl);

	int ok = 1;
	queue<int> q;
	q.push(cent);

	set<int> st, nodes;

	while(size(q)){
		int cur = q.front(); q.pop();
		if(nodes.count(cur)) continue;
		nodes.insert(cur);
		if(id[cur] != id[cent]){
			ok = 0;
			break;
		}
		if(!st.count(c[cur])){
			if(ins[lvl][c[cur]].size() > 1){
				ok = 0;
				break;
			}
			st.insert(c[cur]);
			for(int u: in[c[cur]]){
				q.push(u);
			}
		}

		int u = par[cur];
		if(u) q.push(u);
	}

	if(ok){
		ans = min(ans, (int)size(st)-1);
	}

	for(int u: adj[cent]){
		if(!vis[u]){
			go(u, lvl+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>k;
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(int i = 1; i <= n; i++){
		cin>>c[i];
		in[c[i]].emplace_back(i);
	}

	go(1, 0);
	cout<<ans<<'\n';
}