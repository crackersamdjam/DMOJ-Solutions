#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = __int128;
const int MM = 3e5+5;

int n, m, k, c[MM];
vector<int> adj[MM];
ll dp[MM][1<<5], ans;

ll go(int i, int mask){
	if(!(mask&(1<<c[i])))
		return 0;
	ll &ret = dp[i][mask];
	if(~ret) return ret;
	if((mask^(1<<c[i])) == 0)
		return 1;
	ret = 0;
	for(int u: adj[i]){
		ret += go(u, mask^(1<<c[i]));
	}
	// print(i, mask, ret);
	return ret;
}

int main(){
	memset(dp, -1, sizeof dp);
	scan(n, m, k);
	for(int i = 1; i <= n; i++){
		scan(c[i]);
		c[i]--;
	}
	for(int i = 0,a,b; i < m; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (1<<k); j++){
			if(__builtin_popcount(j) > 1)
				ans += go(i, j);
		}
	}
	print(ans);
}