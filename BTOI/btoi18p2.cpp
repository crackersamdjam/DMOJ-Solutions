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
const int MM = 2e5+5;

int n, k, r, a[MM];
vector<int> v[MM];
int dp[MM];

int main(){
	scan(n, k, r);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		v[a[i]].emplace_back(i);
		dp[i] = i+1;
	}
	while(r--){
		int b, c;
		scan(b, c);
		if(c > v[b].size()){
			puts("impossible");
			exit(0);
		}
		v[b].emplace_back(n+1);
		for(int i = 0; i < v[b].size(); i++){
			if(i >= c)
				dp[v[b][i]-1] = min(dp[v[b][i]-1], v[b][i-c]);
			else
				dp[v[b][i]-1] = -1;
		}
	}
	int ans = 1e9;
	dp[n+1] = 1e9;
	for(int i = n; i > 0; i--){
		dp[i] = min(dp[i], dp[i+1]);
		if(dp[i] > 0){
			ans = min(ans, i-dp[i]+1);
		}
	}
	if(ans <= n)
		print(ans);
	else
		puts("impossible");

	// for(int i = 1; i <= n; i++)
		// cout<<dp[i]<<' ';
}