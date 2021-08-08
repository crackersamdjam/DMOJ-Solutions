#include <bits/stdc++.h>
using namespace std;
const int MM = 605;

int n, m, k, dp[2][MM*MM], a[MM], b[MM], ans = 1e9, sum;
//dp[sum] = max{special}

int main(){
	memset(dp, -0x3f, sizeof dp);
	cin>>n>>m>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		sum += a[i];
		if(a[i] < k){
			cout<<"Impossible\n";
			return 0;
		}
	}
	int cur = 0, pre = 1;
	dp[cur][0] = 0;
	for(int i = 1; i <= m; i++){
		swap(cur, pre);
		cin>>b[i];
		int add = min(b[i], n);
		for(int j = MM*MM-1; j >= b[i]; j--){
			dp[cur][j] = dp[pre][j-b[i]]+add;
		}
		for(int j = 0; j < MM*MM; j++){
			dp[cur][j] = max(dp[cur][j], dp[pre][j]);
			if(j >= sum and dp[cur][j] >= n*k)
				ans = min(ans, j-sum);
		}
	}
	if(ans == 1e9)
		cout<<"Impossible\n";
	else
		cout<<ans<<'\n';
}