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
const int MM = 1e6+5, NN = 1<<7, F = (1<<7)-1;
const ll mod = 1e9+7;

void add(ll &x, ll y){
	x += y;
	if(x >= mod)
		x -= mod;
}
void sub(ll &x, ll y){
	x -= y;
	if(x < 0)
		x += mod;
}

int n, k, a[MM];
ll dp[2][NN][NN], sum;

int main(){
	scan(n, k);
	for(int i = 0,x,j; i < k; i++){
		scan(x);
		while(x--){
			scan(j);
			a[j] |= 1<<i;
		}
	}
	for(int i = 1; i <= n; i++){
		ll val = sum + (i == 1);
		int A = a[i]&F, B = (a[i]>>7)&F;
		for(int j = 0; j < NN; j++){
			sub(val, dp[1][A][j]);
			if(B&j)
				sub(val, dp[0][A][j]);
		}

		for(int j = 0; j < NN; j++){
			if(!(A&j))
				add(dp[0][j][B], val);
			else
				add(dp[1][j][B], val);
		}
		add(sum, val);
		// cout<<val<<' ';

		if(i == n)
			print(val);
	}
}