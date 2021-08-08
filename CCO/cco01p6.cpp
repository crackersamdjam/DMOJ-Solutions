#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 105;

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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	while(1){
		cin>>n>>m;
		if(!(n+m)) break;
		vector<bool> can(m+1), win(m+1);
		vector<set<int>> st(n+1, set<int>());

		for(int i = 1,k; i <= n; i++){
			cin>>k;
			while(k--){
				int a; cin>>a;
				st[i].insert(a);
			}
		}
		for(int i = 1; i <= m; i++){
			// see if i can win
			// do max flow from sources to n weight 1, m to sink weight k
			PushRelabelMaxFlow<FlowEdge<int>> f(205, 0);

			int cnt = 0;

			for(int j = 1; j <= n; j++){
				if(st[j].count(i)){
					cnt++;
				}
				else{
					f.addEdge(0, j, 1);
					for(int k: st[j]){
						f.addEdge(j, n+k, 1);
					}
				}
			}
			for(int j = 1; j <= m; j++){
				f.addEdge(n+j, n+m+1, cnt-1);
			}
			auto ret = f.getFlow(0, n+m+1);
			if(cnt and cnt+ret == n){
				can[i] = 1;
			}
		}

		if(accumulate(all(can), 0) == 1){
			int i = *max_element(all(can));
			int cnt = 0;
			vector<int> rest(m+1);
			for(int j = 1; j <= n; j++){
				if(size(st[j]) == 1 and st[j].count(i)){
					cnt++;
				}
				else{
					for(int k: st[j]){
						rest[k]++;
					}
				}
			}
			if(*max_element(all(rest)) < cnt)
				win[i] = 1;
		}

		for(int i = 1; i <= m; i++){
			if(win[i])
				cout<<"Candidate "<<i<<" will become president.\n";
			else if(can[i])
				cout<<"Candidate "<<i<<" may become president.\n";
			else
				cout<<"Candidate "<<i<<" will not become president.\n";
		}
	}
}