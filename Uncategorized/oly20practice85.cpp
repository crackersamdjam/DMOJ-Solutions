#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll;
constexpr int MM = 2e6+5, LOG = 20;

int n, q, root, aa[MM], in[MM], out[MM], t;
ll sum[MM];
int dep[MM], sp[LOG][MM];
std::vector<int> adj[MM];

int getlca(int u, int v){
	if(dep[u] < dep[v])
		std::swap(u, v);
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] && (dep[sp[i][u]] >= dep[v]))
			u = sp[i][u];
	}
	if(u == v)
		return u;
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] && ~sp[i][v] && (sp[i][u] != sp[i][v])){
			u = sp[i][u];
			v = sp[i][v];
		}
	}
	return sp[0][u];
}

struct node{
	ll val, lp, sum;
	void apply(ll v){
		val += v*sum;
		lp += v;
	}
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
	node tree[MM*3];
	ll DEF = 0;
	//default value
	
	ll merge(ll va, ll vb){
		return va + vb;
	}
	
	void push_up(int rt){
		tree[rt].val = merge(tree[lc].val, tree[rc].val);
		tree[rt].sum = tree[lc].sum + tree[rc].sum;
	}
	
	// node with lazy val means yet to push to children (but updated itself)
	void push_down(int rt, int nl, int nr){
		ll &val = tree[rt].lp;
		if(nl != nr){
			tree[lc].apply(val);
			tree[rc].apply(val);
		}
		val = DEF;
	}
	
	void build(int l = 1, int r = n+n, int rt = 1){
		int nl = l, nr = r;
		if(l == r){
			tree[rt].val = DEF;
			tree[rt].lp = 0;
			return;
		}
		build(l, nm, lc);
		build(nm+1, r, rc);
		push_up(rt);
	}
	
	void init(int l, int r, ll val, int nl = 1, int nr = n+n, int rt = 1){
		if(r < nl || l > nr)
			return;
		if(l <= nl && r >= nr){
			tree[rt].sum = val;
			return;
		}
		init(l, r, val, nl, nm, lc);
		init(l, r, val, nm+1, nr, rc);
		push_up(rt);
	}
	
	void update(int l, int r, ll val, int nl = 1, int nr = n+n, int rt = 1){
		if(r < nl || l > nr)
			return;
		if(l <= nl && r >= nr){
			tree[rt].apply(val);
			return;
		}
		push_down(rt, nl, nr);
		update(l, r, val, nl, nm, lc);
		update(l, r, val, nm+1, nr, rc);
		push_up(rt);
	}
	
	ll query(int l, int r, int nl = 1, int nr = n+n, int rt = 1){
		if(l > r)
			return 0;
		if(r < nl || l > nr)
			return DEF;
		if(l <= nl && r >= nr)
			return tree[rt].val;
		push_down(rt, nl, nr);
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
#undef lc
#undef rc
#undef nm
} ST;

void dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	sum[cur] = sum[pre]+aa[cur];
	in[cur] = ++t;
	ST.init(t, t, 1);
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		dfs(u, cur);
	}
	out[cur] = ++t;
	ST.init(t, t, -1);
}

int main(){
	memset(sp, -1, sizeof sp);
	scan(n, q, root);
	for(int i = 1; i <= n; i++)
		scan(aa[i]);
	for(int i = 0,b,c; i < n-1; i++){
		scan(b, c);
		adj[b].emplace_back(c);
		adj[c].emplace_back(b);
	}
	dfs(root, 0);
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			if(~sp[i-1][j])
				sp[i][j] = sp[i-1][ sp[i-1][j] ];
		}
	}
	
	while(q--){
		int op, a, b;
		scan(op, a, b);
		if(op == 1){
			ST.update(in[a], in[a], b);
			ST.update(out[a], out[a], b);
		}
		else if(op == 2){
			ST.update(in[a], out[a], b);
		}
		else{
			int c = getlca(a, b);
			ll ans = sum[a]+sum[b]-sum[sp[0][c]]-sum[c] + ST.query(in[c], in[a]) + ST.query(in[c]+1, in[b]);
			print(ans);
		}
	}
}