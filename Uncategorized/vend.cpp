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
const int MM = 1e5+5;

int n, m;
vector<pair<ll, ll>> v;
ll dp[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m;
	while(n--){
		int a, b, c, d;
		cin>>a>>b>>c>>d;
		v.emplace_back(a, b);
		v.emplace_back(c, d);
		a += c;
		b += d;
		for(ll i = 1; i*a <= m; i *= 2){
			v.emplace_back(a*i, b*i);
		}
	}
	for(auto [a, b]: v){
		for(int i = m; i >= a; i--){
			dp[i] = max(dp[i], dp[i-a]+b);
		}
	}
	cout<<dp[m]<<'\n';
}