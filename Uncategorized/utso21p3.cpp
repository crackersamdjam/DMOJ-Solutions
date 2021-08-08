#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e5+5;
const ll mod = 1e9+7;

int n, a[MM];
array<int, 2> mx;
ll dp[MM];

ll bit[MM];

void up(int i, ll v){
	for(i++; i < MM; i += i&-i)
		bit[i] = (bit[i]+v)%mod;
}

ll qu(int i){
	ll v = 0;
	for(i++; i; i -= i&-i)
		v = (v+bit[i])%mod;
	return v;
}

int main(){
	cin>>n;
	up(0, 1);
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		mx = max(mx, {a[i], i});
		int r = mx[1]-1;
		dp[i] = qu(r);
		up(i, dp[i]);
	}
	cout<<dp[n]<<'\n';
}