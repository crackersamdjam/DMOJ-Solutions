#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 3005;

int n, m;
vector<array<int, 2>> e;
vector<int> adj[MM];
array<int, 4> ans = {9999}, tmp;

void go(int a, int b){
	if(size(adj[a]) > size(adj[b]))
		swap(a, b);
	auto l = adj[b].begin();
	for(int i: adj[a]){
		auto j = lower_bound(l, adj[b].end(), i);
		if(j == adj[b].end())
			break;
		if(*j == i){
			cout<<"3\n"<<min(a, b)<<' '<<max(a, b)<<' '<<i<<'\n';
			exit(0);
		}
		l = j;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0,a,b; i < m; i++){
		cin>>a>>b;
		if(a != b)
			e.push_back({a, b});
	}
	for(auto &ee: e)
		sort(all(ee));
	sort(all(e));
	e.erase(unique(e.begin(), e.end()), e.end());
	for(auto [a, b]: e){
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	for(int i = 1; i <= n; i++){
		sort(all(adj[i]));
		if(size(adj[i]) == size(e)){
			cout<<"-1\n";
			exit(0);
		}
	}
	
	// O(m sqrt m) triangle finding comes from p1 in https://dmoj.ca/contest/rte3
	for(auto [a, b]: e)
		go(a, b);
	
	// O(m) find 4 nodes
	//either two separate edges
	//or switch adj[rt][0] to adj[rt][1] and try again
	auto [rt, sec] = e[0];
	int c = size(adj[rt]) > 1 ? adj[rt][1] : 0;
	for(int i = 1; i < size(e); i++){
		if(e[i][0] == rt)
			continue;
		if(e[i][0] == sec or e[i][1] == sec){
			if(c and c != e[i][0] and c != e[i][1]){
				tmp = {rt, c, e[i][0], e[i][1]};
				sort(all(tmp));
				ans = min(ans, tmp);
			}
		}
		else{
			tmp = {rt, sec, e[i][0], e[i][1]};
			sort(all(tmp));
			ans = min(ans, tmp);
		}
	}

	cout<<"4\n";
	for(auto i: ans)
		cout<<i<<' ';
}