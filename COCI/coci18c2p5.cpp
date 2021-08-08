#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll;
typedef long long T;
constexpr int MM = 2e5;

int t;

struct node{
	T val, lp;
	int sz;
	inline void apply(T v){
		val += v*sz;
		lp += v;
	}
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
#define LS 1
#define RS t
	node tree[MM*3];
	const T DEF = 0;
	//default value
	
	inline T merge(T va, T vb){
		return va+vb;
	}
	
	inline void pull(int rt){
		tree[rt].val = merge(tree[lc].val, tree[rc].val);
	}
	
	// node with lazy val means yet to push to children (but updated itself)
	inline void push(int rt, int nl, int nr){
		if(nl != nr){
			tree[lc].apply(tree[rt].lp);
			tree[rc].apply(tree[rt].lp);
		}
		tree[rt].lp = 0;
	}
	
	void build(int l, int r, int rt){
		int nl = l, nr = r;
		tree[rt].sz = r-l+1;
		if(l == r)
			return;
		build(l, nm, lc);
		build(nm+1, r, rc);
		pull(rt);
	}
	
	void build(){
		build(LS, RS, 1);
	}
	
	void update(int l, int r, T val, int nl, int nr, int rt){
		if(r < nl || l > nr)
			return;
		if(l <= nl && r >= nr){
			tree[rt].apply(val);
			return;
		}
		push(rt, nl, nr);
		update(l, r, val, nl, nm, lc);
		update(l, r, val, nm+1, nr, rc);
		pull(rt);
	}
	
	void update(int l, int r, T val){
		update(l, r, val, LS, RS, 1);
	}
		
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr)
			return DEF;
		if(l <= nl && r >= nr)
			return tree[rt].val;
		push(rt, nl, nr);
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
	
	T query(int l, int r){
		return query(l, r, LS, RS, 1);
	}
#undef lc
#undef rc
#undef nm
} ST, ST2;

int n;
int lx[MM], ly[MM], rx[MM], ry[MM];
std::map<int, int> mp;
bool no[MM];
T cnt[MM];

struct st{
	int op, x, l, r, v, id; //0 ins, 1, query, 2 del
	bool operator<(const st &o) const{
		if(x == o.x){
			if(op == o.op)
				return v < o.v; ///reeeeeeeee
			return op < o.op;
		}
		return x < o.x;
	}
};
std::vector<st> q;

void go(int l, int r){
	int m = (l+r)/2;

	if(l < r){
		go(l, m);
		go(m+1, r);
	}

	q.clear();
	for(int i = m+1; i <= r; i++){
		q.push_back({0, lx[i], ly[i], ry[i], 1, -1});
		q.push_back({2, rx[i], ly[i], ry[i], -1, -1});
	}
	for(int i = l; i <= m; i++){
		q.push_back({1, lx[i], ly[i], ry[i], -1, i});
		q.push_back({1, rx[i], ly[i], ry[i], 1, i});
	}

	sort(all(q));
	for(const auto i: q){
		if(i.op == 1){
			if(ST.query(i.l, i.r)) //partial
				no[i.id] = 1;
			cnt[i.id] += i.v*ST2.query(i.l, i.r); //complete
			if(i.v == 1 and cnt[i.id])
				no[i.id] = 1;
		}
		else if(i.op == 0){
			ST.update(i.l, i.r, 1);
			ST2.update(i.l, i.r, 1);
		}
		else if(i.op == 2){
			ST.update(i.l, i.r, -1);
		}
	}
	for(const auto i: q){
		if(i.op == 0)
			ST2.update(i.l, i.r, -1);
	}
}

int main(){
	scan(n);
	for(int i = 0; i < n; i++){
		scan(lx[i], ly[i], rx[i], ry[i]);
		lx[i]++, ly[i]++;
		rx[i] += lx[i]-1, ry[i] += ly[i]-1;
		mp[ly[i]] = mp[ry[i]] = 0;
	}
	for(auto &i: mp)
		i.second = ++t;

	ST.build();
	ST2.build();

	for(int i = 0; i < n; i++)
		ly[i] = mp[ly[i]], ry[i] = mp[ry[i]];

	go(0, n-1);

	for(int i = 0; i < n; i++){
		printf(no[i] ? "NE\n" : "DA\n");
	}
}
/*
overlap
partial: linesweep with query at insert/delete points of old rect
complete: sum of (lx, [ly, ry]) < sum (rx, [ly, ry])

cdq split to know who came first = below/above

*/