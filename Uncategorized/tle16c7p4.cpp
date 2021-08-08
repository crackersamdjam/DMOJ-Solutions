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

int main(){
	int t; ll x;
	scan(t);
	while(t--){
		scan(x);
		int n = (int)__lg(x)+1;
		vector<vector<int>> dp(2, vector<int>(n+1, 99));
		vector<bool> a(n+1);
		dp[0][n] = 0;
		dp[1][n] = 2; //on + extra shift

		for(int i = n-1; i >= 0; i--){
			a[i] = x&(1LL<<i);
			dp[0][i] = dp[a[i+1]][i+1];
			dp[1][i] = dp[a[i+1]][i+1]+1;
			for(int j = i+1; j <= n; j++){			
				if(a[j] == 0){
					dp[1][i] = min(dp[1][i], dp[1][j]+1);
					//"pop" that one bit to fill these
					break;
				}
			}
		}
		print(dp[a[0]][0]+n-1);
	}
}