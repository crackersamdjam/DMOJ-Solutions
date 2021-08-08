#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 3005;

int n, m, k;
ll a[MM];
ll A, B, C, T, ans;
vector<ll> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	cin>>A>>B>>C;
	cin>>T;
	for(int i = 1; i <= m; i++){
		cin>>a[i];
		a[i]--;
	}
	a[m+1] = n;
	for(int i = 1; i <= m; i++){
		ll ls = a[i];
		ll tt = ls*B;
		ll rem = T-tt;
		ll rs = min(a[i+1]-1, ls+rem/A);
		if(rem < 0)
			continue;

		ans += rs-ls+1;

		for(int t = 0; t < k-m; t++){
			tt += C*(rs+1 - ls);
			ls = rs+1;
			rem = T-tt;
			rs = min(a[i+1]-1, ls+rem/A);
			if(rem < 0 or rs < ls)
				break;
			v.emplace_back(rs-ls+1);
		}
	}
	sort(all(v), greater<ll>());
	for(int i = 0; i < min((int)size(v), k-m); i++)
		ans += v[i];
	cout<<ans-1<<'\n';
}