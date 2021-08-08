#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1005;

struct Matching{
	
	int n, k;
	vector<vector<int>> adj;
	vector<int> mt;
	vector<bool> used;
	
	void init(int nn){
		adj.resize(nn);
	}
	
	void addedge(int a, int b){
		// add edge from small side to large side
		adj[a].emplace_back(b);
	}
	
	bool dfs(int cur){
		if(used[cur])
			return 0;
		used[cur] = 1;
		for(int u: adj[cur]){
			if(mt[u] == -1 or dfs(mt[u])){
				mt[u] = cur;
				return 1;
			}
		}
		return 0;
	}
	
	vector<pair<int, int>> run(){
		vector<pair<int, int>> matching;
		mt.assign(k, -1);
		vector<bool> used1(n, 0);
		for(int cur = 0; cur < n; cur++){
			for(int u: adj[cur]){
				if(mt[u] == -1){
					mt[u] = cur;
					used1[cur] = 1;
					break;
				}
			}
		}
		for(int cur = 0; cur < n; cur++){
			if(used1[cur])
				continue;
			used.assign(n, false);
			dfs(cur);
		}
		
		for(int i = 0; i < k; i++){
			if(~mt[i]){
				matching.emplace_back(mt[i]+1, i+1);
			}
		}
		return matching;
	}
};

int n, m, x[MM], y[MM];

bool go(int k){
	Matching M;
	M.init(MM);
	M.n = M.k = MM;
	for(int i = 0; i < k; i++){
		M.addedge(i, x[i]);
		M.addedge(i, y[i]);
	}
	auto ret = M.run();
	return size(ret) == k;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		cin>>x[i]>>y[i];
	}
	int l = 1, r = m;
	while(l <= r){
		int mid = l+r>>1;
		if(go(mid))
			l = mid+1;
		else
			r = mid-1;
	}
	cout<<r<<'\n';
}