#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ld = long double;

void split(vector<string> &s, const string &str, char sep){
    stringstream ss(str);
    string sp;
    while(getline(ss, sp, sep)){
        if(sp != "")
            s.push_back(sp);
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string ss;

	int n;
	while(cin>>n){
		// pr("n", n);

		map<int, int> a, b;
		long long s = 0;
		for(int i = 0; i < n; i++){
			int x, y;
			cin>>x>>y;
			// pr(x, y);
			s += a[x-y]++;
			s += b[x+y]++;
		}
		ld ans = 2*ld(s)/(ld(n)*n);
		cout<<ans<<'\n';
	}
}