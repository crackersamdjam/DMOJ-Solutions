#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e6+5;

//mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 g((uint64_t) new char);
mt19937_64 g(0);
int randint(int l, int r){return uniform_int_distribution<int>(l, r)(g);}
long long randl(long long l, long long r){return uniform_int_distribution<long long>(l, r)(g);}
double randf(double l, double r){return uniform_real_distribution<double>(l, r)(g);}

int n, v[MM];
vector<int> in[11];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>v[i];
		in[v[i]].emplace_back(i);
	}
	for(int cc = 1; cc <= 10; cc++){
		int t = 30;
		int sz = size(in[cc]);
		if(sz < 2) continue;
		while(t--){
			int a = in[cc][randint(0, sz-1)];
			int b = in[cc][randint(0, sz-1)];
			int rem = n-abs(a-b);
			int c = (max(a, b)+rem/2)%n;
			if(a == b or rem%2) continue;
			if(v[c] == v[a]){
				cout<<a+1<<' '<<b+1<<' '<<c+1<<'\n';
				return 0;
			}
		}
	}
	cout<<"0 0 0\n";
}