#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e4+5;

int n, t, a[MM], b[MM];
int ans[MM];
map<int, int> mp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	cin>>t;
	for(int i = 1; i <= t; i++){
		cin>>b[i];
	}

	for(int i = 1; i <= n; i++){
		mp[a[i-1]]++;
		a[i] += a[i-1];
		for(int j = 1; j <= t; j++){
			ans[j] += mp[a[i]-b[j]];
		}	
	}

	for(int i = 1; i <= t; i++)
		cout<<ans[i]<<' ';
}