#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e5+5;

int n, m, t, ans, sum;
array<int, 2> a[MM];
priority_queue<int> lo;
priority_queue<int, vector<int>, greater<>> hi;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>t;
	for(int i = 0; i < n; i++){
		cin>>a[i][0]>>a[i][1];
		a[i][0] *= 2;
	}
	sort(a, a+n);
	for(int i = 0; i < n; i++){
		lo.push(a[i][1]);
		if(a[i][0] > m)
			break;
		while(size(hi)*t > m-a[i][0]){
			assert(size(hi));
			sum -= hi.top();
			lo.push(hi.top());
			hi.pop();
		}

		while(size(lo) and size(hi)*t + t <= m-a[i][0]){
			sum += lo.top();
			hi.push(lo.top());
			lo.pop();
		}
		while(size(lo) and size(hi) and lo.top() > hi.top()){
			sum += lo.top()-hi.top();
			hi.push(lo.top());
			lo.push(hi.top());
			hi.pop();
			lo.pop();
		}
		ans = max(ans, sum);
	}
	cout<<ans<<'\n';
}