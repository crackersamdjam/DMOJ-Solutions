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
const int MM = 1e5+5, MV = 1e6+1;

int n, a[MM], v[MV];
int dp[MV];
int ans[MV];
bool done[MV];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		v[a[i]]++;
	}
	for(int i = 0; i < n; i++){
		if(done[a[i]])
			continue;
		done[a[i]] = 1;
		for(int j = a[i]; j < MV; j += a[i]){
			ans[j] += v[a[i]];
		}
	}
	for(int i = 0; i < n; i++)
		cout<<ans[a[i]]-1<<'\n';;
}