#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 2e5+5;

int n, m, qs, v[MM], at[MM];
vector<int> adj[MM];
int dis[MM];
set<pair<int, int>> st;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>qs;
	for(int i = 0,a,b; i < m; i++){
		cin>>a>>b;
		adj[b].emplace_back(a);
	}
	for(int i = 0; i < n; i++){
		cin>>v[i];
		at[v[i]] = i;
	}
	memset(dis, 0x3f, sizeof dis);
	dis[n] = 0;
	queue<int> q({n});
	while(q.size()){
		int cur = q.front(); q.pop();
		for(int u: adj[cur]){
			if(dis[cur]+1 < dis[u]){
				dis[u] = dis[cur]+1;
				q.emplace(u);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		st.insert({dis[i]+at[i], i});
	}

	while(qs--){
		int i, j; cin>>i>>j;
		i--, j--;
		int a = v[i], b = v[j];
		st.erase({dis[a]+at[a], a});
		st.erase({dis[b]+at[b], b});
		swap(v[i], v[j]);
		swap(at[a], at[b]);
		st.insert({dis[a]+at[a], a});
		st.insert({dis[b]+at[b], b});
		cout<<st.begin()->first<<'\n';
	}
}