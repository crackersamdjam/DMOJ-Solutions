#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e6+5;

int n, q, psa[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>psa[i];
		psa[i]+=psa[i-1];
	}
	while(q--){
		int l, r;
		cin>>l>>r;
		int a = (psa[r]-psa[l-1])/(r-l+1);
		cout<<a<<'\n';
	}
}