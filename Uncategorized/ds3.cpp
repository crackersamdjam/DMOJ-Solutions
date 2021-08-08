#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;

int n, m, a[MM];

struct Tree{
	#define lc rt<<1
	#define rc rt<<1|1
	#define nm ((nl+nr)/2)

	struct node{
		int min, gcd, cnt;
	} tree[MM*3];

	void pull(int rt){
		tree[rt].min = min(tree[lc].min, tree[rc].min);
		tree[rt].gcd = __gcd(tree[lc].gcd, tree[rc].gcd);
		tree[rt].cnt = (tree[lc].gcd == tree[rt].gcd)*tree[lc].cnt
		+ (tree[rc].gcd == tree[rt].gcd)*tree[rc].cnt;
	}

	void update(int l, int v, int nl=1, int nr=n, int rt=1){
		if(l < nl or nr < l)
			return;
		if(nl == nr){
			tree[rt].min = tree[rt].gcd = v;
			tree[rt].cnt = 1;
			return;
		}
		update(l, v, nl, nm, lc);
		update(l, v, nm+1, nr, rc);
		pull(rt);
	}

	int querymin(int l, int r, int nl=1, int nr=n, int rt=1){
		if(r < nl or nr < l)
			return INT_MAX;
		if(l <= nl and nr <= r)
			return tree[rt].min;
		return min(querymin(l, r, nl, nm, lc), querymin(l, r, nm+1, nr, rc));
	}
	int querygcd(int l, int r, int nl=1, int nr=n, int rt=1){
		if(r < nl or nr < l)
			return 0;
		if(l <= nl and nr <= r)
			return tree[rt].gcd;
		return __gcd(querygcd(l, r, nl, nm, lc), querygcd(l, r, nm+1, nr, rc));
	}
	int querycnt(int l, int r, int v, int nl=1, int nr=n, int rt=1){
		if(r < nl or nr < l)
			return 0;
		if(l <= nl and nr <= r)
			return (tree[rt].gcd == v)*tree[rt].cnt;
		return querycnt(l, r, v, nl, nm, lc) + querycnt(l, r, v, nm+1, nr, rc);
	}

} ST;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		ST.update(i, a[i]);
	}
	while(m--){
		char op; int l, r;
		cin>>op>>l>>r;
		if(op == 'C')
			ST.update(l, r);
		if(op == 'M')
			cout<<ST.querymin(l, r)<<'\n';
		if(op == 'G')
			cout<<ST.querygcd(l, r)<<'\n';
		if(op == 'Q')
			cout<<ST.querycnt(l, r, ST.querygcd(l, r))<<'\n';
	}
	
	return 0;
}