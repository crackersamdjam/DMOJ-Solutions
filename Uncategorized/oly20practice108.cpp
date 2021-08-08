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
using T = int;
using L = int;
const int MM = 1e5+5;

int n, m, a[MM], dp[MM];
vector<int> in[MM];

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

struct node{
	T val; L lp;
	inline void apply(L v){
		val = min(val, v);
		lp = min(lp, v);
	}
};

struct segtree{
	node tree[MM*4];
	const T DEF = 1e9;
	const T DEFL = 1e9;
	const static int LS = 0, RS = MM-2;
	inline T merge(T va, T vb){
		return min(va, vb);
	}
	inline void pull(int rt){
		tree[rt].val = merge(tree[lc].val, tree[rc].val);
	}
	inline void push(int rt, int nl, int nr){ // node with lazy val means yet to push to children (but updated itself)
		if(nl == nr) return;
		L &val = tree[rt].lp; tree[lc].apply(val); tree[rc].apply(val); val = DEFL;
	}
	void build(int nl = LS, int nr = RS, int rt = 1){
		tree[rt].val = DEF;
		tree[rt].lp = DEFL;
		if(nl == nr) return; build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	void update(int l, int r, T val, bool fix, int nl = LS, int nr = RS, int rt = 1){
		if(r < nl || l > nr) return;
		if(l <= nl && r >= nr){
			if(fix){
				tree[rt].val = val;
				tree[rt].lp = 1e9;
			}
			else{
				tree[rt].apply(val);
				// tree[rt].val = min(tree[rt].val, val);
			}
			return;
		}
		push(rt, nl, nr);
		update(l, r, val, fix, nl, nm, lc); update(l, r, val, fix, nm+1, nr, rc); pull(rt);
	}
	T query(int l, int r, int nl = LS, int nr = RS, int rt = 1){
		if(l > r) return DEF;
		if(r < nl || l > nr) return DEF;
		if(l <= nl && r >= nr) return tree[rt].val;
		push(rt, nl, nr);
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST;

int main(){
	scan(n, m);
	ST.build();
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		if(in[a[i]].empty())
			dp[i] = 1;
		else
			dp[i] = dp[in[a[i]].back()]+1;

		dp[i] = min(dp[i], ST.query(a[i], a[i])+1);
		in[a[i]].emplace_back(i);

		ST.update(a[i], a[i], dp[i], 1);
		ST.update(1, a[i]-1, dp[i], 0);
		ST.update(a[i]+1, m, dp[i], 0);
		// print(i, a[i], dp[i]);
	}
	print(ST.query(1, m)+1);
}