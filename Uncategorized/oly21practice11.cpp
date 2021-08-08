#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int n, a[MM], b[MM], dp[MM][3], ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(i == 1 or a[i] != a[i-1]){
			dp[i][0] = dp[i-1][0]+1;
			dp[i][1] = dp[i-1][1]+1;
			dp[i][2] = dp[i-1][2]+1;
		}
		else{
			dp[i][0] = 1;
			dp[i][1] = dp[i-1][0]+1;
			dp[i][2] = dp[i-1][1]+1;
		}
		ans = max(ans, *max_element(dp[i], dp[i]+3));
	}
	cout<<ans<<'\n';
}