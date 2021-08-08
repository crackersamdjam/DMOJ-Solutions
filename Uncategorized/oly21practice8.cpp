#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const ll mod = 998244353;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

ll n, m, x[20], ans;
ll dp[21], cnt[21];
ll C[21][21];

int main(){
	C[0][0] = 1;
	for(int i = 1; i <= 20; i++){
		C[i][0] = 1;
		for(int j = 1; j <= 20; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
	}

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < m; i++)
		cin>>x[i];
	
	for(int i = 0; i < (1<<m); i++){
		ll lcm = 1;
		for(int j = 0; j < m; j++){
			if(i&(1<<j))
				lcm = lcm/__gcd(lcm, x[j])*x[j];
		}
		cnt[__builtin_popcount(i)] += n/lcm;
	}

	for(int i = m; i >= 0; i--){
		dp[i] = cnt[i];
		for(int j = i+1; j <= m; j++){
			if((j-i)%2)
				dp[i] -= cnt[j]*C[j][i];
			else
				dp[i] += cnt[j]*C[j][i];
			dp[i] %= mod;
		}
		for(int j = 0; j <= i; j += 4){
			ans += dp[i]*C[i][j]%mod*(1LL<<(m-i));
			ans %= mod;
		}
	}
	if(ans < 0)
		ans += mod;
	ans = divmod(ans, 1LL<<m, mod);
	cout<<ans<<'\n';
}