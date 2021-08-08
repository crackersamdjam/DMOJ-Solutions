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
const int MM = 4e5+5;

int n, q;
ll a[MM], sum;
ll dp[MM];

int main(){
	scan(n, q);
	for(int i = 1; i <= n; i++)
		scan(a[i]);
	for(int i = n+1; i <= n+q; i++)
		scan(a[i]);

	if(n == 1)
		print(a[1]);

	sum = a[1];
	for(int i = 2; i <= n+q; i++){
		sum += a[i];
		dp[i] = max(dp[i-1], dp[i-2]+min(a[i], a[i-1]));
		if(i >= n)
			print(sum-dp[i]);
	}
}