#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e5+5;

struct Bit{
	ll bit[MM], sum;
	map<ll, int> mp;
	int t;
	void up(int i, ll x){
		sum += x;
		// assert(mp.lower_bound(i)->second);
		for(i = mp.lower_bound(i)->second; i < MM; i += i&-i){
			bit[i] += x;
		}
	}
	ll qu(int i){
		ll x = 0;
		for(i = prev(mp.upper_bound(i))->second; i; i -= i&-i)
			x += bit[i];
		return x;
	}
	void build(){
		mp[-1e15] = 0;
		mp[1e15] = 0;
		for(auto &i: mp){
			i.second = ++t;
		}
	}

} lc, rc, lv, rv;

int n, a[MM];
ll ans = LLONG_MAX;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		lc.mp[a[i]-i] = 0;
		lv.mp[a[i]-i] = 0;
		rc.mp[a[i]+i] = 0;
		rv.mp[a[i]+i] = 0;
	}
	lc.build();
	lv.build();
	rc.build();
	rv.build();

	for(int i = 1; i <= n; i++){
		rc.up(a[i]+i, 1);
		rv.up(a[i]+i, a[i]+i);
	}

	for(int i = 0; i <= n; i++){
		if(i){
			lc.up(a[i]-i, 1);
			lv.up(a[i]-i, a[i]-i);
			rc.up(a[i]+i, -1);
			rv.up(a[i]+i, -(a[i]+i));
		}

		ll l = max(i, n-i+1), m, r = 1e9;
		while(l <= r){
			m = l+r>>1;
			int cnt = lc.qu(m-i) + rc.qu(m+i);
			if(cnt*2 > n)
				r = m-1;
			else
				l = m+1;
		}
		m = l;
		int lcnt = lc.qu(m-i);
		ll lval = lv.qu(m-i);
		int rcnt = rc.qu(m+i);
		ll rval = rv.qu(m+i);
		ll v = 0;
		v += lcnt*(m-i)-lval + (lv.sum-lval)-(i-lcnt)*(m-i);
		v += rcnt*(m+i)-rval + (rv.sum-rval)-(n-i-rcnt)*(m+i);
		ans = min(ans, v);
	}
	cout<<ans<<'\n';
}