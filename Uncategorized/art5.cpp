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
const int MM = 2005;

int n, x[MM], y[MM], ax, ay, bx, by;
int dp[MM][MM];

int main(){
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	scan(n, ax, ay, bx, by);
	for(int i = 1; i <= n; i++){
		scan(x[i], y[i]);

		dp[i][i-1] = dp[0][i-1] + abs(x[i]-bx) + abs(y[i]-by);
		dp[i-1][i] = dp[i-1][0] + abs(x[i]-ax) + abs(y[i]-ay);

		for(int j = 0; j < i; j++){
			//same
			if(j < i-1){
				dp[j][i] = min(dp[j][i], dp[j][i-1] + abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]));
				dp[i][j] = min(dp[i][j], dp[i-1][j] + abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]));
			}
			//diff
			if(j){
				dp[i-1][i] = min(dp[i-1][i], dp[j][i-1] + abs(x[i]-x[j]) + abs(y[i]-y[j]));
				dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + abs(x[i]-x[j]) + abs(y[i]-y[j]));
			}
		}
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++)
		ans = min(ans, min(dp[i][n], dp[n][i]));
	print(ans);

	// for(int i = 0; i <= n; i++){
		// for(int j = 0; j <= n; j++)
			// cout<<dp[i][j]<<' ';
		// cout<<'\n';
	// }
}