#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n;
ll a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	ll tot = 0;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		a[i] *= n-i+1;
		tot += a[i];
	}
	ll cur = 0, hi = 0, ans = 0;
	for(int i = 1; i <= n; i++){
		cur -= 2*a[i];
		ans = min(ans, tot+cur-hi);
		hi = max(hi, cur);
	}
	cout<<ans<<'\n';
}