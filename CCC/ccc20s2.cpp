// S2 solution in O(NM)
#include <bits/stdc++.h>
using namespace std;
constexpr int MM = 1e6+5;

int n, m;
bool vis[MM];
vector<int> adj[MM];

void go(int u){
	if(u == n){
		cout<<"yes\n";
		exit(0);
	}
	vis[u] = 1;
	for(int i: adj[u])
		if(!vis[i])
			go(i);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1,k; i <= n; i++){
		k = i;
		for(int j = 1,v; j <= m; j++, k += i){
			cin>>v;
			adj[k].emplace_back(v);
		}
	}
	n *= m;
	go(1);
	cout<<"no\n";
}