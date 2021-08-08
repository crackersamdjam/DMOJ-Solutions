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
int constexpr MM = 4e5+5;

int n;
ll a[MM], b[MM], c;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 0; i <= n*2; i++){
		cin>>a[i];
		c ^= a[i];
	}
	for(int i = 0; i <= n*2; i++){
		cin>>b[i];
		c ^= b[i];
	}
	for(int i = 0; i <= n*2; i++)
		b[i] ^= c;
	sort(a, a+2*n+1);
	sort(b, b+2*n+1);
	for(int i = 0; i <= n*2; i++){
		if(a[i]^b[i])
			return cout<<"-1\n", 0;
	}
	cout<<c<<'\n';
}