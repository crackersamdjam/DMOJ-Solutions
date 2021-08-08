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
const int MM = 305;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;

int n, m, k, sz[MM];
ll dp[MM][MM][2];
vector<pair<int, int>> adj[MM];

void dfs(int cur, int pre){
	sz[cur] = 1;
	dp[cur][1][0] = 0;
	dp[cur][0][1] = 0;

	for(auto [u, w]: adj[cur]){
		if(u == pre) continue;
		dfs(u, cur);
		sz[cur] += sz[u];
		for(int i = sz[cur]; i >= 0; i--){
			ll val[2] = {inf, inf};
			for(int j = 0; j <= i; j++){
				val[0] = min(val[0], dp[cur][i-j][0] + min(dp[u][j][1], dp[u][j][0]+w));
				val[1] = min(val[1], dp[cur][i-j][1] + min(dp[u][j][0], dp[u][j][1]+w*(m == 2)));
			}
			dp[cur][i][0] = val[0];
			dp[cur][i][1] = val[1];
		}
	}
}

int main(){
	scan(n, m, k);
	for(int i = 0,a,b,c; i < n-1; i++){
		scan(a, b, c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	if(k+m-1 > n){
		print(-1);
		return 0;
	}
	memset(dp, 0x3f, sizeof dp);

	dfs(1, 0);
	print(dp[1][k][0]);
}