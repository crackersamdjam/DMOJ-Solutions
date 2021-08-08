#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1001*1050-995000;

int n, w, dp[MM], ans, tot;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;

	cin>>n>>w;
	while(n--){
		int v, c;
		cin>>v>>c;
		tot += c;
		ans += v;
		for(int i = MM-1; i >= c; i--){
			dp[i] = min(dp[i], dp[i-c]+v);
		}
	}

	w = max(0, tot-w);

	ans -= *min_element(dp+w, dp+MM);

	cout<<ans<<'\n';
}