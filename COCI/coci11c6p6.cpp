#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1<<20;
const ll mod = 1e9+7;

int n, m;
ll dp[MM], cnt[MM], ans;

ll fpow(ll base, ll exp){
	if(!exp) return 1;
	ll t = fpow(base, exp/2);
	t = t*t%mod;
	if(exp&1)
		t = t*base % mod;
	return t;
}

void addmod(ll &a, ll b){
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	assert(a >= 0 and a < mod);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int t = 0,k,j; t < n; t++){
		cin>>k;
		int mask = 0;
		while(k--){
			cin>>j;
			mask |= (1<<(j-1));
		}
		cnt[mask]++;
	}

	for(int i = 0; i < (1<<m); i++)
		dp[i] = cnt[i];
	for(int i = 0; i < m; i++){
		for(int mask = 0; mask < (1<<m); mask++){
			if(mask&(1<<i)){
				addmod(dp[mask], dp[mask^(1<<i)]);
			}
		}
	}
	int all = (1<<m)-1;
	for(int mask = 0; mask < (1<<m); mask++){
		int cnt = __builtin_popcount(mask^all); //all outside mask = how many times overcount
		// cout<<mask<<' '<<fpow(-1, cnt)*fpow(2, dp[mask])%mod<<endl;
		addmod(ans, fpow(-1, cnt)*fpow(2, dp[mask])%mod);
	}
	
	cout<<ans;

	return 0;
}
/*
dp[i] = # of masks in subset i
f(mask) = # of ways to cover completely
PIE on all f(subsets)

*/