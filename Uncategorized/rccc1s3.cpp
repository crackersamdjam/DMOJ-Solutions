#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1005;

int n, m, a[MM], b[MM];
vector<int> adj[MM];
bool vis[MM];
bool vis2[MM];

set<int> vals;
set<int> nodes;

void dfs(int cur){
	vis[cur] = 1;
	nodes.insert(cur);
	vals.insert(a[cur]);
	for(int u: adj[cur])
		if(!vis[u])
			dfs(u);
}


vector<pair<int, int>> all;
vector<int> path;
bool done;

void go(int cur, int tar){
	vis2[cur] = 1;
	path.emplace_back(cur);
	if(cur == tar){
		done = 1;
		return;
	}
	for(auto u: adj[cur]){
		if(!vis2[u]){
			go(u, tar);
			if(done) return;
		}
	}
	path.pop_back();
}

int main(){
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		b[i] = a[i];
	}
	for(int i = 0,c,d; i < m; i++){
		cin>>c>>d;
		adj[c].emplace_back(d);
		adj[d].emplace_back(c);
	}
	for(int st = 1; st <= n; st++){
		if(!vis[st]){
			nodes.clear();
			vals.clear();
			dfs(st);
			for(auto v: vals){
				int j = -1;
				for(int jj: nodes){
					if(a[jj] == v){
						j = jj;
						break;
					}
				}
				int k = *nodes.begin();
				// cerr<<"vjk "<<v<<' '<<j<<' '<<k<<endl;
				assert(~j);
				nodes.erase(k);
				path.clear();
				done = 0;
				memset(vis2, 0, sizeof vis2);
				go(j, k);

				// cerr<<"path: ";
				// for(auto i: path)
					// cerr<<i<<' ';
				// cerr<<endl;

				//swap time
				for(int i = 1; i < size(path); i++){
					swap(a[path[i-1]], a[path[i]]);
					all.emplace_back(path[i-1], path[i]);
				}
				for(int i = (int)size(path)-2; i > 0; i--){
					swap(a[path[i-1]], a[path[i]]);
					all.emplace_back(path[i-1], path[i]);
				}

				// for(int i = 1; i <= n; i++)
					// cerr<<a[i]<<' ';
				// cerr<<endl;
				assert(a[k] == v);
			}
		}
	}
	assert(size(all) <= 1e6);
	cout<<size(all)<<'\n';
	for(int i = 1; i <= n; i++){
		cout<<a[i]<<' ';
	}
	cout<<'\n';
	for(auto [i, j]: all){
		cout<<i<<' '<<j<<'\n';
	}
}