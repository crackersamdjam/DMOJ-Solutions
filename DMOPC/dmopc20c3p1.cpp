#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	set<int> st;
	cin>>n;
	for(int i = 0; i < n; i++){
		int a;
		cin>>a;
		st.insert(a);
	}
	if(size(st) == n)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}