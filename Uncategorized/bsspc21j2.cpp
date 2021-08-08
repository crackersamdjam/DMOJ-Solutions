#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int on[2000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int n, m;
	cin>>n;
	while(n--){
		int l, r; cin>>l>>r;
		while(l <= r){
			on[l++]++;
		}
	}
	cin>>m;
	while(m--){
		int l, r; cin>>l>>r;
		int k = 0;
		while(l <= r){
			k += on[l++];
		}
		cout<<(k?"Break is Over! Stop playing games! Stop watching Youtube!":":eyy:")<<'\n';
	}
}