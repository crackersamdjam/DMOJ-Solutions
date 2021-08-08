#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using T = vector<vector<ll>>;
const int MM = 4e4+5 ,SZ = MM;
const ll inf = LLONG_MAX/4;

int n, m, q, off;
ll b[MM], tot;

struct segtree{
	#define lc (rt<<1)
	#define rc (rt<<1|1)
	#define nm ((nl+nr)>>1)
	T tree[SZ];
	const T DEF = T(4, vector<ll>(4, inf));
	int LS, RS;
	
	inline T merge(T va, T vb){
		T vc = DEF;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				for(int k = 0; k < 4; k++){
					for(int l = 0; l <= k; l++){
						//l+4-k <= 4
						//l-k <= 0
						//l <= k
						vc[i][j] = min(vc[i][j], va[i][k]+vb[l][j]);
					}
				}
			}
		}
		return vc;
	}
	
	inline void pull(int rt){
		tree[rt] = merge(tree[lc], tree[rc]);
	}
	
	void build(int _LS, int _RS){ build(LS = _LS, RS = _RS, 1); }
	void build(int nl, int nr, int rt){
		if(nl == nr){
			tree[rt] = DEF;
			for(int i = 0; i < 4; i++){
				tree[rt][i][i] = b[nl*4+i];
				for(int j = i+1; j < 4; j++){
					tree[rt][i][j] = b[nl*4+i] + b[nl*4+j];
				}
			}
			return;
		}
		build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	void update(int l){ update(l, LS, RS, 1); }
	void update(int l, int nl, int nr, int rt){
		if(l < nl || l > nr) return;
		if(nl == nr){
			tree[rt] = DEF;
			for(int i = 0; i < 4; i++){
				tree[rt][i][i] = b[nl*4+i];
				for(int j = i+1; j < 4; j++){
					tree[rt][i][j] = b[nl*4+i] + b[nl*4+j];
				}
			}
			return;
		}
		update(l, nl, nm, lc); update(l, nm+1, nr, rc); pull(rt);
	}
	
	T query(int l, int r){ return query(l, r, LS, RS, 1); }
	T query(int l, int r, int nl, int nr, int rt){
		// if(r < nl || l > nr) return NONE;
		if(l <= nl && r >= nr) return tree[rt];
		if(r <= nm) return query(l, r, nl, nm, lc);
		if(l > nm) return query(l, r, nm+1, nr, rc);
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST;

ll get(){
	ll ret = tot;
	auto v = ST.query(0, m-1);
	for(int i = off; i < 4; i++){
		for(int j = 0; j < 4; j++){
			int dif = (3-j) + 1 + i-off;
			if(dif <= 4)
				ret = min(ret, v[i][j]);
		}
	}
	if(m > 1){
		auto v = ST.query(1, m-1);
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				int dif = (3-j) + 1 + i+4-off; //add the extra ones in first
				if(dif <= 4)
					ret = min(ret, v[i][j]);
			}
		}
	}
	return tot-ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	off = (4-n%4)%4;
	n += off;
	for(int i = off; i < n; i++){
		cin>>b[i];
		tot += b[i];
	}
	m = n/4;
	ST.build(0, m-1);
	cout<<get()<<'\n';
	cin>>q;
	while(q--){
		int i, x; cin>>i>>x;
		i += off-1;
		tot += x-b[i];
		b[i] = x;
		ST.update(i/4);
		cout<<get()<<'\n';
	}
}