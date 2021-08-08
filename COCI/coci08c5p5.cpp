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
using pll = pair<ll, ll>;

pll dp[69][11][69][2];
string s;
int m;

pll go(int i, int last, int k, bool b){
	if(i < 0) return {0, 1};
	// at digit i, last number, k of the last
	pll &ret = dp[i][last][k][b];
	if(~ret.first) return ret;
	ret = {0, 0};
	int r = b ? s[i]-'0' : 9;

	// pr(i, last, k, b, r);

	for(int j = 0; j <= r; j++){
		bool bb = b and (j == r);
		if(j == last){
			auto [f, s] = go(i-1, j, k+1, bb);
			ret.first += f + s*j*((k+1)*(k+1)-k*k);
			ret.second += s;
		}
		else{
			auto [f, s] = go(i-1, j, 1, bb);
			ret.first += f + s*j;
			ret.second += s;
		}
	}

	return ret;
}

ll run(ll n){
	memset(dp, -1, sizeof dp);
	s = to_string(n);
	reverse(all(s));
	m = size(s);
	auto ret = go(m-1, 10, 0, 1);
	return ret.first;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	ll l, r;
	cin>>l>>r;
	cout<<run(r)-run(l-1)<<'\n';
}