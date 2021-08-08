#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define u e.first
#define w e.second
#define f first
#define s second

using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int MM = 3e5+5;

int n, k;
vector<pair<int, int>> adj[MM];
pii dp[MM][3];
ll ans;

pii operator +(const pii a, const pii b){
	return {a.f+b.f, a.s+b.s};
}

void dfs(int cur, int pre, ll c){
	dp[cur][0] = {0, 0};
	dp[cur][1] = {-c, -1};
	dp[cur][2] = {-1e12, 0};
	for(auto e: adj[cur]){
		if(u == pre) continue;
		dfs(u, cur, c);
		pii sa = max(dp[u][0], max(dp[u][1], dp[u][2]));
		dp[cur][2] = max(dp[cur][2]+sa, dp[cur][1]+dp[u][1] + pii(c, 1) + pii(w, 0));
		dp[cur][1] = max(dp[cur][1]+sa, dp[cur][0]+dp[u][1] + pii(w, 0));
		dp[cur][0] = dp[cur][0]+sa;
	}
}

int main(){
	scan(n, k);
	for(int i = 0,a,b; i < n-1; i++){
		ll c; scan(a, b, c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	ll l = -1e8, m, r = 1e8;
	while(l <= r){
		m = l + (r-l)/2;
		dfs(1, 0, m);
		auto res = max({dp[1][0], dp[1][1], dp[1][2]});
		if(-res.s <= k+1)
			r = m-1;
		else
			l = m+1;
	}
	dfs(1, 0, l);
	auto res = max({dp[1][0], dp[1][1], dp[1][2]});
	print(res.f + (k+1)*l);
}