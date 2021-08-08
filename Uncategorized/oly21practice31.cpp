#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1e9+7;
const int MM = 1e6+5;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

using stt = tuple<ld, int, int>;

ll f[MM], inv[MM];

ll C(int n, int k){
	return f[n]*inv[k]%mod*inv[n-k]%mod;
}

int n, k;
ll ans;
set<int> vis[MM];

int main(){
	cin>>n>>k;
	f[0] = inv[0] = 1;
	for(int i = 1; i <= n; i++)
		f[i] = f[i-1]*i%mod;
	inv[n] = divmod(1LL, f[n], mod);
	for(int i = n-1; i; i--)
		inv[i] = inv[i+1]*(i+1)%mod;

	priority_queue<stt> q;
	q.emplace(log2(C(n, n/2)), n, n/2);
	vis[n].insert(n/2);

	while(k--){
		auto [curd, i, j] = q.top(); q.pop();
		ans += C(i, j);
		ans %= mod;
		if(j > 0 and !vis[i].count(j-1)){
			vis[i].insert(j-1);
			ld nd = curd - log2(i+1-j) + log2(j);
			q.emplace(nd, i, j-1);
		}
		if(j < i and !vis[i].count(j+1)){
			vis[i].insert(j+1);
			ld nd = curd + log2(i+1-(j+1)) - log2(j+1);
			q.emplace(nd, i, j+1);
		}
		if(i > 0 and j < i and !vis[i-1].count(j)){
			vis[i-1].insert(j);
			ld nd = curd - log2(i) + log2(i-j);
			q.emplace(nd, i-1, j);
		}
	}
	cout<<ans<<'\n';
}
/*
LDBL_MAX = 1.18973e+4932
bruh

__float128
:wesleythink:
*/