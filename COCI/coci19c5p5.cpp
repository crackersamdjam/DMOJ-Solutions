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
const ll mod = 1e9+7;
const int MM = 355;

void add(ll &a, ll b){
	a += b;
	if(a >= mod)
		a -= mod;
}

int n;
ll dp[MM][MM][2], C[MM][MM];

int main(){
	scan(n);
	C[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			C[i][j] = C[i-1][j];
			if(j)
				add(C[i][j], C[i-1][j-1]);
		}
	}
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			for(int k = 0; j+k <= n; k++){
				ll m = C[j+k][k];
				if(k != i){
					add(dp[i][j+k][0], dp[i-1][j][0]*m%mod);
					add(dp[i][j+k][1], dp[i-1][j][1]*m%mod);
				}
				else{
					add(dp[i][j+k][1], dp[i-1][j][0]*m%mod);
					add(dp[i][j+k][1], dp[i-1][j][1]*m%mod);
				}
			}
		}
	}
	print(dp[n][n][1]);
}