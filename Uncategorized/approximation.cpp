#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ld = double;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin>>t;
	cout<<fixed<<setprecision(9);
	while(t--){
		ld c; cin>>c;

		if(c > 10000){
			cout<<round(c*c*acos(-1)/4)<<'\n';
		}
		else{
			int ans = 0;
			for(int i = 1; i <= c; i++){
				ans += sqrt(c*c-i*i);
			}
			cout<<ans<<'\n';
		}
	}
}