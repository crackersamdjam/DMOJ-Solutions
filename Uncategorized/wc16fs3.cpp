#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 405;

int n, k, a[MM], dp[MM][MM];
int cnt[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	cin>>n>>k;
	k++;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		for(int j = 1; j <= k; j++){
			
			int add = 0, sum = 0, len = -1;
			memset(cnt, 0, sizeof cnt);

			for(int l = i-1; l >= 0; l--){
				int v = a[l+1];
				len++;
				sum += add;
				add += cnt[len];
				if(v > len)
					cnt[v]++;
				else{
					sum += len-v;
					add++;
				}
				dp[i][j] = min(dp[i][j], dp[l][j-1]+sum);
			}
		}
	}
	cout<<dp[n][k]<<'\n';
}