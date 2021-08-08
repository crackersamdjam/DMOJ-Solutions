#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 805;

int n, a[MM];
int dp[MM][MM];

int go(int l, int r){
	if(l >= r) return 0;
	int &ret = dp[l][r];
	if(~ret) return ret;
	ret = 1e9;

	if(a[l] == a[r]){
		ret = min(ret, go(l+1, r));
		ret = min(ret, go(l, r-1));
	}

	for(int i = l; i < r; i++){
		ret = min(ret, 1+go(l, i)+go(i+1, r));
	}

	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	memset(dp, -1, sizeof dp);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		a[n+i] = a[i];
	}

	int fs = 0, ss = 1e9;
	for(int i = 0; i < n; i++){
		fs += a[i] != a[i+1];
	}
	for(int i = 0; i < n; i++){
		ss = min(ss, go(i, i+n));
	}
	cout<<(fs+1)/2<<' '<<ss<<'\n';
}