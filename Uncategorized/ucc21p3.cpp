#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){
	int n, x, y, l, r, q;
	long long ans = 0;
	cin>>n>>x>>y>>q;
	while(q--){
		cin>>l>>r;
		l = max(l, x);
		r = min(r, y);
		ans += max(0, r-l+1);
	}
	cout<<ans<<'\n';
}