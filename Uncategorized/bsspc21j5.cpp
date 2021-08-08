#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;

template<class T> pair<vector<T>, vector<T>> linear_sieve(T N){
	vector<T> low(N+1, 0);
	vector<T> primes;
	for(T i = 2; i <= N; i++){
		if(!low[i])
			low[i] = i, primes.emplace_back(i);
		for(T j = 0; j < (T)size(primes) and primes[j] <= low[i] and i*primes[j] <= N; j++)
			low[i*primes[j]] = primes[j];
	}
	return {move(low), move(primes)};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	auto [low, primes] = linear_sieve((int)2e6);
	// pr(size(primes));

	primes.insert(primes.begin(), -1);
	int sz = size(primes);
	vector<ll> psa(sz);
	for(int i = 1; i < sz; i++){
		psa[i] = psa[i-1] + primes[i];
	}

	int t, x, k;
	cin>>t;
	while(t--){
		cin>>x>>k;
		int l = lower_bound(all(primes), x)-primes.begin();
		int r = l+k-1;
		cout<<primes[r]<<' '<<psa[r]-psa[l-1]<<'\n';
	}
}