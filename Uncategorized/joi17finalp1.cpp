#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n, q;
ll A, B;
ll dif[MM], ans;

ll val(int i){
	if(i == n+1) return 0;
	ll v = dif[i];
	return v > 0 ? -v*A : -v*B;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q>>A>>B;
	for(int i = 0; i <= n; i++)
		cin>>dif[i];
	for(int i = n; i; i--){
		dif[i] -= dif[i-1];
		ans += val(i);
	}

	while(q--){
		int l, r, x; cin>>l>>r>>x;
		ans -= val(r+1)+val(l);
		dif[l] += x;
		dif[r+1] -= x;
		ans += val(r+1)+val(l);
		cout<<ans<<'\n';
	}
}