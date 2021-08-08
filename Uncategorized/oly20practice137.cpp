#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
constexpr ll mod = 1e9+7;
constexpr int MM = 1e5+5;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int n, k, l, r;
ll dp[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>l>>r;
	l = (l+k-1)/k;
	r /= k;
	for(int i = r-l; i; i--){
		ll x = r/i-(l-1)/i;
		dp[i] = fpow(x, n, mod);
		dp[i] = (dp[i]-x+mod)%mod;
		for(int j = i+i; j <= r-l; j += i)
			dp[i] = (dp[i]-dp[j]+mod)%mod;
	}
	cout<<dp[1]+(l == 1)<<'\n';
}