#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
template<typename T> int size(const T &a){return a.size();}

using namespace std;

int n, c, v;
string s;
int cc, vv;
string sv = "aeiouy";
string sc = "bcdfghjklmnpqrstvwxyz";

int main(){
	cin>>n>>c>>v;
	cin>>s;
	for(auto i: s){
		if(sv.find(i) != string::npos)
			vv++;
		else
			vv = 0;
		if(sc.find(i) != string::npos)
			cc++;
		else
			cc = 0;
		if(cc > c or vv > v){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
}