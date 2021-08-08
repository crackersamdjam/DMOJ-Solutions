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
constexpr int MM = 1e5+1, LOG = 17;

int n, q, tot, sz[MM], a[MM], b[MM], dep[LOG][MM], in[LOG][MM], out[LOG][MM], t[LOG], centid[LOG][MM], parid[LOG][MM];
ll maxw, c[MM];
std::vector<std::pair<int, ll>> adj[MM];
bool vis[MM];

struct Combine {
	using Data = ll;
	using Lazy = ll;
	const Data qdef = 0;
	const Lazy ldef = 0;
	Data merge(const Data &l, const Data &r) const { return std::max(l, r); }
	Data applyLazy(const Data &l, const Lazy &r) const { return l + r; }
	Lazy getSegmentVal(const Lazy &v, int k) const { return v; }
	Lazy mergeLazy(const Lazy &l, const Lazy &r) const { return l + r; }
};
struct Combine2{
	using Data = std::pair<ll, ll>;
	using Lazy = std::pair<ll, ll>;
	const Data qdef = {0LL, 0LL};
	Data merge(const Data &l, const Data &r) const {
		if(l.first > r.first)
			return {l.first, std::max(l.second, r.first)};
		return {r.first, std::max(r.second, l.first)};
	}
	Data applyLazy(const Data &l, const Lazy &r) const {
		return r;
	}
};
template <class Combine> struct SegmentTreeLazyBottomUp {
	using Data = typename Combine::Data; using Lazy = typename Combine::Lazy;
	Combine C; int N, lgN; std::vector<Data> TR; std::vector<Lazy> LZ;
	void apply(int i, const Lazy &v, int k) {
		TR[i] = C.applyLazy(TR[i], C.getSegmentVal(v, k));
		if (i < N) LZ[i] = C.mergeLazy(LZ[i], v);
	}
	void pushup(int i) {
		for (int k = 2; i /= 2; k *= 2) {
			TR[i] = C.merge(TR[i * 2], TR[i * 2 + 1]);
			if (LZ[i] != C.ldef)
				TR[i] = C.applyLazy(TR[i], C.getSegmentVal(LZ[i], k));
		}
	}
	void propagate(int i) {
		int h = lgN + 1, k = 1 << lgN, ii = i >> h;
		for (; h > 0; ii = i >> --h, k /= 2) if (LZ[ii] != C.ldef) {
				apply(ii * 2, LZ[ii], k); apply(ii * 2 + 1, LZ[ii], k); LZ[ii] = C.ldef;
			}
	}
	void init(int n0, const Data vdef) {
		N = n0;
		lgN = std::__lg(N);
		TR = std::vector<Data>(N * 2, C.qdef);
		LZ = std::vector<Lazy>(N, C.ldef);
		fill(TR.begin() + N, TR.end(), vdef);
		for (int i = N - 1; i > 0; i--) TR[i] = C.merge(TR[i * 2], TR[i * 2 + 1]);
	}
	void update(int l, int r, const Lazy &v) {
		int l0 = l += N, r0 = r += N, k = 1; propagate(l); propagate(r);
		for (; l <= r; l /= 2, r /= 2, k *= 2) {
			if (l & 1) apply(l++, v, k);
			if (!(r & 1)) apply(r--, v, k);
		}
		pushup(l0); pushup(r0);
	}
	Data query(int l, int r) {
		propagate(l += N); propagate(r += N); Data ql = C.qdef, qr = C.qdef;
		for (; l <= r; l /= 2, r /= 2) {
			if (l & 1) ql = C.merge(ql, TR[l++]);
			if (!(r & 1)) qr = C.merge(TR[r--], qr);
		}
		return C.merge(ql, qr);
	}
};
template <class Combine> struct SegmentTreeBottomUp {
	using Data = typename Combine::Data; using Lazy = typename Combine::Lazy;
	Combine C; int N; std::vector<Data> TR;
	void init(int N0, const Data &vdef) {
		N = N0;
		TR = std::vector<Data>(N * 2, C.qdef);
		fill(TR.begin() + N, TR.end(), vdef);
		for (int i = N - 1; i > 0; i--)
			TR[i] = C.merge(TR[i * 2], TR[i * 2 + 1]);
	}
	void update(int i, const Lazy &v) {
		for (i += N, TR[i] = C.applyLazy(TR[i], v); i /= 2;)
			TR[i] = C.merge(TR[i * 2], TR[i * 2 + 1]);
	}
	Data query(int l, int r) {
		Data ql = C.qdef, qr = C.qdef;
		for (l += N, r += N; l <= r; l /= 2, r /= 2) {
			if (l & 1) ql = C.merge(ql, TR[l++]);
			if (!(r & 1)) qr = C.merge(TR[r--], qr);
		}
		return C.merge(ql, qr);
	}
};
SegmentTreeLazyBottomUp<Combine> ST[LOG];
SegmentTreeBottomUp<Combine2> BEST, CH[LOG];
//all best, ch for each centroid's ch

int getsz(int cur, int pre){
	sz[cur] = 1;
	for(auto e: adj[cur]){
		int u = e.first;
		if(u != pre && !vis[u])
			sz[cur] += getsz(u, cur);
	}
	return sz[cur];
}

int findcent(int cur, int pre){
	for(auto e: adj[cur]){
		int u = e.first;
		if(!vis[u] && u != pre && sz[u]*2 > tot)
			return findcent(u, cur);
	}
	return cur;
}

void dfs1(int cur, int pre, int lvl, int cent, ll w){
	in[lvl][cur] = ++t[lvl];
	dep[lvl][cur] = dep[lvl][pre]+1;
	centid[lvl][cur] = cent;
	parid[lvl][cur] = pre == cent ? cur : parid[lvl][pre];
	for(auto u: adj[cur]){
		if(u.first == pre || vis[u.first])
			continue;
		dfs1(u.first, cur, lvl, cent, u.second);
	}
	out[lvl][cur] = t[lvl];
	ST[lvl].update(in[lvl][cur], out[lvl][cur], w);
}

void go(int root, int lvl){
	getsz(root, -1);
	tot = sz[root];
	if(tot == 1)
		return;
	int cent = findcent(root, -1);
	vis[cent] = 1;
	
	dfs1(cent, 0, lvl, cent, 0);
	
	for(auto u: adj[cent]){
		if(vis[u.first])
			continue;
		int st = in[lvl][u.first], ed = out[lvl][u.first];
		ll v = ST[lvl].query(st, ed);
		CH[lvl].update(in[lvl][u.first], {v, 0LL});
	}
	
	auto tmp = CH[lvl].query(in[lvl][cent], out[lvl][cent]);
	BEST.update(cent, {tmp.first+tmp.second, 0LL});

	for(auto u: adj[cent]){
		if(!vis[u.first])
			go(u.first, lvl+1);
	}
}

int main(){
	scan(n, q, maxw);
	for(int i = 0; i < n-1; i++){
		scan(a[i], b[i], c[i]);
		adj[a[i]].emplace_back(b[i], c[i]);
		adj[b[i]].emplace_back(a[i], c[i]);
	}
	
	for(int i = 0; i < LOG; i++){
		ST[i].init(MM, 0);
		CH[i].init(MM, {0, 0});
	}
	BEST.init(MM, {0, 0});
	
	go(1, 0);
	
	ll d, e, last = 0;
	while(q--){
		scan(d, e);
		d = (d+last)%(n-1);
		e = (e+last)%maxw;
		int aa = a[d], bb = b[d];
		
		ll dif = e-c[d];
		c[d] = e;
		
		for(int i = 0; i < LOG; i++){
			int cent = centid[i][aa];
			if(cent and cent == centid[i][bb]){
				if(dep[i][aa] < dep[i][bb])
					std::swap(aa, bb);
				
				int par = parid[i][aa];
				
				ST[i].update(in[i][aa], out[i][aa], dif);
				ll v = ST[i].query(in[i][par], out[i][par]);
				CH[i].update(in[i][par], {v, 0LL});
				
				auto tmp = CH[i].query(in[i][cent], out[i][cent]);
				BEST.update(cent, {tmp.first+tmp.second, 0LL});
			}
		}
		print(last = BEST.query(0, MM-1).first);
	}
}
/*
 * ett each centroid
 * when update edge, loop through LOG levels
 * if for any lvl, there is a point where centid[lvl][a] == centid[lvl][b] != 0, then update the one with higher depth
 * then for its centid, remove old ans from multiset and insert new one
 *
 */