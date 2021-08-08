#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 2005;

int n, sum, ans = 1e9;
int dp[MM][MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	dp[0][0] = 1;
	while(n--){
		int a;
		cin>>a;
		sum += a;
		for(int i = MM-1; i >= 0; i--){
			for(int j = MM-1; j >= 0; j--){
				if(i >= a) dp[i][j] |= dp[i-a][j];
				if(j >= a) dp[i][j] |= dp[i][j-a];
			}
		}
	}
	for(int i = 0; i < MM; i++){
		for(int j = 0; j < MM; j++){
			if(dp[i][j])
				ans = min(ans, max({i, j, sum-i-j}));
		}
	}
	cout<<ans<<'\n';
}
// what a bait