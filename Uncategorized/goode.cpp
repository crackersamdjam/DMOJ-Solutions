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
const int MM = 1e6+5;

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)/2)

	struct node{
		int on, off;
		bool flip;
		
		void apply(bool f){
			if(f){
				swap(on, off);
				flip ^= 1;
			}
		}

	} t[MM*4];

	int LS, RS;

	void build(int _LS, int _RS){
		build(LS = _LS, RS = _RS, 1);
	}

	void pull(int rt){
		t[rt].on = t[lc].on + t[rc].on;
		t[rt].off = t[lc].off + t[rc].off;
	}

	void build(int nl, int nr, int rt){
		t[rt].on = nr-nl+1;
		if(nl == nr)
			return;
		build(nl, nm, lc);
		build(nm+1, nr, rc);
	}

	void push(int nl, int nr, int rt){
		if(nl == nr)
			return;
		t[lc].apply(t[rt].flip);
		t[rc].apply(t[rt].flip);
		t[rt].flip = 0;
	}

	void update(int l, int r){
		update(l, r, LS, RS, 1);
	}
	void update(int l, int r, int nl, int nr, int rt){
		if(r < nl or nr < l)
			return;
		if(l <= nl and nr <= r){
			t[rt].apply(1);
			return;
		}
		push(nl, nr, rt);
		update(l, r, nl, nm, lc);
		update(l, r, nm+1, nr, rc);
		pull(rt);
	}

	int query(int k){
		return query(k, LS, RS, 1);
	}
	int query(int k, int nl, int nr, int rt){
		if(nl == nr)
			return nl+k;
		push(nl, nr, rt);
		if(t[lc].on <= k)
			return query(k-t[lc].on, nm+1, nr, rc);
		return query(k, nl, nm, lc);
	}

} ST;

int n, q, k;

int main(){
	scan(n, q, k);
	ST.build(1, n+1);
	while(q--){
		int a, b;
		scan(a, b);
		ST.update(a, b);
		int res = ST.query(k-1);
		if(res > n)
			puts("AC?");
		else
			print(res);
	}
}