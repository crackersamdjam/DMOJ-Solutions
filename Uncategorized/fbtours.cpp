#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+5;
const ll mod = 1e9+7;

ll ans;
int tc, n, m, q, last[MM];
vector<int> adj[MM], adj2[MM];
int path[MM], ptr, dfn[MM], low[MM], tt, id[MM];

void dfs(int cur, int pre){
	
	path[++ptr] = cur;
	dfn[cur] = low[cur] = ++tt;

	for(int u: adj[cur]){
		if(u == pre)
			continue;
		
		if(!dfn[u]){
			dfs(u, cur);
			low[cur] = min(low[cur], low[u]);
		}
		else
			low[cur] = min(low[cur], dfn[u]);
	}

	if(dfn[cur] == low[cur]){
		int u = 0;
		while(u != cur){
			u = path[ptr--];
			id[u] = cur;
		}
	}
}

int in[MM], out[MM], head[MM], dep[MM], par[MM], heavy[MM];
bool vis2[MM];

int dfs2(int cur, int pre){
	vis2[cur] = 1;
	int size = 1, maxsz = 0;
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		par[u] = cur, dep[u] = dep[cur]+1;
		int szu = dfs2(u, cur);
		size += szu;
		if(szu > maxsz)
			maxsz = szu, heavy[cur] = u;
	}
	return size;
}

void hld(int cur, int hd){
	head[cur] = hd;
	in[cur] = ++ptr;

	if(heavy[cur])
		hld(heavy[cur], hd);
	for(int u: adj[cur]){
		if(u != par[cur] && u != heavy[cur])
			hld(u, u);
	}
	out[cur] = ptr;
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

int dsu[MM];

int find(int x){
	while(x != dsu[x])
		x = dsu[x], dsu[x] = dsu[dsu[x]];
	return x;
}

int bit[MM];

void up(int i, int v){
	for(; i and i < MM; i += i&-i)
		bit[i] += v;
}

int qu(int i){
	int v = 0;
	for(; i; i -= i&-i)
		v += bit[i];
	return v;
}

int main(){
	scan(tc);
	while(tc--){
		scan(n, m, q);
		for(int i = 0,a,b; i < m; i++){
			scan(a, b);
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		for(int i = 1; i <= n; i++){
			if(!dfn[i])
				dfs(i, 0);
		}

		for(int i = 1; i <= n; i++){
			for(int j: adj[i])
				if(id[i] != id[j])
					adj2[id[i]].emplace_back(id[j]);
			
			dsu[i] = i;
		}

		for(int i = 1; i <= n; i++){
			adj2[i].erase(unique(adj2[i].begin(), adj2[i].end()), adj2[i].end());
			for(int j: adj2[i]){
				dsu[find(j)] = find(i);
			}
		}
		swap(adj, adj2);

		tt = 0;
		ptr = 0;
		for(int i = 1; i <= n; i++){
			if(!vis2[i]){
				dfs2(i, 0);
				hld(i, i);
			}
		}

		while(q--){
			int a, b, c;
			if(gc == 'T'){
				scan(a, b, c);
				a = id[a], b = id[b];
				if(find(a) != find(b))
					continue;

				up(in[a], c);
				up(in[b], c);
				up(in[getlca(a, b)], -c);
				up(in[par[getlca(a, b)]], -c);
			}
			else{
				scan(a);
				int i = id[a];
				int v = qu(out[i]) - qu(in[i]-1);

				ans += v-last[a];
				if(ans >= mod)
					ans -= mod;
				last[a] = v;
			}
		}

		print(ans);
		ans = 0;
		tt = 0;
		ptr = 0;
		for(int i = 0; i <= n; i++){
			adj[i].clear();
			adj2[i].clear();
		}
		for(int i = 0; i <= n; i++){
			dfn[i] = low[i] = 0;
			id[i] = 0;
			last[i] = 0;
			dep[i] = 0;
			vis2[i] = 0;

			dsu[i] = 0;
			in[i] = out[i] = 0;
			head[i] = dep[i] = par[i] = heavy[i] = 0;
		}
		memset(bit, 0, sizeof bit);
	}
}
/*
compress BCCS (biconnected - not block cut, all into one new node)
int last[MM]; stores the last value
each time when query, print delta since last time
HLD or ETT updates

path update and point query
also graph may not be connected
*/