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
#define f first
#define s second

using namespace std;
using T = pair<int, int>;
const int MM = 2e5+5, mod = 30013;

struct node{
	T val;
};

struct segtree{
	node tree[MM*4];
	const T DEF = {0, 0};
	int LS, RS;
	
	inline T merge(T va, T vb){
		if(va.f < vb.f)
			swap(va, vb);
		return {va.f, (va.s + (va.f == vb.f)*vb.s)%mod};
	}
	
	inline void pull(int rt){
		tree[rt].val = merge(tree[lc].val, tree[rc].val);
	}
	
	void build(int _LS, int _RS){ build(LS = _LS, RS = _RS, 1); }
	void build(int nl, int nr, int rt){
		tree[rt].val = DEF;
		if(nl == nr) return; build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	void update(int l, T v){ update(l, v, LS, RS, 1); }
	void update(int l, T v, int nl, int nr, int rt){
		if(l < nl || l > nr) return;
		if(nl == nr){
			tree[rt].val = merge(tree[rt].val, v);
			return;
		}
		update(l, v, nl, nm, lc); update(l, v, nm+1, nr, rc); pull(rt);
	}
	
	T query(int l, int r){ return query(l, r, LS, RS, 1); }
	T query(int l, int r, int nl, int nr, int rt){
		if(r < nl || l > nr) return DEF;
		if(l <= nl && r >= nr) return tree[rt].val;
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST;

int n;
T dp[MM];
struct sc{
	int a, b, c, d, i;
} a[MM];

struct cmp{
	bool operator()(const sc &x, const sc &y) const{
		return x.b > y.b; //pq high first
	};
};
priority_queue<sc, vector<sc>, cmp> st;
map<int, int> mp;
int x;

int main(){
	scan(n);
	for(int i = 0; i < n; i++){
		scan(a[i].a, a[i].b, a[i].c, a[i].d);
		mp[a[i].c] = mp[a[i].d] = 0;
	}
	for(auto &i: mp)
		i.second = ++x;
	sort(a, a+n, [](const sc &x, const sc &y){
		return x.a < y.a;
	});
	ST.LS = 0, ST.RS = x;
	ST.update(0, {0, 1});
	for(int i = 0; i < n; i++){
		auto &p = a[i];
		p.i = i;
		p.c = mp[p.c];
		p.d = mp[p.d];
		while(size(st) and st.top().b < p.a){
			auto rm = st.top(); st.pop();
			ST.update(rm.d, dp[rm.i]);
		}
		dp[i] = ST.query(0, p.c-1);
		dp[i].f++;
		st.emplace(p);
	}
	while(size(st)){
		auto rm = st.top(); st.pop();
		ST.update(rm.d, dp[rm.i]);
	}
	auto ans = ST.query(0, x);
	print(ans.f, ans.s);
}