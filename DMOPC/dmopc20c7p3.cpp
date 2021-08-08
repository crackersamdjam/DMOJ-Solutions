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
const int MM = 1e6+5;

int t, n, l, r;
ll a[MM];

void run(){
	queue<pair<int, ll>> q;

	ll ans = 0, sum = 0;
	ll two = 0;

	for(int i = 0; i <= n; i++){
		if(sum < a[i]){
			q.emplace(i, a[i]-sum);
			sum = a[i];
		}

		while(size(q) and i-q.front().first > r){
			auto [j, c] = q.front(); q.pop();
			two += c;
			ans += c;
		}

		while(sum > a[i] and size(q) and i-q.front().first >= l){
			auto [j, c] = q.front();
			ll sub = min(c, sum-a[i]);
			ans += sub;
			sum -= sub;
			c -= sub;
			q.front().second = c;
			if(!c) q.pop();
		}

		if(sum > a[i]){
			ll sub = sum-a[i];
			ans += sub;
			two -= sub;
			sum -= sub;
			if(two < 0){
				cout<<"-1\n";
				return;
			}
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>t;
	while(t--){
		cin>>n>>l>>r;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		a[n] = 0;
		run();
	}
}