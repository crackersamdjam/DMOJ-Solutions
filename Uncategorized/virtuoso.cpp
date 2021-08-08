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
using pii = pair<int, int>;
const int MM = 1e5+5;

pii operator+(pii a, int b){
	return {a.first+b, a.second};
}
pii operator+(pii a, pii b){
	return {a.first+b.first, a.second+b.second};
}

int n;
pair<int, int> dp[MM][7][3];

int main(){
	scan(n);
	memset(dp, 0x3f, sizeof dp);
	pii ans = dp[0][0][0];
	fill(&dp[0][0][0], &dp[1][0][0], pii(0, 0));

	for(int i = 1,k,l; i <= n; i++){
		scan(k);
		while(k--){
			scan(l);
			l--;
			if(i == 1){
				dp[i][l][0] = dp[i][l][1] = dp[i][l][2] = pii(0, 0);
				continue;
			}

			dp[i][l][0] = min({dp[i-1][l][0], dp[i-1][l][1]+pii(0, 1), dp[i-1][l][2]+pii(0, 1)});
			for(int j = 0; j < 7; j++){
				if(j < l)
					dp[i][l][1] = min({dp[i][l][1], dp[i-1][j][0]+pii(l-j, 1), dp[i-1][j][1]+pii(l-j, 0), dp[i-1][j][2]+pii(l-j, 1)});
				if(j > l)
					dp[i][l][2] = min({dp[i][l][2], dp[i-1][j][0]+pii(j-l, 1), dp[i-1][j][1]+pii(j-l, 1), dp[i-1][j][2]+pii(j-l, 0)});
			}
		}
	}
	ans = *min_element(&dp[n][0][0], &dp[n+1][0][0]);
	print(ans.first, ans.second);
}