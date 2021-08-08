#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> int size(const T &x){return int(x.size());}
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1005;

vector<int> adj[MM];
int n, m, q, c[MM], sz[MM];
bool vis[MM];
ll dp[MM][MM][3];
ll req[MM];

// inline void minn(ll &x, ll y){
// 	if(y < x) x = y;
// }
#define minn(x, y) (x) = min((x), (y))

int go(int cur, int pre){
	vis[cur] = 1;
	sz[cur] = 1;
	dp[cur][0][0] = 0;
	dp[cur][0][1] = c[cur];

	for(int u: adj[cur]){
		if(u == pre) continue;
		sz[cur] += go(u, cur);
		for(int i = sz[cur]; i >= 0; i--){
			for(int j = 0; j <= min(i, sz[u]); j++){
			// for(int j = min(i, sz[u]); j >= 0; j--){
				minn(dp[cur][i][0], dp[cur][i-j][0] + dp[u][j][0]);
				minn(dp[cur][i][0], dp[cur][i-j][0] + dp[u][j][1]);
				minn(dp[cur][i][0], dp[cur][i-j][0] + dp[u][j][2]);
				minn(dp[cur][i][1], dp[cur][i-j][1] + dp[u][j][0]);
				if(i-j-2 >= 0) minn(dp[cur][i][2], dp[cur][i-j-2][1] + dp[u][j][1]);
				if(i-j-1 >= 0) minn(dp[cur][i][2], dp[cur][i-j-1][1] + dp[u][j][2]);

				minn(dp[cur][i][2], dp[cur][i-j][2] + dp[u][j][0]);
				if(i-j-1 >= 0) minn(dp[cur][i][2], dp[cur][i-j-1][2] + dp[u][j][1]);
				minn(dp[cur][i][2], dp[cur][i-j][2] + dp[u][j][2]);
			}
		}
	}
	return sz[cur];
}


int main(){
	memset(dp, 0x3f, sizeof dp);
	memset(req, 0x3f, sizeof req);
	req[0] = 0;
	scan(n, m);
	for(int i = 1; i <= n; i++)
		scan(c[i]);
	for(int i = 0,a,b; i < m; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	int tot = 0;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			go(i, 0);
			tot += sz[i];
			for(int j = tot; j >= 0; j--){
				for(int k = 0; k <= min(j, sz[i]); k++){
					ll cost = min({dp[i][k][0], dp[i][k][1], dp[i][k][2]});
					req[j] = min(req[j], req[j-k] + cost);
				}
			}
		}
	}
	for(int i = n-1; i >= 0; i--)
		req[i] = min(req[i], req[i+1]);

	scan(q);
	while(q--){
		ll v;
		scan(v);
		print(upper_bound(req, req+n+1, v)-req-1);
	}
}