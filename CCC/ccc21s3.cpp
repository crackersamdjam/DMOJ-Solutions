#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n;
ll a[MM], b[MM], c[MM], ans = LLONG_MAX;

ll go(ll m){
	ll ret = 0;
	for(int i = 0; i < n; i++){
		ll d = max(0LL, abs(a[i]-m)-c[i]);
		ret += d*b[i];
	}
	ans = min(ans, ret);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	ll l = 0, m, r = 1e9;
	while(l <= r){
		m = l+r>>1;
		if(go(m) < go(m+1))
			r = m-1;
		else
			l = m+1;
	}
	cout<<ans<<'\n';
}