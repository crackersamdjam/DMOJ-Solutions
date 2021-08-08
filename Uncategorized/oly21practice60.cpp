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
const int MM = 3e5+5;

mt19937_64 g(123);

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n+1), in[n+1];
		vector<ll> v(n+1);

		for(int i = 1; i <= n; i++){
			cin>>a[i];
			in[a[i]].emplace_back(i);
		}
		for(int i = 1; i <= n; i++){
			if(size(in[i])){
				int f = in[i].back();
				in[i].pop_back();
				for(int j: in[i]){
					v[j] = g();
					v[f] ^= v[j];
				}
			}
		}
		map<ll, int> cnt;
		ll ans = 0, val = 0;
		cnt[0] = 1;
		for(int i = 1; i <= n; i++){
			val ^= v[i];
			ans += cnt[val]++;
		}
		cout<<ans<<'\n';
	}
}