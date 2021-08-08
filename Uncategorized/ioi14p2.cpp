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
const int MM = 2e6+5;

struct L{
	int mn, mx;
};

struct node{
	L lp;
	inline void apply(L v){
		lp.mn = max(lp.mn, v.mx);
		lp.mn = min(lp.mn, v.mn);
		lp.mx = max(lp.mx, v.mx);
		lp.mx = min(lp.mx, v.mn);
	}
};

struct segtree{
	node tree[MM*4];
	int LS, RS;
	const L DEFL = {INT_MAX, 0};
	
	inline void push(int rt, int nl, int nr){ // node with lazy val means yet to push to children (but updated itself)
		if(nl == nr) return;
		L &val = tree[rt].lp; tree[lc].apply(val); tree[rc].apply(val); val = DEFL;
	}
	
	void build(int _LS, int _RS){ build(LS = _LS, RS = _RS, 1); }
	void build(int nl, int nr, int rt){
		tree[rt].lp = DEFL;
		if(nl == nr) return; build(nl, nm, lc); build(nm+1, nr, rc);
	}
	
	void update(int l, int r, L val){ update(l, r, val, LS, RS, 1); }
	void update(int l, int r, L val, int nl, int nr, int rt){
		if(r < nl || l > nr) return;
		if(l <= nl && r >= nr){
			tree[rt].apply(val);
			return;
		}
		push(rt, nl, nr); update(l, r, val, nl, nm, lc); update(l, r, val, nm+1, nr, rc);
	}

	void out(int nl, int nr, int rt, int *&ptr){
		if(nl == nr){
			*ptr++ = tree[rt].lp.mx;
		}
		else{
			push(rt, nl, nr);
			out(nl, nm, lc, ptr);
			out(nm+1, nr, rc, ptr);
		}
	}
} ST;

void buildWall(int n, int q, int op[], int l[], int r[], int h[], int ans[]){
	ST.build(0, n-1);
	for(int i = 0; i < q; i++){
		if(op[i] == 1) //add operation
			ST.update(l[i], r[i], {INT_MAX, h[i]});
		else
			ST.update(l[i], r[i], {h[i], 0});
	}
	for(int i = 0; i < n; i++)
		ans[i] = i;
	ST.out(0, n-1, 1, ans);
}

#ifdef LOCAL
int main(){
	int n, q;
	scan(n, q);
	int op[n], l[n], r[n], h[n], ans[n];
	for(int i = 0; i < q; i++)
		scan(op[i], l[i], r[i], h[i]);
	buildWall(n, q, op, l, r, h, ans);
	for(int i = 0; i < n; i++)
		print(ans[i]);
}
#endif
/*
10 6
1 1 8 4
2 4 9 1
2 3 6 5
1 0 5 3
1 2 2 5
2 6 7 0
*/