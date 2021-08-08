#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

// #ifndef ONLINE_JUDGE
// template<typename T>
// void pr(T a){std::cerr<<a<<std::endl;}
// template<typename T,typename... Args>
// void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
// #else
// template<typename... Args>
// void pr(Args... args){}
// #endif

using namespace std;
const int MM = 5e5+9;

#define LSOne(S) (S & (-S))
typedef long long ll;
ll B1[MM], B2[MM];
ll query(ll* ft, int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}
ll query(int b) {
    return query(B1, b) * b - query(B2, b);
}
ll range_query(int i, int j)    {
    return query(j) - query(i - 1);
}
void update(ll* ft, int k, ll v) {
	for (; k <= MM-2; k += LSOne(k)) ft[k] += v;
}
void range_update(int i, int j, ll v)	{
	update(B1, i, v);
	update(B1, j + 1, -v);
	update(B2, i, v * (i - 1));
	update(B2, j + 1, -v * j);
}

int n, k, q, at[MM];
vector<int> adj[MM];
int par[MM], dep[MM], heavy[MM], head[MM], in[MM], out[MM], tt, nd[MM];
int pos[MM], ptr = 1;
int bit[MM];

void up(int i, int v){
	for(; i < MM ; i += i&-i)
		bit[i] += v;
}

int qu(int i){
	int v = 0;
	for(; i; i -= i&-i)
		v += bit[i];
	return v;
}

void dfs2(int cur){
	in[cur] = ++tt;
	nd[tt] = cur;
	for(int u: adj[cur]){
		if(u != par[cur])
			dfs2(u);
	}
	out[cur] = tt;
}

int dfs(int cur){
	int sz = 1, mx = 0;
	for (int u : adj[cur]){
		if(u == par[cur])
			continue;
		par[u] = cur;
		dep[u] = dep[cur]+1;
		int t = dfs(u);
		sz += t;
		if(t > mx)
			mx = t, heavy[cur] = u;
	}
	return sz;
}

void decompose(int cur, int h){
	head[cur] = h; pos[cur] = ++ptr;
	if(heavy[cur])
		decompose(heavy[cur], h);
	for(int u: adj[cur]){
		if(u != par[cur] && u != heavy[cur])
			decompose(u, u);
	}
}

int getlca(int a, int b) {
	while(head[a] != head[b]){
		if(dep[head[a]] < dep[head[b]])
			b = par[head[b]];
		else
			a = par[head[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

int query(int a, int b){
	ll res = 0;
	for(; head[a] != head[b]; b = par[head[b]]){
		if(dep[head[a]] > dep[head[b]])
			swap(a, b);
		int l = pos[head[b]], r = pos[b];
		// res += qu(r)-qu(l-1);
		res += range_query(l, r);
	}
	if(a != b){
		if(dep[a] > dep[b])
			swap(a, b);
		int l = pos[a]+1, r = pos[b];
		// res += qu(r)-qu(l-1);
		res += range_query(l, r);
	}
	return (int)res;
}

void update(int a, int b, int v){
	for(; head[a] != head[b]; b = par[head[b]]){
		if(dep[head[a]] > dep[head[b]])
			swap(a, b);
		int l = pos[head[b]], r = pos[b];
		// up(l, v);
		// up(r+1, -v);
		range_update(l, r, v);
	}
	if(a != b){
		if(dep[a] > dep[b])
			swap(a, b);
		int l = pos[a]+1, r = pos[b];
		// up(l, v);
		// up(r+1, -v);
		range_update(l, r, v);
	}
}


set<int> st[MM];

int main(){
	scan(n, k, q);
	for(int i = 1; i <= n; i++){
		scan(at[i]);
	}
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	adj[n+1].emplace_back(1);
	adj[1].emplace_back(n+1);
	adj[n+1].emplace_back(n+2);
	adj[n+2].emplace_back(n+1);
	dfs(n+1);
	decompose(n+1, n+1);
	dfs2(n+1);
	// ST.build();

	for(int i = 1; i <= k; i++){
		st[i].insert(in[n+2]);
		st[i].insert(in[n+1]);
	}

	for(int a = 1; a <= n; a++){
		// pr(in[a], out[a]);
		int i = at[a];
		st[i].insert(in[a]);
		auto it = st[i].lower_bound(in[a]);
		// pr("ins", in[a]);
		auto nx = it, pre = it;
		nx++, pre--;
		int ls = getlca(a, nd[*pre]);
		int rs = getlca(a, nd[*nx]);
		int u = dep[ls] > dep[rs] ? ls : rs;
		// pr(a, i, ",", *pre, *nx, "u", u);
		// up(in[a], 1);
		// up(out[a], -1);
		update(u, a, 1);
		// pr("up", u, a);
	}

	while(q--){
		int op, a;
		scan(op, a);
		if(op == 1){
			{	
				int i = at[a];
				auto it = st[i].lower_bound(in[a]);
				auto nx = it, pre = it;
				nx++, pre--;
				int ls = getlca(a, nd[*pre]);
				int rs = getlca(a, nd[*nx]);
				int u = dep[ls] > dep[rs] ? ls : rs;
				update(u, a, -1);
				st[i].erase(in[a]);
			}

			scan(at[a]);
			int i = at[a];
			st[i].insert(in[a]);
			auto it = st[i].lower_bound(in[a]);
			// pr("ins", in[a]);
			auto nx = it, pre = it;
			nx++, pre--;
			int ls = getlca(a, nd[*pre]);
			int rs = getlca(a, nd[*nx]);
			int u = dep[ls] > dep[rs] ? ls : rs;
			update(u, a, 1);
		}
		else{
			// print(par[a], a);
			int v = query(par[a], a);
			print(v);
		}
	}
}