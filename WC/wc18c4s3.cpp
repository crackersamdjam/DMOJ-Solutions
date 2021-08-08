#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 3e5+5;

int n, m;
vector<int> adj[MM];
int d[MM], c[MM];
bool vis[MM];
int last[MM];
ll cnt[MM];
ll ans;

void dfs(int cur, int rt, int len, int dep, int &mx){
	vis[cur] = 1;
	cnt[dep%len] += c[cur];
	mx = max(mx, dep);
	for(int u: adj[cur]){
		if(u != rt){
			dfs(u, rt, len, dep+1, mx);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>d[i];
		adj[d[i]].emplace_back(i);
	}
	while(m--){
		int a; cin>>a;
		c[a]++;
	}

	vis[0] = 1;
	for(int a: adj[0]){
		int mx = 0;
		dfs(a, a, 1e9, 0, mx);
		for(int j = 0; j <= mx; j++){
			ans += cnt[j]*(cnt[j]-1)/2;
			cnt[j] = 0;
		}
	}

	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		int len = 0;
		int a = i;
		while(!vis[a]){
			last[a] = len++;
			vis[a] = 1;
			a = d[a];
		}
		len -= last[a];

		int mx = 0;
		dfs(a, a, len, 0, mx);

		for(int j = 0; j <= mx; j++){
			ans += cnt[j]*(cnt[j]-1)/2;
			cnt[j] = 0;
		}
	}
	cout<<ans<<'\n';
}