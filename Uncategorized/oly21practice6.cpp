#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int MM = 2e5+5;

int n, m;
ll C, sum, ans;
vector<pair<int, int>> adj[MM];
ll dis[MM];
bool vis[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>C;
	for(int i = 0,a,b,c; i < m; i++){
		cin>>a>>b>>c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
		sum += c;
	}
	ans = sum;
	memset(dis, 0x3f, sizeof dis);
	q.emplace(dis[1] = 0, 1);
	while(size(q)){
		auto [curd, cur] = q.top(); q.pop();
		if(curd > dis[cur])
			continue;

		//remove edges
		for(auto [u, w]: adj[cur]){
			if(vis[u]){
				sum -= w;
			}
		}

		vis[cur] = 1;
		ll v = C*curd+sum;
		ans = min(ans, v);

		for(auto [u, w]: adj[cur]){
			if(curd+w < dis[u]){
				q.emplace(dis[u] = curd+w, u);
			}
		}
	}
	cout<<ans<<'\n';
}