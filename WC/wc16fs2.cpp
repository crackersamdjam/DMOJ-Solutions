#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const ll mod = 10007;

ll ans;
ll a[100];
int n;

void go(ll k){
	ll v = 1;
	for(int i = 1; i < n; i++){
		v = v*(a[i]/k)%mod;
	}
	ans = (ans+v)%mod;
	pr(k, v);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(ll i = 1; i*i <= a[0]; i++){
		if(a[0]%i == 0){
			go(i);
			if(i*i != a[0])
				go(a[0]/i);
		}
	}
	cout<<ans<<'\n';
}