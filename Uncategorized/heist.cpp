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
const int MM = 1e5+40;

int t, n, k, a[MM];
ll dp[MM][31];

int main(){
	scan(t);
	while(t--){
		ll ans = 0, sum = 0;
		scan(n, k);
		for(int i = 1; i <= n; i++){
			scan(a[i]);
			sum += max(a[i], 0);
		}
		for(int i = n+1; i <= n+k; i++)
			a[i] = a[i-n];

		if(k == n){
			print(sum);
			continue;
		}

		for(int off = 0; off <= k; off++){
			memset(dp[off], 0, sizeof dp[off]);
			for(int i = off+1; i <= off+n; i++){
				dp[i][0] = dp[i-1][0];
				for(int j = 1; j <= k; j++){
					dp[i][j] = dp[i-1][j-1]+a[i];
					dp[i][0] = max(dp[i][0], dp[i-1][j]);
				}
			}
			//force last one to be off
			ans = max(ans, dp[off+n][0]);
		}
		print(ans);
	}
}