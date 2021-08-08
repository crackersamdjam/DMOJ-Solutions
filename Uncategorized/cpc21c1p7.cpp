#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int constexpr MM = 5e5+5;

int ans;

int val[MM*8], cnt[MM*8];

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)/2)

void pull(int rt, int nl, int nr){
	if(cnt[rt])
		val[rt] = nr-nl+1;
	else
		val[rt] = val[lc] + val[rc];
}

void update(int l, int r, int x, int nl = 0, int nr = MM-2, int rt = 1){
	if(l > r) return;
	if(r < nl or nr < l) return;
	if(l <= nl and nr <= r){
		cnt[rt] += x;
		pull(rt, nl, nr);
		return;
	}
	update(l, r, x, nl, nm, lc);
	update(l, r, x, nm+1, nr, rc);
	pull(rt, nl, nr);
}

int n, qq, d;
vector<int> adj[MM];
vector<pair<int, int>> op[MM];

int incc[MM], outcc[MM], id[MM];
int inc[MM], outc[MM];
int par[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}

	queue<int> q;
	q.emplace(1);

	int t = 0;
	while(size(q)){
		int cur = q.front(); q.pop();
		int p = par[cur];
		int pp = par[par[cur]];
		id[cur] = ++t;
		if(!inc[p]) inc[p] = t;
		outc[p] = t;
		if(!incc[pp]) incc[pp] = t;
		outcc[pp] = t;

		for(int u: adj[cur]){
			if(u == par[cur]) continue;
			par[u] = cur;
			q.emplace(u);
		}
	}

	cin>>qq>>d;
	for(int i = 0,u,a,b; i < qq; i++){
		cin>>u>>a>>b;
		op[a].emplace_back(u, 1);
		op[b+1].emplace_back(u, -1);
	}

	for(int i = 1; i <= d; i++){
		for(auto [u, x]: op[i]){
			int l = incc[u], r = outcc[u];
			if(l){
				update(l, r, x);
			}
			int p = par[u];
			if(p){
				update(inc[p], id[u]-1, x);
				update(id[u]+1, outc[p], x);
			}
			if(p > 1){
				update(id[p], id[p], x);
			}
		}
		cout<<1+val[1]<<'\n';
	}
}