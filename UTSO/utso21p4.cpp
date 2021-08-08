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
const int MM = 2e5+5;

int n, m;
vector<pair<int, int>> adj[MM];
bool vis[MM], cnt[MM], take[MM];
int taken;

void dfs(int cur, int pre){
	vis[cur] = 1;
	for(auto [u, id]: adj[cur]){
		if(!vis[u]){
			dfs(u, cur);
			if(!cnt[u]){
				cnt[u] ^= 1;
				cnt[cur] ^= 1;
				take[id] = 1;
				taken++;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0,a,b; i < m; i++){
		cin>>a>>b;
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i, 0);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += cnt[i];
	
	cout<<ans<<'\n';
	cout<<m-taken<<'\n';
	for(int i = 0; i < m; i++){
		if(!take[i])
			cout<<i+1<<' ';
	}
}