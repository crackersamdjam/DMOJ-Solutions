#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
constexpr int MM = 2e5+1, NN = 25001, SQ = 501;

int n, m, q;
int val[MM];
vector<int> adj[MM];
int in[MM], out[MM], t;
vector<int> nodes[MM], pos[MM];
int bid[MM];
vector<int> big;

int sub[MM];

int ans1[SQ][NN];
int ans2[NN][SQ];

void dfs(int cur, int pre){
	in[cur] = ++t;
	pos[val[cur]].emplace_back(t);
	for(auto u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
	out[cur] = t;
}

void go(int cur, int pre, int col, int sum){
	ans1[bid[col]][val[cur]] += sum;
	sub[cur] = val[cur] == col;
	for(auto u: adj[cur]){
		if(u != pre){
			go(u, cur, col, sum + (val[cur] == col));
			sub[cur] += sub[u];
		}
	}
	//do small to big and big to big
	ans2[val[cur]][bid[col]] += sub[cur];
}

int main(){
	cin>>n>>m>>q;
	cin>>val[1];
	nodes[val[1]].emplace_back(1);
	for(int i = 2,p; i <= n; i++){
		cin>>p>>val[i];
		adj[p].emplace_back(i);
		nodes[val[i]].emplace_back(i);
	}

	for(int i = 1; i <= m; i++){
		if(size(nodes[i]) >= SQ){
			bid[i] = size(big);
			big.emplace_back(i);
		}
		pos[i].reserve(size(nodes[i]));
	}

	dfs(1, 0);

	for(int i = 0; i < size(big); i++){
		go(1, 0, big[i], 0);
	}

	for(int i = 0,a,b; i < q; i++){
		cin>>a>>b;
		if(size(nodes[b]) >= SQ){
			cout<<ans2[a][bid[b]]<<'\n';
		}
		else if(size(nodes[a]) >= SQ){
			cout<<ans1[bid[a]][b]<<'\n';
		}
		else{
			int ret = 0;
			for(int j: nodes[a])
				ret += upper_bound(all(pos[b]), out[j]) - lower_bound(all(pos[b]), in[j]);
			cout<<ret<<'\n';
		}
		cout<<flush;
	}
}
/*
precompute big-small, small-small, small-big
brute force small-small
*/