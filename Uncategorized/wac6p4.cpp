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
const int MM = 2e5+5;
const ll mod = 998244353;

void out(ll a[4]){
	for(int i = 0; i < 4; i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
}

char s[MM];
int n, k;
ll ans, v[4][4], cnt[4];

int main(){
	scan(n, k);
	scanf("%s", s+1);
	for(int i = 0; i < 4; i++)
		v[i][i] = 1;

	for(int i = 1; i <= n; i++){
		if(s[i] == 'W'){
			v[0][1] += v[0][0];
			v[0][1] %= mod;
		}
		if(s[i] == 'A'){
			v[0][2] += v[0][1];
			v[1][2] += v[1][1];
			v[0][2] %= mod;
			v[1][2] %= mod;
		}
		if(s[i] == 'C'){
			v[0][3] += v[0][2];
			v[1][3] += v[1][2];
			v[2][3] += v[2][2];
			v[0][3] %= mod;
			v[1][3] %= mod;
			v[2][3] %= mod;
		}
	}
	cnt[0] = 1;
	while(k--){
		for(int r = 3; r >= 0; r--){
			ll val = 0;
			for(int l = r; l >= 0; l--){
				val += cnt[l]*v[l][r]%mod;
				val %= mod;
			}
			cnt[r] = val;
		}
		// out(cnt);
	}

	print(cnt[3]);
}