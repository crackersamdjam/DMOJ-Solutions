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
using ll = long long;
const int MM = 1e5+5;

int n, m;
ll bit[MM];
bool off[MM][6];

void up(int i, ll x){
	for(; i < MM; i += i&-i)
		bit[i] += x;
}

ll qu(int i){
	int x = 0;
	for(; i; i -= i&-i)
		x += bit[i];
	return x;
}

ll dif[MM];
ll ans, x, y;

int main(){
	cin>>n>>m>>x>>y;
	for(int i = 0; i < m; i++){
		int a; char b;
		cin>>a>>b;
		b -= 'A';
		off[a][b] = 1;
		if(b == 0)
			ans += x*!off[a][1];
		if(b == 5)
			ans += x*!off[a][4];

		if(b == 2 or b == 3)
			up(a, 1);

		ll ls = a*2-qu(a);
		ll rs = (n-a+1)*2 - (qu(n) - qu(a-1));
		ls *= x;
		rs *= x;
		ans += ls;
		dif[i] = rs-ls;
		ans += i*y;
	}
	sort(dif, dif+m);
	int i = 0;
	while(i < m and dif[i] + y*i - y*(m-i-1) < 0){
		ans += dif[i] + y*i - y*(m-i-1);
		i++;
	}
	cout<<ans<<'\n';
}