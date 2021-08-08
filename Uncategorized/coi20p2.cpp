#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 5005;

int n, a[MM];
int dp[MM][MM];
int best[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	// last one [idk, i]
	// current one (i, j]
	for(int i = 1; i <= n; i++){
		int l = i;
		int ls = 0, rs = 0, add = 0;

		for(int j = 1; j <= i; j++){
			best[j] = max(dp[j+1][i], best[j-1]);
		}

		for(int j = i+1; j <= n; j++){
			dp[i+1][j] = max(dp[i+1][j], best[i]);
			dp[i+1][j] = max(dp[i+1][j], dp[i+1][j-1]);
			// dp[i+1][j] = max(dp[i+1][j], dp[l][i] + add);
			dp[i+1][j] = max(dp[i+1][j], best[l] + add);

			rs += a[j];
			if(ls == rs)
				add++;

			while(l > 1 and ls <= rs){
				ls += a[l];
				l--;
				if(ls == rs){
					add++;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans = max(ans, dp[i][n]);
	}
	cout<<ans<<'\n';
}
/*
dp[i][j] = [i, j] in last segment
loop i
"extend" i --> j
and also move left side

*/