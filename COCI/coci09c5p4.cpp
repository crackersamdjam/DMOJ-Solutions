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
const int MM = 105;

int n, k, a[MM], dp[MM][MM][6];
// dp[l][r][c] = cost to make [l, r] have c a[l]s

int main(){
	scan(n, k);
	for(int i = 0; i < n; i++)
		scan(a[i]);

	memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i < n; i++){
		dp[i][i][1] = 0;
		dp[i][i-1][0] = 0;
	}

	for(int len = 1; len <= n; len++){
		for(int l = 0; l+len-1 < n; l++){
			int r = l+len-1;

			for(int i = l+1; i <= r; i++){
				for(int lc = 0; lc <= k; lc++){
					if(a[l] == a[i]){
						for(int rc = 0; rc <= k; rc++){
							int tc = min(k, lc+rc);
							dp[l][r][tc] = min(dp[l][r][tc], dp[l][i-1][lc] + dp[i][r][rc]);
						}
					}
					else{
						dp[l][r][lc] = min(dp[l][r][lc], dp[l][i-1][lc] + dp[i][r][0]);
					}
				}
			}

			for(int c = 1; c <= k; c++)
				dp[l][r][c] = min(dp[l][r][c], dp[l][r][c-1]+1);

			dp[l][r][0] = min(dp[l][r][0], dp[l][r][k]);
		}
	}

	print(dp[0][n-1][0]);
}