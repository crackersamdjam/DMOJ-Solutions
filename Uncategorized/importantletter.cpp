//this is wleung_bvg's code
//from his submission on utsoj
#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

template <const int MAXV, class unit> struct TarjanSCC {
    int id[MAXV], low[MAXV], pre; bool vis[MAXV]; vector<pair<int, unit>> adj[MAXV], DAG[MAXV]; vector<vector<int>> components; stack<int> s;
    void addEdge(int v, int w, unit weight) { adj[v].emplace_back(w, weight); }
    void dfs(int v) {
        vis[v] = true; int mn = low[v] = pre++; s.push(v);
        for (auto &&e : adj[v]) {
            if (!vis[e.first]) dfs(e.first);
            if (low[e.first] < mn) mn = low[e.first];
        }
        if (mn < low[v]) { low[v] = mn; return; }
        int w; components.emplace_back();
        do {
            w = s.top(); s.pop();
            id[w] = components.size() - 1; components.back().push_back(w); low[w] = INT_MAX;
        } while (w != v);
    }
    void clear(int V = MAXV) { components.clear(); for (int i = 0; i < V; i++) { adj[i].clear(); DAG[i].clear(); } }
    void run(int V) {
        fill(vis, vis + V, false); pre = 0;
        for (int v = 0; v < V; v++) if (!vis[v]) dfs(v);
    }
    void genDAG(int V) {
        for (int v = 0; v < V; v++) for (auto &&e : adj[v]) if (id[v] != id[e.first]) DAG[id[v]].emplace_back(id[e.first], e.second);
    }
};

template <const int MAXV, class unit> struct DijkstraSSSP {
    unit INF, dist[MAXV]; pair<int, unit> to[MAXV]; vector<pair<int, unit>> adj[MAXV]; DijkstraSSSP(unit INF) : INF(INF) {}
    void addEdge(int v, int w, unit weight) { adj[v].emplace_back(w, weight); }
    void addBiEdge(int v, int w, unit weight) { addEdge(v, w, weight); addEdge(w, v, weight); }
    void clear(int V = MAXV) { for (int i = 0; i < V; i++) adj[i].clear(); }
    void run(int V, const vector<int> &src) {
        priority_queue<pair<unit, int>, vector<pair<unit, int>>, greater<pair<unit, int>>> PQ;
        fill(dist, dist + V, INF); fill(to, to + V, make_pair(-1, 0));
        for (int s : src) PQ.emplace(dist[s] = 0, s);
        while (!PQ.empty()) {
            unit d = PQ.top().first; int v = PQ.top().second; PQ.pop();
            if (d > dist[v]) continue;
            for (auto &&e : adj[v]) if (dist[e.first] > dist[v] + e.second) {
                to[e.first] = make_pair(v, e.second); PQ.emplace(dist[e.first] = dist[v] + e.second, e.first);
            }
        }
    }
    void run(int V, int s) { run(V, vector<int>(1, s)); }
};

const int MAXN = 1e4 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, M, A, B;
TarjanSCC<MAXN, ll> SCC;
DijkstraSSSP<MAXN, ll> SP(INF);

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // freopen("err.txt", "w", stderr);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> A >> B;
    --A; --B;
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        SCC.addEdge(--a, --b, c);
    }
    SCC.run(N);
    SCC.genDAG(N);
    for (int i = 0; i < sz(SCC.components); i++) for (auto &&e : SCC.DAG[i]) SP.addEdge(i, e.first, e.second);
    SP.run(sz(SCC.components), SCC.id[A]);
    if (SP.dist[SCC.id[B]] == INF) cout << "No Friends" << nl;
    else cout << SP.dist[SCC.id[B]] << nl;
    return 0;
}