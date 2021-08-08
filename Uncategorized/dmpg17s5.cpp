#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1024;
// const int MM = 16;

int n, m, a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	iota(a, a+MM, 0);
	for(int i = __lg(MM)-2; i >= 0; i--){
		int v = 1<<i;
		for(int j = 2*v; j < MM; j += v*4){
			reverse(a+j, a+j+2*v);
			reverse(a+j, a+j+v);
			reverse(a+j+v, a+j+2*v);
		}
	}
	// for(int i = 0; i < MM; i++){
		// assert(!i or __builtin_popcount(a[i]^a[i-1]) == 1);
	// }
	for(int i = 0; i < n; i++){
		int v = a[i]<<10;
		for(int j = 0; j < m; j++){
			cout<<(a[j]|v)<<' ';
		}
		cout<<'\n';
	}
}