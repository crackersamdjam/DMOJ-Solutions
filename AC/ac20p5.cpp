#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+5;

int n, psa[MM], cnt[MM], sz[MM];
vector<int> adj[MM];

// https://cp-algorithms.com/algebra/prime-sieve-linear.html
// returns an array of the lowest prime factor (other than 1) of each integer and a list of primes
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
	cin>>n;
	for(int i = 2,p; i <= n; i++){
		cin>>p;
		adj[p].emplace_back(i);
	}

	auto [low, primes] = linear_sieve(n);

	for(int i = n; i; i--){
		for(int u: adj[i]){
			sz[i] += sz[u];
			psa[sz[u]]--;
		}
		psa[sz[i]++]++;
	}
	
	for(int i = n; i; i--){
		psa[i] += psa[i+1];
		int a = i;
		while(a > 1){
			cnt[low[a]] += psa[i];
			a /= low[a];
		}
	}
	vector<array<int, 2>> out;
	for(int i: primes){
		if(cnt[i])
			out.push_back({i, cnt[i]});
	}
	cout<<size(out)<<'\n';
	for(auto [a, b]: out)
		cout<<a<<' '<<b<<'\n';
}