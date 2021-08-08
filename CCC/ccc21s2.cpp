#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 5e6+5;

ll n, m, k, ans;
ll r, c;
bool onr[MM], onc[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	while(k--){
		char op; int i;
		cin>>op>>i;
		if(op == 'R'){
			if(onr[i]){
				ans -= m-2*c;
				onr[i] = 0;
				r--;
			}
			else{
				ans += m-2*c;
				onr[i] = 1;
				r++;
			}
		}
		else{
			if(onc[i]){
				ans -= n-2*r;
				onc[i] = 0;
				c--;
			}
			else{
				ans += n-2*r;
				onc[i] = 1;
				c++;
			}
		}
	}
	cout<<ans<<'\n';
}