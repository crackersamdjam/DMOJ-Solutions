#ifndef LOCAL
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("avx2")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
constexpr int MM = 1e5+5, SQ = 1200;

struct query{
	int op, id, w, i;
} q[MM];

struct edge{
	int a, b, c;
} e[MM];

int n, m, qq, ans[MM];
int par[MM], sz[MM];

inline int find(int x){
	while(x != par[x])
		x = par[x];
	return x;
}

vector<pair<int, int>> rm;
bool change[MM];
vector<int> add[MM];

inline void merge(int a, int b, bool undo){
	int fa = find(a), fb = find(b);
	if(fa != fb){
		if(sz[fa] < sz[fb])
			swap(fa, fb);
		par[fb] = fa;
		sz[fa] += sz[fb];
		if(undo)
			rm.emplace_back(fa, fb);
	}
}
// maybe try "partial compression" to speed up

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		cin>>e[i].a>>e[i].b>>e[i].c;
	}
	cin>>qq;
	for(int i = 0; i < qq; i++){
		cin>>q[i].op>>q[i].id>>q[i].w;
		q[i].i = i;
	}
	for(int l = 0; l < qq; l += SQ){
		int r = min(l+SQ, qq);
		iota(par, par+n+1, 0);
		fill(sz, sz+n+1, 1);
		fill(change, change+m+1, 0);

		vector<int> qu, changes, same;
		for(int i = l; i < r; i++){
			if(q[i].op == 1){
				change[q[i].id] = 1;
				changes.emplace_back(q[i].id);
			}
			else{
				qu.emplace_back(i);
			}
		}

		changes.erase(unique(changes.begin(), changes.end()), changes.end());

		for(int i = 1; i <= m; i++){
			if(!change[i]){
				same.emplace_back(i);
			}
		}

		for(int i = l; i < r; i++){
			if(q[i].op == 1){
				e[q[i].id].c = q[i].w;
				// permanently update edge w
			}
			else{
				for(int eid: changes){
					// out of those that need to change, get existed req
					// changes was made unique earlier, so no redos
					if(e[eid].c >= q[i].w){
						add[i].emplace_back(eid);
					}
				}
			}
		}

		sort(all(qu), [&](auto x, auto y){
			return q[x].w > q[y].w;
		});
		sort(all(same), [&](auto x, auto y){
			return e[x].c < e[y].c;
		});

		for(int i: qu){
			while(size(same) and e[same.back()].c >= q[i].w){
				int eid = same.back(); same.pop_back();
				merge(e[eid].a, e[eid].b, 0);
			}

			for(auto eid: add[i]){
				merge(e[eid].a, e[eid].b, 1);
			}

			ans[q[i].i] = sz[find(q[i].id)];

			while(size(rm)){
				auto [a, b] = rm.back(); rm.pop_back();
				par[b] = b;
				sz[a] -= sz[b];
			}
		}
	}

	for(int i = 0; i < qq; i++){
		if(ans[i])
			cout<<ans[i]<<'\n';
	}
}