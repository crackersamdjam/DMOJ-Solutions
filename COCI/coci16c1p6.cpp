#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int n;
string s[16];
int cnt[16][26];
int common[26];
int sum[1<<16], lensum[1<<16];
int dp[1<<16];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>s[i];
		for(auto c: s[i])
			cnt[i][c-'a']++;
	}
	for(int i = 0; i < (1<<n); i++){
		memset(common, 0x3f, sizeof common);
		for(int j = 0; j < n; j++){
			if(i&(1<<j)){
				for(int c = 0; c < 26; c++)
					common[c] = min(common[c], cnt[j][c]);
				lensum[i] += size(s[j]);
			}
		}
		sum[i] = accumulate(common, common+26, 0);
		if(__builtin_popcount(i) < 2)
			sum[i] = 0;
	}

	for(int i = 1; i < (1<<n); i++){
		dp[i] = lensum[i] - sum[i];
		for(int j = (i-1)&i; j > 0; j = (j-1)&i){
			dp[i] = min(dp[i], dp[j] + dp[i^j] - sum[i]);
		}
		// cerr<<i<<' '<<lensum[i]<<' '<<-sum[i]<<", "<<dp[i]<<endl;
	}
	cout<<dp[(1<<n)-1]+1<<'\n';
}