#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e6+5;

ll fpow(ll base, ll pow, ll mod){
	bool over = 0;
	if(base >= mod){
		over = 1;
		base %= mod;
	}
	ll x = 1;
	for(; pow > 0; pow >>= 1){
		if(pow&1){
			x = x*base;
			if(x >= mod){
				over = 1;
				x %= mod;
			}
		}
		base = base*base;
		if(base >= mod){
			over = 1;
			base %= mod;
		}
	}
	if(over)
		x += mod;
	return x;
}

ll phi(ll n){
	ll val = n;
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0){
			while(n%i == 0)
				n /= i;
			val -= val/i;
		}
	}
	if(n > 1) val -= val/n;
	return val;
}

int n;
ll a[MM], b[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>b[0];
	for(int i = 0; i < n; i++){
		cin>>a[i];
		b[i+1] = phi(b[i]);
	}
	ll ans = 1;
	for(int i = n-1; i >= 0; i--){
		ans = fpow(a[i], ans, b[i]);
	}
	cout<<ans%b[0]<<'\n';
}