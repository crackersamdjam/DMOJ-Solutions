#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

#ifndef ONLINE_JUDGE
void build(std::vector<std::vector<int>> b){
	// std::cout<<"build\n";
	// for(int i = 0; i < size(b); i++)
	// 	for(int j = 0; j < i; j++)
	// 		if(b[i][j])
	// 			std::cout<<i<<' '<<j<<'\n';
	// std::cout<<"done\n";
}
#endif

using namespace std;
const int MM = 1005;

int n, par[MM];
vector<int> in[MM];
bool done[MM];

vector<int> tt;
bool no;
set<int> ins;
vector<vector<int>> adj;
vector<int> adj2[MM];

void dfs(int cur){
	ins.insert(cur);
	tt[cur]++;
	if(tt[cur] > 3) no = 1;
	if(no) return;
	for(int u: adj2[cur]){
		if(!ins.count(u))
			dfs(u);
		if(no) return;
	}
	ins.erase(cur);
}

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

void add(int a, int b){
	adj[a][b] = adj[b][a] = 1;
	adj2[a].emplace_back(b);
	adj2[b].emplace_back(a);
}

int construct(vector<vector<int>> p){
	n = size(p);
	adj.resize(n);
	for(int i = 0; i < n; i++){
		par[i] = i;
		in[i].clear();
		in[i].emplace_back(i);
		adj[i].resize(n);
		fill(all(adj[i]), 0);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(p[i][j]){
				int a = find(i), b = find(j);
				if(a != b){
					par[b] = a;
					in[a].insert(in[a].end(), all(in[b]));
				}
			}
		}
	}
	for(int t = 0; t < n; t++){
		if(find(t) != t) continue;
		//at most one group of all 2s or all 3s
		vector<vector<int>> v;
		set<int> has;
		for(int a: in[t]){
			for(int b: in[t])
				has.insert(p[a][b]);
		}
		//if has 0, no

		for(int a: in[t]){
			if(done[a]) continue;
			done[a] = 1;
			v.emplace_back();
			v.back().emplace_back(a);
			for(int b: in[t]){
				if(b == a)
					continue;
				if(p[a][b] == 1){
					if(done[b]) return 0;
					done[b] = 1;
					v.back().emplace_back(b);
				}
			}
		}
		// pr(size(v));
		// for(auto &cur: v){
			// cerr<<"in ";
			// for(int i: cur)
				// cerr<<i<<' ';
			// cerr<<endl;
		// }

		for(int i = 1; i < size(v); i++){
			add(v[i-1][0], v[i][0]);
		}
		if(size(v) > 1){
			add(v[0][0], v.back()[0]);
		}
		if(has.count(3)){
			if(size(v) >= 4)
				add(v[0][0], v[2][0]);
			else
				return 0;
		}

		for(auto &cur: v){
			for(int i = 1; i < size(cur); i++){
				add(cur[i-1], cur[i]);
			}
		}
	}

	for(int i = 0; i < n; i++){
		sort(all(adj2[i]));
		adj2[i].erase(unique(adj2[i].begin(), adj2[i].end()), adj2[i].end());
	}

	//now test if correct
	for(int i = 0; i < n; i++){
		tt.resize(n);
		fill(all(tt), 0);
		ins.clear();
		dfs(i);
		if(no || tt != p[i]) return 0;
	}

	build(adj);
	return 1;
}