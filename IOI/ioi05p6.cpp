#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int n, K;
int dp[101][101][51];
int sz[101];
vector<pair<int, int>> adj[101];
int dis[101];
int tot;

vector<int> in;

void dfs(int cur, int pre){
	in.emplace_back(cur);

	for(auto [u, w]: adj[cur]){
		if(u == pre) continue;

		dis[u] = dis[cur]+w;
		dfs(u, cur);
		sz[cur] += sz[u];
		tot += sz[u]*w;

		for(int j: in){
			for(int k = min(K, sz[cur]); k >= 0; k--){
				for(int kk = 0; kk <= min(k, sz[u]); kk++){
					dp[cur][j][k] = max(dp[cur][j][k], dp[cur][j][k-kk]+dp[u][j][kk]);
				}
			}
		}
	}

	for(int j: in){
		for(int k = min(K, sz[cur]); k > 0; k--){
			dp[cur][j][k] = max(dp[cur][j][k], dp[cur][cur][k-1] + (dis[cur]-dis[j])*sz[cur]);
		}
	}

	in.pop_back();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	cin>>n>>K;
	for(int i = 1,p,d; i <= n; i++){
		cin>>sz[i]>>p>>d;
		adj[p].emplace_back(i, d);
	}
	dfs(0, 0);
	cout<<tot-dp[0][0][K]<<'\n';
}