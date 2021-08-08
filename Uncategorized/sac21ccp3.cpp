#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin>>n>>p;
	vector<pair<ll, string>> v;
	while(n--){
		string ss;
		ll m, c, e;
		cin>>ss;
		cin>>m>>c>>e;
		ll s = floor(4*sqrtl(m) + 3*pow(c, p) - 4*e);
		v.push_back({s, ss});
	}
	sort(all(v));
	cout<<v.back().second<<' '<<v.back().first<<'\n';
	reverse(all(v));
	cout<<v.back().second<<' '<<v.back().first<<'\n';
}