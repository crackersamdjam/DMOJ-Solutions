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
const int MM = 4e5+5;

int n, m, k, tot, dp[MM], ans = INT_MAX;

int main(){
	scan(n, m, k);
	for(int i = 0,a; i < n; i++){
		scan(a);
		tot += a;
		if(a < k){
			puts("Impossible");
			exit(0);
		}
	}
	memset(dp, -0x3f, sizeof dp);
	dp[0] = 0;
	for(int i = 0,b; i < m; i++){
		scan(b);
		int add = min(b, n);
		for(int j = MM-1; j >= b; j--){
			dp[j] = max(dp[j], dp[j-b]+add);
		}
		for(int j = 0; j < MM; j++){
			if(j >= tot and dp[j] >= n*k)
				ans = min(ans, j-tot);
		}
	}
	if(ans == INT_MAX)
		puts("Impossible");
	else
		print(ans);
}