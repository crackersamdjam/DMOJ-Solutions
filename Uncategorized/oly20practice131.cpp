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
using ll = long long;
const int MM = 1e5+5;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

int n, q;
ll mod;

struct L{
	ll add, mul;
	bool operator==(const L &o){
		return add==o.add and mul==o.mul;
	}
} lp[MM*4];
ll val[MM*4];
int sz[MM*4];
ll in[MM];
const L LDEF = {0, 1};

void apply(int rt, L v){
	val[rt] = (val[rt]*v.mul+v.add*sz[rt])%mod;
	lp[rt].add = (lp[rt].add*v.mul+v.add)%mod;
	lp[rt].mul = (lp[rt].mul*v.mul)%mod;
}

void pull(int rt){
	val[rt] = (val[lc]+val[rc])%mod;
}

void push(int nl, int nr, int rt){
	if(nl == nr || lp[rt] == LDEF) return;
	apply(lc, lp[rt]);
	apply(rc, lp[rt]);
	lp[rt] = LDEF;
}

void build(int nl, int nr, int rt){
	lp[rt] = LDEF;
	sz[rt] = nr-nl+1;
	if(nl == nr){
		val[rt] = in[nl];
		return;
	}
	build(nl, nm, lc);
	build(nm+1, nr, rc);
	pull(rt);
}

void up(int l, int r, L v, int nl, int nr, int rt){
	if(r < nl or nr < l) return;
	push(nl, nr, rt);
	if(l <= nl and nr <= r){
		apply(rt, v);
		return;
	}
	up(l, r, v, nl, nm, lc);
	up(l, r, v, nm+1, nr, rc);
	pull(rt);
}

ll qu(int l, int r, int nl, int nr, int rt){
	if(r < nl or nr < l) return 0;
	if(l <= nl and nr <= r)
		return val[rt];
	push(nl, nr, rt);
	return (qu(l, r, nl, nm, lc) + qu(l, r, nm+1, nr, rc))%mod;
}

int main(){
	scan(n, mod);
	for(int i = 1; i <= n; i++)
		scan(in[i]);
	build(1, n, 1);
	scan(q);
	int op, l, r, x;
	while(q--){
		scan(op, l, r);
		
		if(op == 1){
			scan(x);
			up(l, r, {0, x%mod}, 1, n, 1);
		}
		else if(op == 2){
			scan(x);
			up(l, r, {x%mod, 1}, 1, n, 1);
		}
		else if(op == 3){
			print(qu(l, r, 1, n, 1));
		}
		else abort();
	}
}