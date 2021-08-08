#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 5e5+5;

struct T{
	ll in, k, sub;
	//income, subtract, how many times
};
struct L{
	ll in, k, sub;
};

struct node{
	T t; L lp;
	inline void apply(L l){
		t.sub += l.sub;
		t.sub += l.in*t.k;
		t.in += l.in;
		t.k += l.k;

		lp.sub += l.sub;
		lp.sub += l.in*lp.k;
		lp.in += l.in;
		lp.k += l.k;
	}
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
	node tree[MM*4];
	const T DEF = {0, 0, 0};
	const L DEFL = {0, 0};
	int LS, RS;
	
	inline void pull(int rt){
		//nothing
	}
	
	inline void push(int rt, int nl, int nr){ // node with lazy t means yet to push to children (but updated itself)
		if(nl == nr) return;
		L &t = tree[rt].lp; tree[lc].apply(t); tree[rc].apply(t); t = DEFL;
	}
	
	void build(int _LS, int _RS){ build(LS = _LS, RS = _RS, 1); }
	void build(int nl, int nr, int rt){
		tree[rt].t = DEF;
		tree[rt].lp = DEFL;
		if(nl == nr) return; build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	void update(int l, int r, L t){ update(l, r, t, LS, RS, 1); }
	void update(int l, int r, L t, int nl, int nr, int rt){
		if(r < nl || l > nr) return;
		if(l <= nl && r >= nr){
			tree[rt].apply(t);
			return;
		}
		push(rt, nl, nr); update(l, r, t, nl, nm, lc); update(l, r, t, nm+1, nr, rc); pull(rt);
	}
	
	T query(int l, int r){ return query(l, r, LS, RS, 1); }
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr) return DEF;
		if(l <= nl && r >= nr) return tree[rt].t;
		push(rt, nl, nr); 
		if(l <= nm)
			return query(l, r, nl, nm, lc);
		return query(l, r, nm+1, nr, rc);
	}
} ST;

int n, q, a[MM];

void out(){
	for(int i = 1; i <= n; i++){
		auto res = ST.query(i, i);
		cout<<res.in*res.k-res.sub<<' ';
	}
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	ST.build(1, n);
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		ST.update(i, i, {a[i], 0});
	}
	for(int i = 0,op,l,r,x; i < q; i++){
		cin>>op>>l>>r;
		if(op == 1){
			cin>>x;
			ST.update(l, r, {x, 0});
		}
		else{
			ST.update(l, r, {0, 1});
		}
		// out();
	}
	out();
}