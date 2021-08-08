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
const int MM = 2e5+5;

struct node{
	T val; L lp; int sum;
	inline void apply(L v){
		val.first += v;
		lp += v;
	}
};

struct segtree{
	node tree[MM*4];
	const T DEF = {INT_MIN, 0};
	const L DEFL = 0;
	int LS, RS;
	
	inline void pull(int rt){
		tree[rt].val = max(tree[lc].val, tree[rc].val);
		tree[rt].sum = tree[lc].sum + tree[rc].sum;
	}
	
	inline void push(int rt, int nl, int nr){ // node with lazy val means yet to push to children (but updated itself)
		if(nl == nr or tree[rt].lp == DEFL) return;
		L &val = tree[rt].lp; tree[lc].apply(val); tree[rc].apply(val); val = DEFL;
	}
	
	void build(int _LS, int _RS){ build(LS = _LS, RS = _RS, 1); }
	void build(int nl, int nr, int rt){
		tree[rt].val = {-nl, nl};
		tree[rt].lp = DEFL;
		if(nl == nr) return; build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	void update(int l, int r, L val){ update(l, r, val, LS, RS, 1); }
	void update(int l, int r, L val, int nl, int nr, int rt){
		if(r < nl || l > nr) return;
		if(l <= nl && r >= nr){
			if(val != INT_MAX){
				//reset num
				assert(nl == nr);
				tree[rt].val = {-nl, nl};
				tree[rt].sum++;
			}
			else
				tree[rt].apply(1);
			return;
		}
		push(rt, nl, nr); update(l, r, val, nl, nm, lc); update(l, r, val, nm+1, nr, rc); pull(rt);
	}

	T query(int l, int r){ return query(l, r, LS, RS, 1); }
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr) return DEF;
		if(l <= nl && r >= nr) return tree[rt].val;
		push(rt, nl, nr); return max(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
	
	int sum(int l, int r){ return sum(l, r, LS, RS, 1); }
	int sum(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr) return 0;
		if(l <= nl && r >= nr) return tree[rt].sum;
		push(rt, nl, nr); return sum(l, r, nl, nm, lc) + sum(l, r, nm+1, nr, rc);
	}

} ST;


int n, q;


int main(){
	scan(n, q);
	n = min(n, q);
	ST.build(1, n);

	for(int t = 0,op,l,r; t < q; t++){
		scan(op, l, r);
		l = min(l, n+1);
		r = min(r, n);
		if(op == 1){
			ST.update(l, r, INT_MAX);
			while(1){
				auto [v, i] = ST.query(1, n);
				if(v < 0) break;
				ST.update(i, i, v-i);
			}
		}
		else print(ST.sum(l, r));
	}
}