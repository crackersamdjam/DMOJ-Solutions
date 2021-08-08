// (n+q) log n
#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx")
#endif

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
using T = pair<int, int>;
using L = int;
const int MM = 5e5+5, LIM = 5e5;

struct node{
	T val; L lp; int ls, min;
	inline void apply(L v){
		assert(v > val.first);
		val = {v, ls};
		lp = v;
		min = v;
	}
};

struct segtree{
	node tree[MM*4];
	const T DEF = {1e9, 1e9};
	const L DEFL = 0;
	int LS, RS;
	
	inline T merge(T va, T vb){
		if(va.first+va.second == vb.first+vb.second)
			return va.second < vb.second ? va : vb; //second will become b
		return (va.first+va.second < vb.first+vb.second) ? va : vb;
	}
	
	inline void pull(int rt){
		tree[rt].val = merge(tree[lc].val, tree[rc].val);
		tree[rt].min = min(tree[lc].min, tree[rc].min); ///reeeee
	}
	
	inline void push(int rt, int nl, int nr){ // node with lazy val means yet to push to children (but updated itself)
		if(nl == nr or tree[rt].lp == DEFL) return;
		L val = tree[rt].lp; tree[lc].apply(val); tree[rc].apply(val); tree[rt].lp = DEFL;
	}
	
	void build(int _LS, int _RS){ build(LS = _LS, RS = _RS, 1); }
	void build(int nl, int nr, int rt){
		tree[rt].ls = nl;
		tree[rt].lp = DEFL;
		tree[rt].val = {0, nl}; //the previous ones are covered
		if(nl == nr) return; build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	void update(int l, int r, L val){ if(l <= r) update(l, r, val, LS, RS, 1); }
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
	//search for first index where value becomes less
	int upper_bound(int v){ return upper_bound(v, LS, RS, 1);}
	int upper_bound(int v, int nl, int nr, int rt){
		if(nl == nr) return nl;
		push(rt, nl, nr);
		return tree[lc].min >= v ? upper_bound(v, nm+1, nr, rc) : upper_bound(v, nl, nm, lc);
	}
} ST;

int n;
array<int, 4> ans = {INT_MAX};

struct st{
	int a, b, c;
	bool operator<(const st &o) const{
		return a < o.a;
	}
} q[MM];


int main(){
	scan(n);
	// assert(n > 0 and n <= LIM);
	for(int i = 0; i < n; i++){
		scan(q[i].a, q[i].b, q[i].c);
		// assert(q[i].a > 0 and q[i].a <= LIM);
		// assert(q[i].b > 0 and q[i].b <= LIM);
		// assert(q[i].c > 0 and q[i].c <= LIM);
	}
	ST.build(0, MM-1);
	sort(q, q+n+1);
	for(int t = n; t >= 0; t--){
		auto i = q[t];
		auto [c, b] = ST.tree[1].val;
		int a = i.a;
		ans = min(ans, {a+b+c, a, b, c});

		if(t){
			int j = ST.upper_bound(i.c);
			ST.update(j, i.b-1, i.c);
		}
	}
	print(ans[1], ans[2], ans[3]);
}