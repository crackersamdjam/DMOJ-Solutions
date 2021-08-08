#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 2e5+5;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
// #define npm int nl, int nr, int rt
#define npm int nl = 0, int nr = MM-2, int rt = 1
#define lpm nl, nm, lc
#define rpm nm+1, nr, rc

struct segtree{
	ll sz[MM*4];
	ll sum[MM*4];
	ll lp[MM*4];

	inline void pull(int rt){
		sz[rt] = sz[lc]+sz[rc];
		sum[rt] = sum[lc]+sum[rc];
	}
	
	inline void push(int rt){
		// node with lazy val means yet to push to children (but updated itself)
		auto &l = lp[rt];
		lp[lc] += l;
		sum[lc] += sz[lc]*l;
		lp[rc] += l;
		sum[rc] += sz[rc]*l;
		l = 0;
	}

	void build(int l, int r, npm){
		if(nl == nr){
			sz[rt] = l <= nl and nl <= r;
			return;
		}
		build(l, r, lpm);
		build(l, r, rpm);
	}

	void update(int l, int r, int op, npm){
		if(l > r) return;
		if(r < nl || l > nr) return;
		if(l <= nl && r >= nr){
			if(op == 0){
				// set to 0
				assert(nl == nr);
				sz[rt] = sum[rt] = 0;
			}
			else{
				lp[rt] += op;
				sum[rt] += sz[rt]*op;
				// add one
			}
			return;
		}
		push(rt);
		update(l, r, op, lpm);
		update(l, r, op, rpm);
		pull(rt);
	}
	
	ll query(int l, int r, npm){
		if(l > r) return 0;
		if(r < nl || l > nr) return 0;
		if(l <= nl && r >= nr) return sum[rt];
		push(rt);
		return query(l, r, lpm) + query(l, r, rpm);
	}

} ST;

int n, a[MM];
int last[MM], pre[MM];
ll ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	ST.build(1, n);

	for(int i = 1; i <= n; i++){
		cin>>a[i];
		int l = last[a[i]];
		int p = pre[l];
		ST.update(p, l-1, -1);
		ST.update(l, l, 0);

		ll add = ST.query(l+1, i-2);
		ans += add;

		ST.update(last[a[i]]+1, i-1, 1);
		pre[i] = l;
		last[a[i]] = i;
	}

	cout<<ans<<'\n';
}