#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

template <class _FlowUnit> struct FlowEdge {
	using FlowUnit = _FlowUnit; int to, rev; FlowUnit cap, resCap;
	FlowEdge(int to, int rev, FlowUnit cap)
			: to(to), rev(rev), cap(cap), resCap(cap) {}
};

template <class Edge> struct PushRelabelMaxFlow {
	using FlowUnit = typename Edge::FlowUnit;
	int V; FlowUnit FLOW_EPS; vector<vector<Edge>> G; vector<bool> cut;
	PushRelabelMaxFlow(int V, FlowUnit FLOW_EPS = FlowUnit(1e-9))
			: V(V), FLOW_EPS(FLOW_EPS), G(V) {}
	void addEdge(int v, int w, FlowUnit vwCap, FlowUnit wvCap = FlowUnit()) {
		if (v == w) return;
		G[v].emplace_back(w, int(G[w].size()), vwCap);
		G[w].emplace_back(v, int(G[v].size()) - 1, wvCap);
	}
	FlowUnit getFlow(int s, int t) {
		cut.assign(V, false); if (s == t) return FlowUnit();
		vector<FlowUnit> ex(V, FlowUnit()); vector<int> h(V, 0), cnt(V * 2, 0);
		vector<vector<int>> hs(V * 2);
		vector<typename vector<Edge>::iterator> cur(V);
		auto push = [&] (int v, Edge &e, FlowUnit df) {
			int w = e.to;
			if (abs(ex[w]) <= FLOW_EPS && df > FLOW_EPS) hs[h[w]].push_back(w);
			e.resCap -= df; G[w][e.rev].resCap += df; ex[v] -= df; ex[w] += df;
		};
		h[s] = V; ex[t] = FlowUnit(1); cnt[0] = V - 1;
		for (int v = 0; v < V; v++) cur[v] = G[v].begin();
		for (auto &&e : G[s]) push(s, e, e.resCap);
		if (!hs[0].empty()) for (int hi = 0; hi >= 0;) {
			int v = hs[hi].back(); hs[hi].pop_back(); while (ex[v] > FLOW_EPS) {
				if (cur[v] == G[v].end()) {
					h[v] = INT_MAX; for (auto e = G[v].begin(); e != G[v].end(); e++)
						if (e->resCap > FLOW_EPS && h[v] > h[e->to] + 1)
							h[v] = h[(cur[v] = e)->to] + 1;
					cnt[h[v]]++;
					if (--cnt[hi] == 0 && hi < V) for (int w = 0; w < V; w++)
						if (hi < h[w] && h[w] < V) { cnt[h[w]]--; h[w] = V + 1; }
					hi = h[v];
				} else if (cur[v]->resCap > FLOW_EPS && h[v] == h[cur[v]->to] + 1) {
					push(v, *cur[v], min(ex[v], cur[v]->resCap));
				} else cur[v]++;
			}
			while (hi >= 0 && hs[hi].empty()) hi--;
		}
		for (int v = 0; v < V; v++) cut[v] = h[v] >= V;
		return -ex[s];
	}
};

const int MM = 2005;
using ll = long long;
int n, m;

PushRelabelMaxFlow<FlowEdge<ll>> f(MM, 0);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	int s = n+m+1, t = s+1;
	ll sum = 0;
	for(int i = 1,v; i <= n; i++){
		cin>>v;
		f.addEdge(i, t, v);
	}
	for(int i = 1,a,b,c; i <= m; i++){
		cin>>a>>b>>c;
		f.addEdge(s, n+i, c);
		f.addEdge(n+i, a, 1e9);;
		f.addEdge(n+i, b, 1e9);;
		sum += c;
	}
	auto ans = f.getFlow(s, t);
	cout<<sum-ans<<'\n';
}