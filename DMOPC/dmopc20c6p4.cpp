#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 5e5+5;

int n, q, c[MM];
vector<int> adj[MM];
set<int> st[MM];

int bit[MM];

void up(int i, int x){
	for(i++; i < MM ; i += i&-i)
		bit[i] += x;
}

int qu(int i){
	int x = 0;
	for(i++; i; i -= i&-i)
		x += bit[i];
	return x;
}

int head[MM], par[MM], heavy[MM], dep[MM];

int getsz(int cur, int pre){
	int size = 1, maxsz = 0;
	for(int u : adj[cur]){
		if(u == pre)
			continue;
		par[u] = cur, dep[u] = dep[cur]+1;
		int szu = getsz(u, cur);
		size += szu;
		if(szu > maxsz)
			maxsz = szu, heavy[cur] = u;
	}
	return size;
}

void hld(int cur, int h){
	head[cur] = h;
	if(heavy[cur])
		hld(heavy[cur], h);
	for(int u: adj[cur]){
		if(u != par[cur] and u != heavy[cur])
			hld(u, u);
	}
}

int getlca(int a, int b){
	while(head[a] != head[b]){
		if(dep[head[a]] < dep[head[b]])
			b = par[head[b]];
		else
			a = par[head[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

int reg[MM], val[MM];
vector<int> in[MM];
int totcol;
int only[MM];
vector<pair<int, int>> qv[MM];
int ans[MM];


void dfs(int cur, int pre){
	st[cur].insert(c[cur]);
	for(int u: adj[cur]){
		if(u == pre) continue;
		dfs(u, cur);
		if(size(st[u]) > size(st[cur])){
			swap(st[u], st[cur]);
		}
		for(int i: st[u])
			st[cur].insert(i);
		st[u].clear();

		only[cur] += only[u];
	}
	reg[cur] = val[cur] = size(st[cur]);
}

void go(int cur, int pre){
	for(auto [k, i]: qv[cur]){
		ans[i] = n-qu(k-1);
	}

	for(int u: adj[cur]){
		if(u == pre) continue;
		up(val[cur], -1);
		up(val[u], -1);
		val[cur] -= only[u];
		val[u] += totcol-reg[u];
		up(val[cur], 1);
		up(val[u], 1);
		
		go(u, cur);

		up(val[cur], -1);
		up(val[u], -1);
		val[cur] += only[u];
		val[u] -= totcol-reg[u];
		up(val[cur], 1);
		up(val[u], 1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>c[i];
		in[c[i]].emplace_back(i);
	}
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	getsz(1, 0);
	hld(1, 0);

	for(int i = 1; i <= n; i++){
		if(size(in[i])){
			totcol++;
			int lca = in[i][0];
			for(int j: in[i])
				lca = getlca(lca, j);
			only[lca]++;
		}
	}

	dfs(1, 0);

	for(int i = 1; i <= n; i++){
		up(val[i], 1);
	}

	for(int i = 0; i < q; i++){
		int rt, k;
		cin>>rt>>k;
		qv[rt].emplace_back(k, i);
	}

	go(1, 0);

	for(int i = 0; i < q; i++){
		cout<<ans[i]<<'\n';
	}
}
/*
https://cdn.discordapp.com/attachments/848020085398175744/848248079119286313/unknown.png

precount subtree_cnt[u] and only_in_this_subtree[u]

r root
c child

move from r to c

r loses subtree of c
ans[r] -= only_in[c]

c gains "supertree" in direction of r
ans[c] += those not in c's subtree
        = total_colors - cnt[c]

*/