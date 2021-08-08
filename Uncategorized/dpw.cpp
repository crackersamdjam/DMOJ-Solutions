#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

using namespace std;
using ll = long long;
using T = long long;
using L = long long;
const int MM = 4e5+5;

struct node{
	T val; L lp;
	inline void apply(L v){
		val += v;
		lp += v;
	}
};

struct segtree{
	node tree[MM*4];
	const T DEF = LLONG_MIN/2;
	const L DEFL = 0;
	int LS, RS;
	
	inline T merge(T va, T vb){
		return max(va, vb);
	}
	
	inline void pull(int rt){
		tree[rt].val = merge(tree[lc].val, tree[rc].val);
	}
	
	inline void push(int rt, int nl, int nr){ // node with lazy val means yet to push to children (but updated itself)
		if(nl == nr or tree[rt].lp == DEFL) return;
		L &val = tree[rt].lp; tree[lc].apply(val); tree[rc].apply(val); val = DEFL;
	}
	
	void build(int _LS, int _RS){ build(LS = _LS, RS = _RS, 1); }
	void build(int nl, int nr, int rt){
		tree[rt].val = DEF;
		tree[rt].lp = DEFL;
		if(nl == nr){
			tree[rt].val = 0;
			return;
		}
		build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	void update(int l, int r, L val){ update(l, r, val, LS, RS, 1); }
	void update(int l, int r, L val, int nl, int nr, int rt){
		if(r < nl || l > nr) return;
		if(l <= nl && r >= nr){
			tree[rt].apply(val);
			return;
		}
		push(rt, nl, nr); update(l, r, val, nl, nm, lc); update(l, r, val, nm+1, nr, rc); pull(rt);
	}
	
	T query(int l, int r){ return query(l, r, LS, RS, 1); }
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr) return DEF;
		if(l <= nl && r >= nr) return tree[rt].val;
		push(rt, nl, nr); return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST;

int n, m;
vector<pair<int, int>> a[MM];
ll dp[MM];

int main(){
	scan(n, m);
	while(m--){
		int l, r, v;
		scan(l, r, v);
		a[l].emplace_back(l-1, v);
		a[r+1].emplace_back(l-1, -v);
	}
	ST.build(0, n);
	for(int i = 1; i <= n+1; i++){
		for(auto j: a[i])
			ST.update(0, j.first, j.second);
		dp[i] = ST.query(0, i-1);
		ST.update(i, i, dp[i]);
	}
	print(dp[n+1]);
}