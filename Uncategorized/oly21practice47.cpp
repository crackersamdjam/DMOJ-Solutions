#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

void yes(){
	cout<<"Yes\n";
	exit(0);
}
void no(){
	cout<<"No\n";
	exit(0);
}

int main(){
	string s, t;
	cin>>s>>t;
	if(s == t)
		yes();
	if(size(s) != size(t)+1)
		no();
	for(int i = 0; i < size(t); i++){
		if(s[i] != t[i]){
			if(s.substr(i+1) == t.substr(i))
				yes();
			else
				no();
		}
	}
	yes();
}