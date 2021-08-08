#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

vector<int> kmp(const string &s){
	int n = size(s);
	vector<int> pi(n);
	for(int i = 1, j = 0; i < n; i++){
		while(j and s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin>>s>>t;
	int m = size(t);

	string sa = t+"#"+s;
	auto a = kmp(sa);
	reverse(all(s));
	reverse(all(t));
	string sb = t+"#"+s;
	auto b = kmp(sb);

	for(int i = m+m; i < size(sa); i++){
		int j = (int)size(sa)-i+m+m-1;
		if(a[i] + b[j] >= m){
			cout<<"yes\n";
			return 0;
		}
	}
	cout<<"no\n";
}