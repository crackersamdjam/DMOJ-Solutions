#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int constexpr MM = 3e5+5;

int n, m, mx[MM];
vector<int> adj[MM];

void dfs(int cur, int id){
	if(mx[cur]) return;
	mx[cur] = id;
	for(int u: adj[cur])
		dfs(u, id);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	for(int i = 0,a,b; i < m; i++){
		cin>>a>>b;
		adj[b].emplace_back(a);
	}
	for(int i = n; i; i--)
		dfs(i, i);
	for(int i = n; i; i--){
		int j = mx[i];
		if(i < j)
			return cout<<i<<' '<<j<<'\n', 0;
	}
	cout<<"-1\n";
}