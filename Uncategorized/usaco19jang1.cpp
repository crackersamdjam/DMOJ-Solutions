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
const ll mod = 1e9+7;
const int MM = 1e5+5, NN = 5005;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

void addmod(ll &a, ll b){
	a += b;
	if(a >= mod)
		a -= mod;
}

int n, m, k;
vector<int> v[NN];
ll dp[NN], add[NN];
map<char, int> mp;

int main(){
	scan(n, m, k);
	for(int i = 0,a,b; i < n; i++){
		scan(a, b);
		v[b].emplace_back(a);
	}
	dp[0] = 1;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			for(auto a: v[j])
				if(i >= a)
					addmod(dp[i], dp[i-a]);
		}
	}
	for(int i = 1; i <= n; i++){
		for(auto a: v[i])
			addmod(add[i], dp[k-a]);
	}
	
	for(int i = 0; i < m; i++){
		mp[gc]++; gc;
	}

	ll ans = 1;

	for(auto [i, c]: mp){
		ll val = 0;
		for(int j = 1; j <= n; j++)
			addmod(val, fpow(add[j], c, mod));
		ans = ans*val%mod;
	}

	print(ans);
}