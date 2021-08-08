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

int n, m, k;
bitset<MM> s[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m>>k;
	while(k--){
		int a, b;
		cin>>a>>b;
		s[a][b] = 1;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			auto t = s[i]&s[j];
			if(t.count() > 1){
				cout<<"NO\n";
				exit(0);
			}
		}
	}
	cout<<"YES\n";
}