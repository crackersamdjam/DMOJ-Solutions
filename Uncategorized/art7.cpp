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
const int MM = 1e5+5;
const ll mod = 1e9+7;

int n;
char s[MM];
ll dp[MM][2][2][2];
//dp[i][has 1][has 0 (after 1)][flag]

ll go(int i, int d1, int d0, int f){
	if(d0 < 0) return 0;
	if(i == n) return !d0 and !d1;
	ll &ret = dp[i][d1][d0][f];
	if(~ret) return ret;
	ret = 0;
	for(int j = 0; j <= (f ? s[i]-'0' : 9); j++){
		//assign this number
		//only count zero if taken one
		ret += go(i+1, max(0, d1-(j == 1)), d0-(!d1 and j == 0), f and (j == s[i]-'0'));
	}
	// print(i, d1, d0, f, ret);
	return ret %= mod;
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%s", s);
	n = strlen(s);
	print(go(0, 1, 1, 1));
}