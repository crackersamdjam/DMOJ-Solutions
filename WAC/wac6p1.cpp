#include <bits/stdc++.h>
using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	cout<<setprecision(9);
	while(n--){
		double p, c;
		cin>>p>>c;
		cout<<p/(1+c/100)<<'\n';
	}
}