#include <bits/stdc++.h>
typedef long long ll;
constexpr ll mod = 1e9+7;
constexpr int MM = 1e7;

ll n, p, q, pre[MM], a;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin>>n>>p>>q;
	assert(1 <= n and n <= MM);
	assert(1 <= p and p <= MM);
	assert(1 <= q and q <= MM);
	assert(p < q);
	for(ll i = 0; i < n; i++){
		std::cin>>a;
		assert(1 <= a and a <= 1e9);
		ll j = n-((n-i)*p)/q;
		ll v = pre[i]*2+a;
		if(v >= mod){
			v -= mod;
			if(v >= mod)
				v -= mod;
		}
		pre[j] = v;
		std::cout<<v<<' ';
	}
}