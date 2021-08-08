#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 5005;
const int MV = 5000;

int n, a[MM], b[MM], c[MM];
int dp[MM][MM];
// dp[i][j] = # of ops needed to fill [1, i) and already j in ith bucket 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>c[i];
	for(int i = 1; i <= n; i++)
		cin>>a[i]>>b[i];

	memset(dp, 0x3f, sizeof dp);
	dp[1][0] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = MV-1; j >= 0; j--)
			dp[i][j] = min(dp[i][j], dp[i][j+1]);

		for(int j = b[i-1]; j <= MV; j++)
			dp[i][j] = min(dp[i][j], dp[i][j-b[i-1]]+1);

		for(int j = 0; j <= MV; j++){
			int k = max(0, (c[i]-j +a[i]-1)/a[i]);
			int l = min(MV, k*b[i]);
			dp[i+1][l] = min(dp[i+1][l], dp[i][j]+k);
		}
	}
	int ans = 1e9;
	for(int j = 0; j <= MV; j++)
		ans = min(ans, dp[n+1][j]);
	cout<<ans<<'\n';
}