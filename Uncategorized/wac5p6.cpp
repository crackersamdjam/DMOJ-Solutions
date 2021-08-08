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
using ll = long long;
const int MM = 3e5+5, LOG = 18;

struct edge{
	int u, w1, w2, id;
};
vector<edge> adj2[MM];

ll dif[MM];
int n, m, k, q, id[MM];
int dep[MM], sp[LOG][MM], dep1[MM], sp1[LOG][MM];
vector<int> adj[MM], in[MM];
int ina[MM], inb[MM];
bool used[MM]; //used its par edge

void dfs1(int cur, int pre){
	dep1[cur] = dep1[pre]+1;
	sp1[0][cur] = pre;
	for(int u: adj[cur]){
		if(u != pre)
			dfs1(u, cur);
	}
}
void dfs2(int cur, int pre){
	dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	for(auto e: adj2[cur]){
		int u = e.u;
		if(u != pre)
			dfs2(u, cur);
	}
}
int treelca(int u, int v){
	if(dep1[u] < dep1[v])
		swap(u, v);
	for(int i = LOG-1; i >= 0; i--){
		if(~sp1[i][u] && dep1[sp1[i][u]] >= dep1[v])
			u = sp1[i][u];
	}
	if(u == v)
		return u;
	for(int i = LOG-1; i >= 0; i--){
		if(~sp1[i][u] && ~sp1[i][v] && sp1[i][u] != sp1[i][v]){
			u = sp1[i][u];
			v = sp1[i][v];
		}
	}
	return sp1[0][u];
}
int treedist(int a, int b){
	return dep1[a]+dep1[b]-2*dep1[treelca(a, b)];
}
int getlca(int u, int v){
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] && dep[sp[i][u]] >= dep[v])
			u = sp[i][u];
	}
	if(u == v)
		return u;
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] && ~sp[i][v] && sp[i][u] != sp[i][v]){
			u = sp[i][u];
			v = sp[i][v];
		}
	}
	return sp[0][u];
}

ll tot, sum[MM];
vector<ll> best;

void prop(int cur, int pre){
	for(auto e: adj2[cur]){
		int u = e.u;
		if(u != pre){
			prop(u, cur);
			dif[cur] += dif[u];
			sum[e.id] += (ll)max(0, e.w1-e.w2)*dif[u];
		}
	}
}

int main(){
	memset(sp1, -1, sizeof sp1);
	memset(sp, -1, sizeof sp);
	scan(n, m, k, q);
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs1(1, 0); //init tree
	for(int i = 1; i < LOG; i++)
		for(int j = 1; j <= n; j++)
			if(~sp1[i-1][j]) sp1[i][j] = sp1[i-1][sp1[i-1][j]];

	int t = n;
	for(int i = 1,a,b; i <= m; i++){
		scan(a, b);
		ina[i] = a, inb[i] = b;
		int lca = treelca(a, b);

		int ta = a, tb = b;
		vector<int> ls, rs;
		while(ta != lca){
			ls.emplace_back(ta);
			ta = sp1[0][ta];
		}
		while(tb != lca){
			rs.emplace_back(tb);
			tb = sp1[0][tb];
		}
		reverse(all(ls));
		reverse(all(rs));

		t++; //dummy
		adj2[lca].push_back({t, 0, 0, 0});
		id[t] = i;

		for(int j = 0; j < (int)ls.size(); j++){
			int d1 = j+1, d2 = (int)rs.size()+(int)ls.size()-j;
			adj2[t].push_back({ls[j], d1, d2, i});
			used[ls[j]] = 1;
		}
		for(int j = 0; j < (int)rs.size(); j++){
			int d1 = j+1, d2 = (int)rs.size()+(int)ls.size()-j;
			adj2[t].push_back({rs[j], d1, d2, i});
			// ida[rs[j]] = a, idb[rs[j]] = b, id[rs[j]] = i;
			used[rs[j]] = 1;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int u: adj[i])
			if(dep1[i] < dep1[u] and !used[u])
				adj2[i].push_back({u, 0, 0, 0});

	dfs2(1, 0);
	for(int i = 1; i < LOG; i++)
		for(int j = 1; j <= n+t; j++)
			if(~sp[i-1][j]) sp[i][j] = sp[i-1][sp[i-1][j]];

	int a, b;
	while(q--){
		scan(a, b);
		if(a == b) continue;
		int lca = getlca(a, b);
		tot += treedist(a, b);
		dif[a]++, dif[b]++;

		if(lca > n){
			int ta = a, tb = b;
			for(int i = LOG-1; i >= 0; i--){
				if(dep[ta]-(1<<i) > dep[lca])
					ta = sp[i][ta];
				if(dep[tb]-(1<<i) > dep[lca])
					tb = sp[i][tb];
			}
			dif[ta]--, dif[tb]--;

			int ma = ina[id[lca]], mb = inb[id[lca]];
			int d = treedist(a, b) - (1 + min(treedist(a, ma) + treedist(b, mb),
				treedist(a, mb) + treedist(b, ma)));
			d = max(d, 0);
			sum[id[lca]] += d;
		}
		else{
			dif[lca] -= 2;
		}
	}

	prop(1, 0);

	for(int i = 1; i <= m; i++)
		best.emplace_back(sum[i]);
	sort(all(best), greater<ll>());
	for(int i = 0; i < k; i++)
		tot -= best[i];

	print(tot);
}