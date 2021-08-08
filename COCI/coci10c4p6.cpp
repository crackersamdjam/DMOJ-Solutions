#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 50;

ll n, f[MM];

int main(){
	cin>>n;
	f[0] = f[1] = 1;
	for(int i = 2; i < MM; i++){
		f[i] = f[i-1]+f[i-2];
	}
	while(1){
		for(int i = MM-1; i >= 0; i--){
			if(f[i] == n){
				cout<<f[i]<<'\n';
				return 0;
			}
			if(f[i] < n){
				n -= f[i];
				break;
			}
		}
	}
}