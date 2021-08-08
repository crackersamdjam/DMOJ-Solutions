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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	long long ans = 0;
	int n, a, b = 0;
	cin>>n;
	while(n--){
		cin>>a;
		if(a <= b){
			ans += b+1-a;
			b++;
		}
		else{
			b = a;
		}
	}
	cout<<ans<<'\n';
}