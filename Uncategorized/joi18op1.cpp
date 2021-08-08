#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef int T;
typedef int L;
constexpr int MM = 1e6+5;

struct node{
	T val, real;
	L lp;
	inline void apply(const L v){
		val += v;
		lp += v;
		real += v;
	}
};

std::set<int> vals[MM];

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
	node tree[MM*3];
	const T DEF = INT_MIN/3;
	const L DEFL = 0;
	int LS = 1, RS = MM-1;
	
	inline T merge(T va, T vb){
		return va > vb ? va : vb;
	}
	
	inline void pull(int rt){
		tree[rt].real = merge(tree[lc].real, tree[rc].real);
	}
	
	// node with lazy val means yet to push to children (but updated itself)
	inline void push(int rt, int nl, int nr){
		L &val = tree[rt].lp;
		if(nl != nr){
			tree[lc].apply(val);
			tree[rc].apply(val);
		}
		val = DEFL;
	}
	
	void build(int l, int r, int rt){
		int nl = l, nr = r;
		
		tree[rt].val = 0;
		tree[rt].real = DEF;
		tree[rt].lp = DEFL;
		
		if(l == r){
			return;
		}
		build(l, nm, lc);
		build(nm+1, r, rc);
		pull(rt);
	}
	
	void build(){
		build(LS, RS, 1);
	}
	
	void update(int l, int r, L val, int nl, int nr, int rt){
		if(r < nl || l > nr)
			return;
		if(l <= nl && r >= nr){
			tree[rt].apply(val);
			// cout<<"update "<<l<<' '<<r<<' '<<val<<", "<<tree[rt].val<<' '<<tree[rt].real<<endl;
			return;
		}
		push(rt, nl, nr);
		update(l, r, val, nl, nm, lc);
		update(l, r, val, nm+1, nr, rc);
		pull(rt);
	}
	
	void update(int l, int r, L val){
		update(l, r, val, LS, RS, 1);
	}	

	void edit(int l, int r, bool op, L val, int nl, int nr, int rt){
		if(r < nl || l > nr)
			return;
		if(l <= nl && r >= nr){
			if(op) vals[nl].insert(val);
			else vals[nl].erase(vals[nl].lower_bound(val));
			tree[rt].real = (vals[l].size() ? *vals[l].rbegin() : 0) + 1 + tree[rt].val;
			// cout<<"edit "<<l<<' '<<tree[rt].val<<' '<<tree[rt].real<<endl;
			return;
		}
		push(rt, nl, nr);
		edit(l, r, op, val, nl, nm, lc);
		edit(l, r, op, val, nm+1, nr, rc);
		pull(rt);
	}
	
	void edit(int l, bool op, L val){
		edit(l, l, op, val, LS, RS, 1);
	}
		
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr)
			return DEF;
		if(l <= nl && r >= nr)
			return tree[rt].real;
		push(rt, nl, nr);
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
	
	T query(int l, int r){
		return query(l, r, LS, RS, 1);
	}
#undef lc
#undef rc
#undef nm
} ST;

int n, q, rt, ls, rs, mid;

std::vector<int> countScans(std::vector<int> a, std::vector<int> x, std::vector<int> v){
	n = a.size(), q = x.size();
	std::vector<int> ans(q);
	auto mp = a;
	mp.insert(mp.end(), all(v));
	sort(all(mp));
	mp.erase(unique(mp.begin(), mp.end()), mp.end());

	ST.LS = 1;
	ST.RS = mp.size()+1;
	ST.build();
	for(int i = 0; i < n; i++){
		int id = i;
		a[id] = lower_bound(all(mp), a[id]) - mp.begin()+1;
		ST.update(a[id], ST.RS, -1);
		ST.edit(a[id], 1, i);
	}

	for(int i = 0; i < q; i++){
		int id = x[i];
		ST.update(a[id], ST.RS, 1);
		ST.edit(a[id], 0, id);
		a[id] = lower_bound(all(mp), v[i]) - mp.begin()+1;
		ST.update(a[id], ST.RS, -1);
		ST.edit(a[id], 1, id);
		ans[i] = ST.query(1, ST.RS);
	}

	return ans;
}

#ifndef ONLINE_JUDGE
int main(){
	auto out = countScans({1, 2, 3, 4}, {0, 2}, {3, 1});
	for(int i: out)
		print(i);
}
#endif