#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef __int128 ll;
typedef __int128 T;
constexpr int MM = 6e5+9;
constexpr ll inf = LLONG_MAX;

struct st{
	int op, x, l, r; ll w;
	// 1 add 0 rm
	bool operator<(const st &o) const{
		if(x != o.x)
			return x < o.x;
		return op < o.op; //rm first
	}
};
vector<st> q;
map<ll, int> mp;
int R, C, N, M, k, t;
ll ans = -inf;

struct node{
	T val, lp;
	void apply(T v){
		val += v;
		lp += v;
	}
};

struct segtree{
#define LS 1
#define RS t
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
	node tree[MM*4];
	T DEF = 0;
	T merge(T va, T vb){ return max(va, vb);}
	void push_up(int rt){ tree[rt].val = merge(tree[lc].val, tree[rc].val); }
	void push_down(int rt, int nl, int nr){
		if(nl != nr){
			tree[lc].apply(tree[rt].lp);
			tree[rc].apply(tree[rt].lp);
		}
		tree[rt].lp = 0;
	}
	void build(int nl = LS, int nr = RS, int rt = 1){
		if(nl == nr){
			tree[rt].val = DEF;
			tree[rt].lp = 0;
			return;
		}
		build(nl, nm, lc);
		build(nm+1, nr, rc);
		push_up(rt);
	}
	void update(int l, int r, T val, int nl = LS, int nr = RS, int rt = 1){
		if(r < nl || l > nr)
			return;
		if(l <= nl && r >= nr){
			tree[rt].apply(val);
			return;
		}
		push_down(rt, nl, nr);
		update(l, r, val, nl, nm, lc);
		update(l, r, val, nm+1, nr, rc);
		push_up(rt);
	}
	T query(int l, int r, int nl = LS, int nr = RS, int rt = 1){
		if(r < nl || l > nr)
			return -inf;
		if(l <= nl && r >= nr)
			return tree[rt].val;
		push_down(rt, nl, nr);
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST;

int bound(int x){
	return max(min(x, M), C);
}

int main(){
	scan(R, C, N, M, k);
	while(k--){
		int a, b; ll w;
		scan(a, b, w);
		int l = max(C, b), r = min(M, b+C-1);
		assert(l <= r);
		mp[l] = mp[r] = 0;
		mp[bound(l-1)] = mp[bound(r-1)] = 0;
		mp[bound(l+1)] = mp[bound(r+1)] = 0;
		q.push_back({1, a, l, r, w});
		q.push_back({0, a+R, l, r, -w});
		q.push_back({1, a-1, C, C, 0});
		q.push_back({1, a+1, C, C, 0});
		q.push_back({1, a+R-1, C, C, 0});
		q.push_back({1, a+R+1, C, C, 0});
	}
	mp[C] = mp[M] = 0;
	for(auto &i: mp)
		i.second = ++t;
	
	q.push_back({0, -1, C, M, -inf});
	q.push_back({0, R, C, M, inf});
	q.push_back({0, N+1, C, M, -inf});
	sort(all(q));
	int last = -1;
	ST.build();
	
	for(auto &i: q){
		if(i.x > N){
			ans = max(ans, ST.query(LS, RS));
			break;
		}
		if(last >= R and (last != i.x))
			ans = max(ans, ST.query(LS, RS));
		last = i.x;
		ST.update(mp[i.l], mp[i.r], i.w);
	}
	print(ans);
}