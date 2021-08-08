#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int MM = 1e6+5;

int n, a[MM], b[MM], ans = 1e9;

void go(){
	deque<int> ls, rs;
	for(int i = 0; i < n; i++)
		rs.emplace_back(a[i]);
	sort(all(rs));

	int m = (n)/2;
	// 3 -> 1
	// 4 -> 2

	//0 1 | 2
	//0 1 2 | 3

	for(int i = 0; i <= n; i++){
		//i the "zero" point (so is i+n)

		while(size(ls) and ls.front() < i){
			rs.emplace_back(n+ls.front()); ls.pop_front();
		}
		while(size(rs) and rs.front() <= i+m){
			ls.emplace_back(rs.front()); rs.pop_front();
		}

		int v = 0;
		if(size(ls))
			v = max(v, ls.back()-i);
		if(size(rs))
			v = max(v, n+i-rs.front());
		ans = min(ans, v);
	}

}

int main(){
	cin>>n;
	for(int i = 0,v; i < n; i++){
		cin>>v;
		v--;
		a[i] = (v-i+n)%n;
		b[n-i-1] = (v-(n-i-1)+n)%n;
	}
	go();
	swap(a, b);
	go();
	cout<<ans<<'\n';
}