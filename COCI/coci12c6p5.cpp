#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e4+5;
const ll mod = 1e9+7;

int n, a[MM];
ll dp[MM], pre[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	if(a[1] > 0 or a[n] > 0){
		cout<<"0\n";
		return 0;
	}
	a[1] = a[n] = 0;
	dp[0] = 1;

	for(int i = 2; i <= n; i++){
		swap(dp, pre);
		for(int j = 0; j <= n/2; j++){
			if(a[i] == -1 or a[i] == j){
				dp[j] = (pre[j] + pre[j+1] + (j ? pre[j-1] : 0))%mod;
			}
			else
				dp[j] = 0;
		}
	}
	cout<<dp[0]<<'\n';
}