#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	if(a < b and c < d)
		cout<<"Go to the department store\n";
	else if(a < b)
		cout<<"Go to the grocery store\n";
	else if(c < d)
		cout<<"Go to the pharmacy\n";
	else
		cout<<"Stay home\n";
}