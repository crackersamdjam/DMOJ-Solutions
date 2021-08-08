#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin>>s>>t;
	reverse(all(s));
	reverse(all(t));
	while(size(s) and size(t) and s.back() == t.back()){
		s.pop_back();
		t.pop_back();
	}
	cout<<size(s)+size(t)<<'\n';
}