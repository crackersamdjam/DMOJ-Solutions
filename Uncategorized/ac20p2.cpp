#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int n, q;
long long cnt[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	while(n--){
		int a; cin>>a; cnt[a]++;
	}
	while(q--){
		int op, a; cin>>op>>a;
		if(op == 1){
			cnt[a/2] += cnt[a];
			cnt[(a+1)/2] += cnt[a];
			cnt[a] = 0;
		}
		else{
			cout<<cnt[a]<<'\n';
		}
	}
}