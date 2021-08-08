#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
typedef pair<int, int> T;
typedef int L;
const int MM = 1e5+5, LOG = 17;

struct node{
	T val;
	L lp;
	inline void apply(L v){
		val = {v, v};
		lp = v;
	}
};

int n, c[MM], ina[MM], inb[MM];
vector<int> adj[MM];
int par[MM], dep[MM], heavy[MM], head[MM], pos[MM], ptr, rpos[MM]; //reverse mapping
int bit[MM], sp[LOG][MM];
map<int, int> mp;
int X = 2;

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
	node tree[MM*4];
	const T DEF = {INT_MAX, INT_MIN};
	const L LDEF = 0;
	inline T merge(T va, T vb){ return {min(va.first, vb.first), max(va.second, vb.second)};}
	inline void pull(int rt){ tree[rt].val = merge(tree[lc].val, tree[rc].val);}
	
	// node with lazy val means yet to push to children (but updated itself)
	inline void push(int rt, int nl, int nr){
		L &val = tree[rt].lp;
		if(nl != nr and val){
			tree[lc].apply(val);
			tree[rc].apply(val);
		}
		val = LDEF;
	}
	
	void build(int l = 0, int r = MM-1, int rt = 1){
		int nl = l, nr = r;
		
		tree[rt].val = DEF;
		tree[rt].lp = LDEF;
		
		if(l == r)
			return;
		build(l, nm, lc);
		build(nm+1, r, rc);
		pull(rt);
	}
	
	void update(int l, int r, L val, int nl = 0, int nr = MM-1, int rt = 1){
		if(r < nl || l > nr)
			return;
		if(l <= nl && r >= nr){
			tree[rt].apply(val);
			return;
		}
		push(rt, nl, nr);
		update(l, r, val, nl, nm, lc);
		update(l, r, val, nm+1, nr, rc);
		pull(rt);
	}
	
	int query(int l, int r, int val, int nl = 0, int nr = MM-1, int rt = 1){
		if(r < nl)
			return -1; //too far right, it works
		if(nr < l)
			return l; //too far left
		
		if(tree[rt].val.first == val and tree[rt].val.second == val)
			return -1;

		if(nl == nr) //doesn't work
			return nl+1;

		push(rt, nl, nr);
		int res = query(l, r, val, nm+1, nr, rc);
		if(res == -1) return query(l, r, val, nl, nm, lc);
		return res;
		//if doesn't work on right, get it
	}

	int get(int l, int nl = 0, int nr = MM-1, int rt = 1){
		if(l < nl || l > nr)
			return 0;
		if(nl == nr)
			return tree[rt].val.first;
		push(rt, nl, nr);
		return get(l, nl, nm, lc) | get(l, nm+1, nr, rc);
	}
#undef lc
#undef rc
#undef nm
} ST;

inline int bitqu(int i){
	int ret = 0;
	for(; i; i -= i&-i)
		ret += bit[i];
	return ret;
}

inline void bitup(int i, int v){
	for(; i < X; i += i&-i)
		bit[i] += v;
}

int dfs(int cur, int pre){
	int size = 1, maxsz = 0;
	for(int u : adj[cur]){
		if(u == pre)
			continue;
		par[u] = cur, dep[u] = dep[cur]+1;
		sp[0][u] = cur;
		int szu = dfs(u, cur);
		size += szu;
		if(szu > maxsz)
			maxsz = szu, heavy[cur] = u;
	}
	return size;
}

void decompose(int cur, int id){
	head[cur] = id, pos[cur] = ++ptr;
	rpos[ptr] = cur; //reverse mapping
	if(~heavy[cur])
		decompose(heavy[cur], id);
	for(int u: adj[cur]){
		if (u != par[cur] && u != heavy[cur])
			decompose(u, u);
	}
}

inline void init(){
	memset(sp, -1, sizeof sp);
	memset(heavy, -1, sizeof heavy);
	ptr = 0;
	adj[0].push_back(1);
	// adj[1].push_back(0);
	dfs(0, -1);
	decompose(1, 1);
	ST.build();
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			int u = sp[i-1][j];
			if(~u) sp[i][j] = sp[i-1][u];
		}
	}
}

vector<pair<int, int>> undo;

inline ll query(int u){
	ll res = 0;
	while(u > 0){
		int last = u, tar = ST.get(pos[u]);

		u = ST.query(pos[head[u]], pos[u], tar);
		u = rpos[u];
		u = par[u]; //jump to diff one

		int cnt = dep[last]-(u == -1 ? -1 : dep[u]);
		res += (ll)cnt*bitqu(tar-1);

		bitup(tar, cnt);
		undo.emplace_back(tar, cnt);
	}
	for(auto i: undo)
		bitup(i.first, -i.second);
	undo.clear();

	return res;
}

inline void update(int b, L v){
	int a = 0;
	for(; head[a] != head[b]; b = par[head[b]]){
		// if(dep[head[a]] > dep[head[b]])
			// swap(a, b);
		int l = pos[head[b]], r = pos[b];
		ST.update(l, r, v);
	}
	if(a != b){
		// if(dep[a] > dep[b])
			// swap(a, b);
		ST.update(pos[a]+1, pos[b], v);
	}
}

int main(){
	scan(n);
	for(int i = 1; i <= n; i++){
		scan(c[i]);
		mp[c[i]] = 0;
	}
	for(auto &i: mp)
		i.second = X++;
	for(int i = 1; i <= n; i++)
		c[i] = mp[c[i]];

	for(int i = 1; i < n; i++){
		scan(ina[i], inb[i]);
		adj[ina[i]].emplace_back(inb[i]);
	}
	init();
	update(pos[1], c[1]);
	
	for(int i = 1; i < n; i++){
		print(query(ina[i]));
		update(inb[i], c[inb[i]]);
	}
}