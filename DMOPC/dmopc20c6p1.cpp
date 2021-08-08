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
const int MM = 2e6+5;

int n;
ll a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		a[i+n] = a[i];
	}
	for(int i = 1; i <= 2*n; i++){
		a[i] += a[i-1];
	}
	int m = 1;
	for(int l = 0; l < n; l++){
		int r = n+l;
		ll ls, rs, d1, d2;
		while(1){
			rs = a[r]-a[m];
			ls = a[m]-a[l];
			d1 = abs(rs-ls);
			m++;
			rs = a[r]-a[m];
			ls = a[m]-a[l];
			d2 = abs(rs-ls);
			if(d2 < d1){

			}
			else{
				m--;
				break;
			}
		}
		cout<<min(d1, d2)<<" \n"[l == n-1];
	}
}