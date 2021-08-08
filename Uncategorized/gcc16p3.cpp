#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e5+5;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

struct node{
	ll val, lp;
	void apply(ll a){
		val += a;
		lp += a;
	}
} tree[MM*4];

void pull(int rt){
	tree[rt].val = max(tree[lc].val, tree[rc].val);
}

void push(int rt){
	tree[lc].apply(tree[rt].lp);
	tree[rc].apply(tree[rt].lp);
	tree[rt].lp = 0;
}

void update(int l, int r, ll v, int nl, int nr, int rt){
	if(r < nl or nr < l)
		return;
	if(l <= nl and nr <= r){
		tree[rt].apply(v);
		return;
	}
	push(rt);
	update(l, r, v, nl, nm, lc);
	update(l, r, v, nm+1, nr, rc);
	pull(rt);
}

ll query(int l, int r, int nl, int nr, int rt){
	if(r < nl or nr < l)
		return 0;
	if(l <= nl and nr <= r)
		return tree[rt].val;
	push(rt);
	return max(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
}

int n, q, h[MM], v[MM], d[MM], pre[MM];
vector<int> adj[MM];
stack<int> stk;
int in[MM], out[MM], t;
vector<array<int, 3>> ord;
ll ans[MM];

void dfs(int cur){
	in[cur] = ++t;
	for(int u: adj[cur])
		dfs(u);
	out[cur] = t;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>h[i]>>v[i]>>d[i];
		while(size(stk) and h[stk.top()] <= h[i]){
			stk.pop();
		}
		if(size(stk)){
			adj[stk.top()].emplace_back(i);
			pre[i] = stk.top();
		}
		stk.emplace(i);
		ord.push_back({d[i], 0, i});
	}
	for(int i = 1; i <= n; i++){
		if(!in[i]){
			dfs(i);
		}
	}
	for(int i = 1,b,m; i <= q; i++){
		cin>>b>>m;
		ord.push_back({m, i, b});
	}
	sort(all(ord));
	for(auto [_, id, u]: ord){
		if(!id){
			update(in[u], out[u], v[u], 1, n, 1);
		}
		else{
			// assert(d[u] <= _);
			ans[id] = v[u] + query(in[u], out[u], 1, n, 1) - query(in[u], in[u], 1, n, 1);
		}
	}
	for(int i = 1; i <= q; i++)
		cout<<ans[i]<<'\n';
}
/*
dfn range updates and range queries, but subtract parent value of the node to query
*/