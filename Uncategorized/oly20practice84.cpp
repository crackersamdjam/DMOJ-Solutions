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
const int MM = 105;

int dp[MM][MM], n, m, a[MM], ans;

int go(int l, int r){
	if(l > r)
		return 0;
	if(~dp[l][r])
		return dp[l][r];
	int cnt = m-(r-l+1)+1;
	return dp[l][r] = max(go(l, r-1) + a[r]*cnt, go(l+1, r) + a[l]*cnt);
}

int main(){
	scan(n, m);
	while(n--){
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < m; i++)
			scan(a[i]);
		ans += go(0, m-1);
	}
	print(ans);
}