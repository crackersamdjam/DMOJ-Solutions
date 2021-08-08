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

	int n; char c;
	while(cin>>n>>c){
		if(c == 'N'){
			if(n < 3) cout<<"1\n";
			else cout<<"2\n";
		}
		else if(c == 'R'){
			cout<<n<<'\n';
		}
		else if(c == 'B'){
			cout<<n<<'\n';
		}
		else if(c == 'K'){
			int a = min(n, 2);
			cout<<a*a<<'\n';
		}
	}
}