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
const int MM = 1005;

ll t, n, a, b;

int main(){
	scan(t);
	while(t--){
		scan(n, a, b);
		ll ans = LLONG_MAX;
		for(ll i = 1; i <= n; i++){
			if(n%i == 0)
				ans = min(ans, 2*i*a + 2*n/i*b);
		}
		ll g = __gcd(a, b);
		ll ra = b/g, rb = a/g;

		for(ll i = 1; i*ra <= n; i++){
			ll rem = n-ra*i;
			if(rem%rb == 0 and rem)
				ans = min(ans, 2*ra*a + 2*i*b + 2*rem/rb*a);
		}
		print(ans);
	}
}