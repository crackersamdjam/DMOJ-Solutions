#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

using namespace std;
using ld = double;
using T = vector<vector<ld>>;
using V = vector<ld>;
const int MM = 5e4+5;

int tc, n, m, q, adj[MM][8][8];

inline V mul(V va, T m){
	int k = size(va);
	V vb(k, 0);
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++)
			vb[i] += va[j]*m[j][i];
	}
	return vb;
}

inline T mul(T va, T vb){
	int k = size(va);
	T vc(k);
	for(int i = 0; i < k; i++){
		vc[i].resize(k, 0);
		for(int j = 0; j < k; j++){
			for(int l = 0; l < k; l++)
				vc[i][j] += va[i][l]*vb[l][j];
		}
	}
	return vc;
}

inline T fpow(T m){
	for(int i = 0; i < 10; i++)
		m = mul(m, m);
	return m;
}

struct segtree{
	T t[MM*4];
	T DEF;
	int LS, RS;
	
	inline T merge(T va, T vb){
		return mul(va, vb);
	}
	
	inline void pull(int rt){
		t[rt] = merge(t[lc], t[rc]);
	}

	inline T go(int nl, int rt){
		T tmp(8);
		for(int i = 0; i < 8; i++){
			tmp[i].resize(8, 0);
			int tot = 0;
			for(int j = 0; j < 8; j++)
				tot += adj[nl][i][j];
			if(tot and i < 4){
				for(int j = 0; j < 8; j++)
					tmp[i][j] = (ld)adj[nl][i][j]/tot;
			}
			else{
				tmp[i][i] = 1;
			}
		}

		tmp = fpow(tmp);

		t[rt].resize(4);
		for(int i = 0; i < 4; i++){
			t[rt][i].resize(4);
			for(int j = 0; j < 4; j++)
				t[rt][i][j] = tmp[i][j+4];
		}
		return tmp;
	}
	
	void build(int _LS, int _RS){
		DEF.resize(4);
		for(int i = 0; i < 4; i++){
			DEF[i].resize(4, 0);
			DEF[i][i] = 1;
		}
		build(LS = _LS, RS = _RS, 1);
	}
	void build(int nl, int nr, int rt){
		if(nl == nr){
			go(nl, rt);
			return;
		}
		build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	void update(int l){ update(l, LS, RS, 1); }
	void update(int l, int nl, int nr, int rt){
		if(l < nl || l > nr) return;
		if(nl == nr){
			go(nl, rt);
			return;
		}
		update(l, nl, nm, lc), update(l, nm+1, nr, rc); pull(rt);
	}
	
	T query(int l, int r){ return query(l, r, LS, RS, 1); }
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr) return DEF;
		if(l <= nl && r >= nr) return t[rt];
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST;

int main(){
	scan(tc);
	for(int t = 1; t <= tc; t++){
		printf("Case #%d:", t);
		scan(n, m, q);
		while(m--){
			int a, b, c;
			scan(a, b, c);
			int ia = a/4;
			a -= ia*4;
			b -= ia*4;
			adj[ia][a][b] = c;
		}
		ST.build(0, (n-1)/4);
		while(q--){
			int op, a, b, c = 0;
			scan(op, a, b);
			if(op == 3){
				int ia = a/4;
				a -= ia*4;
				int ib = b/4;
				b -= ib*4;

				if(ia > ib){
					printf(" 0.000000");
					continue;
				}

				auto res = ST.query(ia, ib-1);

				memcpy(adj[MM-1], adj[ib], sizeof adj[ib]);
				for(int i = 0; i < 8; i++)
					adj[MM-1][b][i] = 0;
				adj[MM-1][b][b] = 1; //force to stay at b

				auto last = ST.go(MM-1, 0);
				last.resize(4);
				for(int i = 0; i < 4; i++)
					last[i].resize(4);

				res = mul(res, last);

				vector<ld> va(4, 0);
				va[a] = 1;
				auto ans = mul(va, res);
				printf(" %.6lf", ans[b]);
			}
			else{
				if(op == 1)
					scan(c);

				int ia = a/4;
				a -= ia*4;
				b -= ia*4;
				adj[ia][a][b] = c;
				ST.update(ia);
			}
		}
		printf("\n");
		for(int i = 0; i <= (n-1)/4; i++)
			memset(adj[i], 0, sizeof adj[i]);
	}
}