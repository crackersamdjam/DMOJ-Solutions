#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 1<<19, SZ = MM*2+5, NN = 1e4+5;

int n, k, q, a[MM];

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
#define f first
#define s second

	struct node{
		pii a, b;
		//id cnt
	} tree[SZ];

	node merge(node na, node nb){
		map<int, int> mp;
		mp[na.a.f] += na.a.s; 
		mp[na.b.f] += na.b.s; 
		mp[nb.a.f] += nb.a.s; 
		mp[nb.b.f] += nb.b.s;
		vector<pii> best;
		for(auto &i: mp)
			best.emplace_back(i.s, i.f);
		sort(all(best));
		for(auto &i: best)
			swap(i.f, i.s);

		pii ra = best.back();
		best.pop_back();
		if(best.empty())
			return {ra, {0, 0}};
		pii rb = best.back();
		return {ra, rb};
	}
	
	void build(int nl, int nr, int rt){
		if(nl == nr){
			assert(tree[rt].a.f == 0);
			if(nl >= 1 and nl <= n)
				tree[rt].a = {a[nl], 1};
			return;
		}
		build(nl, nm, lc);
		build(nm+1, nr, rc);
		tree[rt] = merge(tree[lc], tree[rc]);
		// print(nl, nr, tree[rt].a.f, tree[rt].a.s);
	}

	node query(int l, int r, int nl, int nr, int rt){
		if(r < nl or nr < l)
			return {{0, 0}, {0, 0}};
		if(l <= nl and nr <= r)
			return tree[rt];
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
	node query(int l, int r){
		return query(l, r, 0, MM-1, 1);
	}

} ST;

vector<int> v[NN];

int main(){
	scan(n, k);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		v[a[i]].emplace_back(i);
	}
	ST.build(0, MM-1, 1);
	scan(q);
	while(q--){
		int l, r;
		scan(l, r);
		// printf("q "); print(l, r);
		auto ret = ST.query(l, r);
		pii ans = ret.a;
		// print(ans.f, ans.s, ans.s*2, r-l+1);
		int cnt = upper_bound(all(v[ans.f]), r) - lower_bound(all(v[ans.f]), l);

		if(cnt*2 > r-l+1)
			printf("yes %d\n", ans.f);
		else
			printf("no\n");
	}
}