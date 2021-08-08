// 2N segtree

#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ll = long long;
using Data = std::pair<ll, int>;
using Lazy = ll;
const int MM = 1e5+1, LOG = 17;

int n, rpos[LOG][MM], rid;
ll p[MM], c[MM];
ll bld[LOG][MM];

struct segtree{
#define nm ((nl+nr)/2)
#define lc (rt+1)
#define rc (rt+(nm-nl+1)*2)
// #define lc (rt<<1)
// #define rc (rt<<1|1)
	Data t[MM*2]; Lazy lp[MM*2];
	const Data def = {LLONG_MAX/2, 0};
	const Lazy ldef = 0;

	inline void apply(const Lazy &v, int rt){
		t[rt].first += v;
		lp[rt] += v;
	}
	inline void push(int nl, int nr, int rt){
		if(nl == nr || lp[rt] == ldef) return;
		apply(lp[rt], lc); apply(lp[rt], rc); lp[rt] = ldef;
	}
	void build(int nl = 0, int nr = n, int rt = 0){
		lp[rt] = ldef;
		if(nl == nr){
			int u = rpos[rid][nl];
			t[rt] = {bld[rid][u]-p[u], u};
			return;
		}
		build(nl, nm, lc); build(nm+1, nr, rc); t[rt] = min(t[lc], t[rc]);
	}
	void update(int l, int r, const Lazy &v, int nl = 0, int nr = n, int rt = 0){
		if(r < nl || l > nr)
			return;
		if(l <= nl and nr <= r){
			apply(v, rt);
			return;
		}
		push(nl, nr, rt);
		update(l, r, v, nl, nm, lc); update(l, r, v, nm+1, nr, rc); t[rt] = min(t[lc], t[rc]);
	}
	Data query(int l, int r, int nl = 0, int nr = n, int rt = 0){
		// if(l > r) return def;
		if(r < nl || nr < l)
			return def;
		if(l <= nl && nr <= r)
			return t[rt];
		push(nl, nr, rt);
		return min(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST[LOG];

std::vector<std::pair<int, int>> adj[MM];
int q, sz[MM], centpar[MM];
int dep[LOG][MM], tot, in[LOG][MM], out[LOG][MM], tt[LOG];
int vis[MM], rt[LOG][MM];
int a[MM], b[MM];
std::map<std::pair<int, int>, int> mp;

#define u e.first

int getsz(int cur, int pre){
	sz[cur] = 1;
	for(auto e: adj[cur])
		if(u != pre && !~vis[u])
			sz[cur] += getsz(u, cur);
	return sz[cur];
}

int findcent(int cur, int pre){
	for(auto e: adj[cur])
		if(!~vis[u] && u != pre && sz[u]*2 > tot)
			return findcent(u, cur);
	return cur;
}

void dfs(int cur, int pre, int l, int cent){
	dep[l][cur] = dep[l][pre]+1;
	in[l][cur] = ++tt[l];
	rpos[l][tt[l]] = cur; //
	rt[l][cur] = cent;

	sz[cur] = 1; //calc now so not needed next time

	for(auto e: adj[cur]){
		if(!~vis[u] and u != pre){
			bld[l][u] = bld[l][cur] + c[e.second];
			dfs(u, cur, l, cent);
			sz[cur] += sz[u];
		}
	}
	out[l][cur] = tt[l];
}

void go(int root, int pre, int l){
	// https://dmoj.ca/src/1467260  save one dfs
	// tot = getsz(root, -1);
	tot = sz[root];
	if(tot == 1){
		centpar[root] = pre;
		vis[root] = l;
		return;
	}
	int cent = findcent(root, -1);
	vis[cent] = l;
	centpar[cent] = pre;
	dfs(cent, 0, l, cent);
	
	for(auto e: adj[cent]){
		if(!~vis[u])
			go(u, cent, l+1);
	}
}

#undef u

int main(){
	memset(vis, -1, sizeof vis);
	scan(n, q);
	for(int i = 1; i <= n; i++)
		scan(p[i]);
	for(int i = 0; i < n-1; i++){
		scan(a[i], b[i], c[i]);
		adj[a[i]].emplace_back(b[i], i);
		adj[b[i]].emplace_back(a[i], i);
		// mp[{a[i], b[i]}] = mp[{b[i], a[i]}] = i;
		if(a[i] > b[i])
			std::swap(a[i], b[i]);
		mp[{a[i], b[i]}]  = i;
	}

	getsz(n, 0);
	go(n, 0, 0);
	for(int j = 0; j < LOG; j++){
		rid = j;
		ST[j].build();
	}

	int u = 1;
	int op, i, ia, ib; ll w;

	while(q--){
		scan(op);
		if(op == 1){
			scan(i, w);
			const ll dif = p[i]-w;
			for(int j = 0; j < LOG and in[j][i]; j++)
				ST[j].update(in[j][i], in[j][i], dif);
			p[i] = w;
		}
		else{
			scan(ia, ib, w);
			if(ia > ib)
				std::swap(ia, ib);
			i = mp[{ia, ib}];
			const ll dif = w-c[i];
			const int mx = std::min(LOG-1, std::min(vis[a[i]], vis[b[i]]));
			for(int j = 0; j <= mx; j++){
				if(dep[j][a[i]] > dep[j][b[i]])
					std::swap(a[i], b[i]);
				ST[j].update(in[j][b[i]], out[j][b[i]], dif);
			}
			c[i] = w;
		}

		int cent = u;
		int j = vis[u];
		std::pair<ll, int> ans = ST[j].query(in[j][u]+1, out[j][u]);

		for(j--; j >= 0; j--){
			cent = centpar[cent];
			ll add = ST[j].query(in[j][u], in[j][u]).first+p[u];

			auto best = min(ST[j].query(in[j][cent], in[j][u]-1),
				ST[j].query(out[j][u]+1, out[j][cent]));
			best.first += add;
			ans = min(ans, best);
		}
		u = ans.second;
		printn(u), pc(32);
	}
}