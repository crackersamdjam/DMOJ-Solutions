#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using vect = vector<ll>;
using matrix = vector<vector<ll>>;
constexpr ll mod = 1e9+7;

template<class ll> ll gcd(ll _a, ll _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class ll, class U> ll fpow(ll _base, U _pow, ll _mod){_base %= _mod; ll _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class ll> ll mulmod(ll _a, ll _b, ll _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class ll> ll divmod(ll _a, ll _b, ll _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}


matrix mul(const matrix &a, const matrix &b){
	int n = size(a);
	matrix c(n, vector<ll>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				// c[i][j] = (c[i][j] + a[i][k]*b[k][j])%mod;
				c[i][j] += a[i][k]*b[k][j]%mod;
			}
			c[i][j] %= mod;
			// this makes code faster for some reason
		}
	}
	return c;
}

vect mul(const vect &a, const matrix &b){
	int n = size(a);
	vect c(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// c[i] = (c[i] + a[j]*b[j][i])%mod;
			c[i] += a[j]*b[j][i]%mod;
		}
		c[i] %= mod;
	}
	return c;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x, d;
	cin>>n>>x>>d;
	string s, t;
	cin>>s>>t;
	int c = 0;
	for(int i = 0; i < n; i++)
		c += s[i]^t[i];

	matrix C(n+1, vect(n+1));
	C[0][0] = 1;
	for(int i = 1; i <= n; i++){
		C[i][0] = 1;
		for(int j = 1; j <= n; j++){
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
		}
	}

	ll div = divmod(1LL, C[n][x], mod);

	matrix mat(n+1, vect(n+1));
	vect vec(n+1);
	vec[0] = 1;

	for(int i = 0; i <= n; i++){
		// i is how many on
		for(int j = 0; j <= min(i, x); j++){
			//j is how many to remove
			int k = x-j;
			//k is how many to add

			int l = i-j+k;
			//l is how many after operations

			if(l < 0 or l > n)
				continue;
			assert(0 <= j and j <= x);
			assert(0 <= k and k <= x);

			//which stay and which new ones added
			mat[i][l] = C[i][j]*C[n-i][k]%mod*div%mod;
		}
	}

	for(; d; d >>= 1){
		if(d&1){
			vec = mul(vec, mat);
		}
		mat = mul(mat, mat);
	}

	// divide because this is 1 out of all options with c bits
	cout<<divmod(vec[c], C[n][c], mod)<<'\n';
}