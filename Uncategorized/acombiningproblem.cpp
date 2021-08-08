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
using T = int;
using L = int;
const int MM = 1e5+5;

struct node{
	T val; L lp; int sz;
	inline void apply(L v){
		val = v*sz;
		lp = v;
	}
};

struct segtree{
	node tree[MM*4];
	const T DEF = 0;
	const L DEFL = -1;
	int LS, RS;
	
	inline T merge(T va, T vb){
		return va+vb;
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
		tree[rt].val = 1;
		tree[rt].lp = DEFL;
		tree[rt].sz = nr-nl+1;
		if(nl == nr) return; build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
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

	int kth(int k){ return kth(k, LS, RS, 1);}
	int kth(int k, int nl, int nr, int rt){
		if(nl == nr)
			return nl;
		push(rt, nl, nr);
		if(k < tree[lc].val)
			return kth(k, nl, nm, lc);
		return kth(k-tree[lc].val, nm+1, nr, rc);
	}
} ST;

int n, q, psa[MM];

int main(){
	scan(n, q);
	for(int i = 1; i <= n; i++){
		scan(psa[i]);
		psa[i] += psa[i-1];
	}
	psa[n+1] = psa[n];
	psa[n+2] = psa[n];
	ST.build(0, n+1);
	while(q--){
		int op, i, k;
		scan(op, i);
		int m = ST.query(1, n);
		i = (i-1)%m+1;

		if(op != 2){
			scan(k);
			int l = m-i+1;
			k = (k-1)%l+1;
		}

		if(op == 1){
			int l = ST.kth(i), r = ST.kth(i+k);
			ST.update(l+1, r-1, 0);
		}
		else if(op == 2){
			int l = ST.kth(i), r = ST.kth(i+1);
			ST.update(l+1, r-1, 1);
		}
		else{
			int l = ST.kth(i), r = ST.kth(i+k);
			print(psa[r-1] - psa[l-1]);
		}
	}
}
/*
segment tree stores "cnt" = how many elements make up that range
segtree walk to find ith and next k
lazy update to make those k all = 0

op 2:
let r = next "existing" element
update(ith ele, r) all to 1
*/