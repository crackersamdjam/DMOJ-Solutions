#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;


int main(){
	int n, sum = 0, ans = 0;
	cin>>n;
	while(n--){
		int a; cin>>a;
		if(a%2){
			sum = 0;
		}
		else{
			sum += a;
		}
		ans = max(ans, sum);
	}
	cout<<ans<<'\n';
}