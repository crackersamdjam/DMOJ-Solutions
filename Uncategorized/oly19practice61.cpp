#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

int n;
ll a[20], b[20];
map<ll, ll> mp;

int main(){
	scan(n);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	for(int i = 0; i < n; i++)
		scan(b[i]);

	for(int i = 0; i < (1<<n); i++){
		ll x = 0, y = 0;
		for(int j = 0; j < n; j++)
			if(i&(1<<j))
				x += a[j];
			else
				y += b[j];

		// print(x, y);
		// if(x and y)
		mp[x] = max(mp[x], y);
	}
	ll mx = -1;
	for(auto it = --mp.end();; it--){
		if(it->second > mx)
			mx = it->second;
		else
			it = mp.erase(it);
		
		if(it == mp.begin())
			break;
	}

	assert(n > 2);

	ll lx = -1, ly = LLONG_MAX/2, ans = LLONG_MAX;
	for(auto [x, y]: mp){
		// print(x, y);
		assert(y < ly);
		// print(lx, y, lx+y+2);
		// if(lx and y)
		if(lx >= 0)
			ans = min(ans, lx+y+2);
		ly = y;
		lx = x;
	}
	print(ans);
}