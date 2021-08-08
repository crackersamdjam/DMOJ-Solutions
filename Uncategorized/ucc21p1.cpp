#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;



int main(){
	string s;
	cin>>s;
	int n = size(s);
	s += " ";
	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		if(s[i] == '2' and s[i+1] != '5')
			ans++;
	}
	cout<<ans<<'\n';
}