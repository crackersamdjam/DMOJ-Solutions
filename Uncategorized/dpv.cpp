#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n;
vector<int> adj[MM];
ll mod, dp[MM], dpup[MM], ans[MM];

void dfs(int cur, int pre){
	dp[cur] = 1;
	dpup[cur] = 1;
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		dfs(u, cur);
		dp[cur] = dp[cur]*(dp[u]+1)%mod;
	}
}

void dfs2(int cur, int pre){
	ans[cur] = dpup[cur]*dp[cur]%mod;
	ll sum = dpup[cur];
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		dpup[u] = dpup[u]*sum%mod;
		sum = sum*(dp[u]+1)%mod;
	}

	reverse(all(adj[cur]));
	sum = 1;
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		dpup[u] = dpup[u]*sum%mod;
		sum = sum*(dp[u]+1)%mod;
	}
	
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		dpup[u]++;
		dfs2(u, cur);
	}
}

int main(){
	scan(n, mod);
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1, 0);
	dfs2(1, 0);
	for(int i = 1; i <= n; i++)
		print(ans[i]);
}