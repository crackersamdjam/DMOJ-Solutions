#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 2005;

vector<int> bad;
map<int, int> dp;

int count(int l, int r){
	int no = upper_bound(all(bad), r) - upper_bound(all(bad), l);
	return r-l-no;
}

int go(int k){
	if(dp.count(k))
		return dp[k];
	int ret = 0;
	for(int i = k-1; i > max(0, k-2005); i--){
		if(k%i == 0 or binary_search(all(bad), i)) continue;
		int v = go(k%i) + count(k%i, i);
		ret = max(ret, v);
	}
	return dp[k] = ret;
}

int main(){
	int k, n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>k>>n;
	for(int i = 0,a; i < n; i++){
		cin>>a;
		bad.emplace_back(a);
	}
	sort(all(bad));

	dp[0] = -1e9;
	cout<<go(k)<<'\n';
}