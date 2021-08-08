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
const int MM = 5005;

int n;
ll dp[MM];
array<ll, 2> a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i][0]>>a[i][1];
		a[i][0] = abs(a[i][0]);
		a[i][1] = abs(a[i][1]);
	}
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++){
		ll maxy = 0;
		dp[i] = LLONG_MAX;
		for(int j = i; j > 0; j--){
			maxy = max(maxy, a[j][1]);
			dp[i] = min(dp[i], dp[j-1] + maxy*a[i][0]);
		}
	}
	cout<<dp[n]*4<<'\n';
}