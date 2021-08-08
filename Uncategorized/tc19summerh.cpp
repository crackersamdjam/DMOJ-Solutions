#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
constexpr int MM = 2e5+5, LOG = 18;
constexpr ll inf = 1e17;

int q, n, m, tt;

// centroid stuff
vector<pair<int, ll>> adj[MM];
ll dis[LOG][MM];
bool vis[MM];
int sz[MM], centpar[MM], dep[MM];

map<int, ll> st[MM];
//(time, distance)

int getsz(int cur, int pre){
	sz[cur] = 1;
	for(auto [u, w]: adj[cur]){
		if(u != pre and !vis[u])
			sz[cur] += getsz(u, cur);
	}
	return sz[cur];
}

int findcent(int cur, int pre, int tot){
	for(auto [u, w]: adj[cur]){
		if(!vis[u] and u != pre and sz[u]*2 > tot)
			return findcent(u, cur, tot);
	}
	return cur;
}

void dfs(int cur, int pre, int l){
	for(auto [u, w]: adj[cur]){
		if(u == pre or vis[u])
			continue;
		dis[l][u] = dis[l][cur] + w;
		dfs(u, cur, l);
	}
}

void go(int root, int pre, int l){
	int tot = getsz(root, -1);
	if(tot == 1){
		dep[root] = l;
		vis[root] = 1;
		centpar[root] = pre;
		return;
	}
	
	int cent = findcent(root, -1, tot);
	dep[cent] = l;
	vis[cent] = 1;
	centpar[cent] = pre;
	dfs(cent, cent, l);
	
	for(auto [u, w]: adj[cent]){
		if(!vis[u]){
			go(u, cent, l+1);
		}
	}
}

ll query(int u, int t){
	ll ret = inf;
	for(int p = u; p; p = centpar[p]){
		auto it = st[p].upper_bound(t);
		if(it == st[p].begin()) continue;
		ll val = prev(it)->second + dis[dep[p]][u];
		ret = min(ret, val);
	}
	return ret;
}

void update(int u, int t, ll v){
	for(int p = u; p; p = centpar[p]){
		ll val = v + dis[dep[p]][u];
		if(val > inf)
			continue;
		
		if(st[p].count(t))
			st[p][t] = val = min(st[p][t], val);
		else
			st[p][t] = val;
		
		auto it = st[p].lower_bound(t);
		if(it != st[p].begin()){
			if(prev(it)->second <= val){
				st[p].erase(it);
				continue;
			}
		}
		while(next(it) != st[p].end() and val <= next(it)->second){
			st[p].erase(next(it));
		}
	}
}

array<int, 4> portals[MM];

int main(){
	#ifdef CLION
	freopen("../in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>q>>tt;
	for(int i = 0,a,b,c; i < n-1; i++){
		cin>>a>>b>>c;
		a++, b++;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	go(1, 0, 0);

	for(int i = 0; i < m; i++){
		int x, st, et, w;
		cin>>x>>st>>et>>w;
		x++;
		portals[i] = {st, et, x, w};
	}
	sort(portals, portals+m);
	update(1, tt, 0);

	for(int i = m-1; i >= 0; i--){
		auto [st, et, x, w] = portals[i];
		ll d = query(x, st);
		update(x, et, d+w);
	}

	while(q--){
		int t, a;
		cin>>t>>a;
		a++;
		ll ret = query(a, t);
		cout<<(ret < inf ? ret : -1)<<'\n';
	}
}