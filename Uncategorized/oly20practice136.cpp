#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = double;
const int MM = 1e5+5;
const ll inf = 1e17;

/*
find y2
(y2-y1)/(x2-x1) = m
(y2-y1) = m*(x2-x1)
y2 = y1+m*(x2-x1)
*/

struct pt{
	ll x, y;
	ll f(ll m, ll x2){
		return y+m*(x2-x);
	}
};

ld slope(pt a, pt b){
	return ld(b.y-a.y)/ld(b.x-a.x);
}

struct cht{
	deque<pt> q;

	pt nl(ll m, ll add, ll x2){
		if(q.empty())
			return {x2, inf};
		//find where new line intersects
		int l = 0, r = (int)size(q)-2;
		while(l <= r){
			int i = l+r>>1;
			if(q[i].f(m, x2) <= q[i+1].f(m, x2))
				r = i-1;
			else
				l = i+1;
		}
		if(l+1 < size(q) and q[l+1].f(m, x2) < q[l].f(m, x2))
			l++;
		return {x2, q[l].f(m, x2) + add};
	}
	void add(pt p){
		while(size(q) >= 2 and slope(q.end()[-2], p) >= slope(q.end()[-1], p))
			q.pop_back();
		q.emplace_back(p);
	}
} t[MM];

int n;
vector<pair<int, int>> adj[MM];
ll p[MM], s[MM], ans[MM];
int par[MM], dep[MM], heavy[MM], head[MM], ptr;
ll dis[MM];

int dfs(int cur, int pre){
	int size = 1, maxsz = 0;
	for(auto [u, w]: adj[cur]){
		if(u == pre)
			continue;
		par[u] = cur, dep[u] = dep[cur]+1, dis[u] = dis[cur] + w;
		int szu = dfs(u, cur);
		size += szu;
		if(szu > maxsz)
			maxsz = szu, heavy[cur] = u;
	}
	return size;
}

pt query(int hd, ll m, ll add, ll x2){
	pt res = {x2, inf};
	while(hd){
		auto l = t[hd].nl(m, add, x2);
		res.y = min(res.y, l.y);
		hd = head[par[head[hd]]];
	}
	return res;
}

void hld(int cur, int hd){
	head[cur] = hd;
	if(cur > 1){
		auto l = query(hd, s[cur], p[cur], dis[cur]);
		ans[cur] = l.y;
		t[hd].add(l);
	}
	else t[hd].add({0, 0});

	for(auto [u, w]: adj[cur]){
		if(u != par[cur] && u != heavy[cur])
			hld(u, u);
	}
	if(heavy[cur])
		hld(heavy[cur], hd);
}

int main(){
	#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#endif
	cin>>n;
	for(int i = 0,a,b,c; i < n-1; i++){
		cin>>a>>b>>c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	for(int i = 2; i <= n; i++){
		cin>>p[i]>>s[i];
	}
	dfs(1, 0);
	hld(1, 1);
	for(int i = 2; i <= n; i++)
		cout<<ans[i]<<' ';
}
/*
in every path, I store a monoq of (x, y) points
the "hull", between them is monotonically increasing
when query with a line, I get the point on the hull that makes this new (x2, y2) coordinate the best

use hld to decompose
at node cur, query all previous heads (at most log n) to get best answer for current
insert new point
do light paths first, then do the heavy one (so that light ones don't query stuff that doesn't belong to them)

*/