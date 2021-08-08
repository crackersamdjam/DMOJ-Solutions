#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 3e4+5;

int n, a[MM], psa[MM], ans;
int dp[MM], pre[MM];
//dp[index][cnt] = max{last length}
int mx1[MM], mx2[MM];

void go(){
	memset(dp, 0, sizeof dp);
	dp[0] = 1e9;
	for(int i = 0; i <= n; i++)
		psa[i] = psa[i-1]+a[i];

	for(int j = 1; j <= n; j++){
		swap(pre, dp);
		dp[0] = 0;
		int l = 0;
		for(int i = 1; i <= n; i++){
			while(psa[i]-psa[l] > pre[l])
				l++;
			if(psa[i]-psa[l] <= pre[l])
				dp[i] = psa[i]-psa[l];
			else
				dp[i] = 0;

			if(dp[i])
				mx1[i] = j;
		}
	}
}

int main(){
	#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#endif
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	go();
	swap(mx1, mx2);
	reverse(a+1, a+1+n);
	go();
	reverse(mx2+1, mx2+1+n);

	for(int i = 1; i <= n; i++)
		ans = max(ans, mx1[i]+mx2[i+1]);

	cout<<ans<<'\n';
}