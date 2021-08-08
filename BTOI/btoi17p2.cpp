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
using T = vector<vector<int>>;
const int MM = 5e4+5;

int k, n, m, q, adj[MM][5][5];

struct segtree{
	T t[MM*4];
	T DEF;
	int LS, RS;
	
	inline T merge(T va, T vb){
		T vc(k);
		for(int i = 0; i < k; i++){
			vc[i].resize(k, 1e9);
			for(int j = 0; j < k; j++){
				for(int l = 0; l < k; l++)
					vc[i][j] = min(vc[i][j], va[i][l]+vb[l][j]);
			}
		}
		return vc;
	}
	
	inline void pull(int rt){
		t[rt] = merge(t[lc], t[rc]);
	}
	
	void build(int _LS, int _RS){
		DEF.resize(k);
		for(int i = 0; i < k; i++){
			DEF[i].resize(k, 1e9);
			DEF[i][i] = 0;
		}
		build(LS = _LS, RS = _RS, 1);
	}
	void build(int nl, int nr, int rt){
		if(nl == nr){
			t[rt].resize(k);
			for(int i = 0; i < k; i++){
				t[rt][i].resize(k);
				for(int j = 0; j < k; j++)
					t[rt][i][j] = adj[nl][i][j];
			}
			return;
		}
		build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	T query(int l, int r){ return query(l, r, LS, RS, 1); }
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr) return DEF;
		if(l <= nl && r >= nr) return t[rt];
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST;

int main(){
	memset(adj, 0x3f, sizeof adj);
	scan(k, n, m, q);
	while(m--){
		int a, b, c;
		scan(a, b, c);
		assert(a/k+1 == b/k);
		adj[a/k][a%k][b%k] = c;
	}
	ST.build(0, (n-1)/k-1);
	while(q--){
		int a, b;
		scan(a, b);
		auto res = ST.query(a/k, b/k-1);
		vector<int> va(k, 1e9), vb(k, 1e9);
		va[a%k] = 0;
		for(int i = 0; i < k; i++){
			for(int j = 0; j < k; j++){
				vb[i] = min(vb[i], va[j]+res[j][i]);
			}
		}
		int ans = vb[b%k];
		print(ans >= 1e9 ? -1 : ans);
	}
}