#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const int MM = 2e5+5;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int n;
int sum[MM], mx[MM];
ll ans = 1;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 0; i < n; i++){
		ll a; cin>>a;
		for(int j = 2; j*j <= a; j++){
			int cnt = 0;
			while(a % j == 0){
				a /= j;
				cnt++;
			}
			sum[j] += cnt;
			mx[j] = max(mx[j], cnt);
		}
		sum[a]++;
		mx[a] = max(mx[a], 1);
	}
	for(int i = 2; i < MM; i++){
		ans = ans*fpow((ll)i, sum[i]-mx[i], mod)%mod;
	}
	cout<<(ans+1)%mod<<'\n';
}