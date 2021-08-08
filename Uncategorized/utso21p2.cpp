#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

int n, k;

int main(){
	cin>>k;

	for(int n = 1; n <= 101; n++){
		assert(n != 101);

		int cur = n*(n-1)/2+n;
		vector<int> ans;
		for(int i = n; i > 0; i--){
			int v = i*(i-1)/2+i;
			while(cur-v >= k){
				cur -= v;
				if(size(ans))
					ans.emplace_back(1);
				for(int j = 0; j < i; j++)
					ans.emplace_back(2);
			}
		}
		while(size(ans) < n)
			ans.emplace_back(1);

		if(size(ans) > n or cur != k)
			continue;
		// cout<<cur<<' '<<k<<endl;

		cout<<n<<'\n';
		for(int i: ans)
			cout<<i<<' ';
		break;
	}
}