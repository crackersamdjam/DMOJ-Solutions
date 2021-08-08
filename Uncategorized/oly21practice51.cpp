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

int n, a[MM];
ll first[101], second[101][101], third[101];
ll ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		ans += third[a[i]];
		for(int j = 1; j <= 100; j++){
			third[j] += second[a[i]][j];
			second[a[i]][j] += first[j];
		}
		first[a[i]]++;
	}
	cout<<ans<<'\n';
}