#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;



int main(){
	long long t, n, a, b, c, v;
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		c = a/__gcd(a, b)*b;
		v = n/a+n/b-n/c;
		cout<<v<<'\n';
	}
}