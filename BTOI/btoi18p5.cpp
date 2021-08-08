#pragma GCC optimize("O3")
// #pragma GCC target("sse4")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll;
constexpr int MM = 4100;

std::mt19937_64 g(300);

int n, m, k;
char s[MM][MM];
ll f[MM], dp[MM][4], sum;
int mp[200];

int main(){
	mp['A'] = 0;
	mp['C'] = 1;
	mp['G'] = 2;
	mp['T'] = 3;
	scan(n, m, k);
	for(int i = 0; i < n; i++){
		scanf("%s", s[i]);
		f[i] = std::uniform_int_distribution<ll>(1, LLONG_MAX)(g);
		sum += f[i];
		#pragma GCC ivdep
		for(int j = 0; j < m; j++){
			s[i][j] = mp[s[i][j]];
			dp[j][s[i][j]] += f[i];
		}
	}
	for(int i = 0; i < n; i++){
		ll v = 0;
		#pragma GCC ivdep
		for(int j = 0; j < m; j++){
			v += dp[j][s[i][j]];
		}
		if(sum*m - v + f[i]*k == sum*k){
			print(i+1);
			break;
		}
	}
}