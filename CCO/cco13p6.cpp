#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e4+5;

string s;
int n;
int dp[MM][MM], mod;

int main(){
	cin>>s>>mod;
	n = size(s);
	s = " "+s;

	for(int i = 0; i <= n; i++)
		dp[0][i] = dp[i][0] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
			if(s[i] != s[j])
				dp[i][j] -= dp[i-1][j-1];

			if(dp[i][j] >= mod)
				dp[i][j] -= mod;
			if(dp[i][j] < 0)
				dp[i][j] += mod;
		}
	}

	cout<<dp[n][n]<<'\n';
}