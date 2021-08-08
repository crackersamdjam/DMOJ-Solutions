#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e6+5;

int n, m, a[MM], b[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int j = 1; j <= m; j <<= 1){
		if(m&j){
			for(int i = 0; i < n; i++){
				b[i] = a[i]^a[(i+j)%n];
			}
			for(int i = 0; i < n; i++){
				a[i] = b[i];
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout<<a[i]<<'\n';
	}
}