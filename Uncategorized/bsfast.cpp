#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
constexpr int MM = 1e6+5;

int n, q, a[MM], p;

struct Segval{
	#define lc (rt<<1)
	#define rc (rt<<1|1)
	#define nm ((nl+nr)>>1)

	int val[MM*4];

	const int DEF = 1e9+5;
	int LS, RS;
	
	inline int merge(int va, int vb){
		return min(va, vb);
	}
	
	inline void pull(int rt){
		val[rt] = merge(val[lc], val[rc]);
	}

	void build(int _LS, int _RS){ build(LS = _LS, RS = _RS, 1); }
	void build(int nl, int nr, int rt){
		val[rt] = a[nl];
		if(nl == nr) return; build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	void update(int i, int v){ update(i, v, LS, RS, 1); }
	void update(int i, int v, int nl, int nr, int rt){
		if(nl == nr){
			val[rt] = v;
			return;
		}
		if(i <= nm) update(i, v, nl, nm, lc);
		else update(i, v, nm+1, nr, rc);
		pull(rt);
	}

	// https://cp-algorithms.com/data_structures/segment_tree.html#toc-tgt-8
	int get_first(int l, int r, int x){ return get_first(l, r, x, LS, RS, 1); }
	int get_first(int l, int r, int x, int nl, int nr, int rt){
		if(nr < l or r < nl) return -1;
		if(l <= nl and nr <= r){
			if(val[rt] >= x) return -1;
			while(nl != nr){
				if(val[lc] < x){
					rt = lc;
					nr = nm;
				}
				else{
					rt = rc;
					nl = nm+1;
				}
			}
			return nl;
		}
		int ls = get_first(l, r, x, nl, nm, lc);
		if(ls != -1) return ls;
		return get_first(l, r, x, nm+1, nr, rc);
	}

} ST;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	ST.build(1, n+1);
	while(q--){
		int op, i, l, r, x;
		cin>>op;
		if(op == 1){
			cin>>i>>x;
			i ^= p, x ^= p;
			ST.update(i, x);
		}
		else{
			cin>>l>>r>>x;
			l ^= p, r ^= p, x ^= p;
			p = ST.get_first(l, r, x);
			// assert(p != -1);
			cout<<p<<'\n';
		}
	}
}