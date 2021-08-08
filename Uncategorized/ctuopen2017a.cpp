#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

long long a[1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while(cin>>n){
		a[0] = 1e11;
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		if(n == 1){
			cout<<"1\n";
			continue;
		}
		auto d = a[n]-a[n-1];
		for(int i = n-2; i >= 0; i--){
			if(a[i+1]-a[i] != d){
				cout<<i+1<<'\n';
				break;
			}
		}
	}
}