#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
typedef long double ld;
const int MM = 1005;

int n;
ll x[MM], y[MM], ans;
map<pair<pair<ll, ll>, ll>, int> mp;

ll sq(ll a){ return a*a; }

int main(){
	scan(n);
	for(int i = 0; i < n; i++){
		scan(x[i], y[i]);
		x[i] <<= 1;
		y[i] <<= 1;
		for(int j = 0; j < i; j++){
			ll mx = (x[i]+x[j])/2, my = (y[i]+y[j])/2;
			ll d = sq(mx-x[i]) + sq(my-y[i]);
			ans += mp[{{mx, my}, d}]++;
		}
	}
	print(ans);
}