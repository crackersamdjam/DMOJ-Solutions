#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 127;

int t;
ll n;
ll dp[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	dp[0] = dp[2] = 1;
	for(int i = 3; i < MM; i++){
		dp[i] = dp[i-2]+dp[i-3];
	}
	while(t--){
		cin>>n;
		n++;
		int i = 0;
		while(n > dp[i]){
			n -= dp[i++];
		}
		string s;
		while(i){
			if(i >= 3 and n <= dp[i-3]){
				s += "420";
				i -= 3;
			}
			else{
				if(i >= 3)
					n -= dp[i-3];
				s += "69";
				i -= 2;
			}
		}
		cout<<s<<'\n';
	}
}