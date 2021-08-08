#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 505;

int n, a[MM][MM], b[MM][MM], c[MM][MM];
ll ans;

ll go(){
	ll ret = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!b[i][j])
				c[i][j] = c[i][j-1]+1;
			else
				c[i][j] = 0;
		}
	}

	for(int l = 1; l <= n; l++){
		for(int r = l; r <= n; r++){
			ll sum = 0;
			for(int i = 1; i <= n+1; i++){
				if(c[i][r] >= r-l+1){
					sum++;
				}
				else{
					ret += sum*(sum-1)/2 + sum;
					sum = 0;
				}
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>a[i][j];
			if(a[i][j] < 100)
				b[i][j] = 1;
		}
	}
	ans += go();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 100)
				b[i][j] = 1;
		}
	}
	ans -= go();
	cout<<ans<<'\n';
}