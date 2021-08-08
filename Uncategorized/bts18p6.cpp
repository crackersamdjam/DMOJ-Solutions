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
const int MM = 1e5+5;

int n, t;
ll d[4][MM], ans[MM];

int main(){
	scan(n, t);
	for(int i = 0; i < n; i++){
		ll l,r,a,b,c;
		scan(l, r, a, b, c);

		// if(r-l < 5){
		// 	for(int j = l; j <= r; j++)
		// 		ans[j] += a*(j-l)*(j-l) + b*(j-l) + c;
		// 	continue;
		// }

		d[0][l] += c;
		d[1][l+1] += b;
		
		d[1][l+1] += -a;
		d[2][l+1] += 2*a;

		d[0][r+1] -= c;
		
		d[0][r+1] -= (r-l)*b;
		d[1][r+1] -= b;

		d[2][r+1] -= a*2;
		d[1][r+1] -= (r-l)*a*2;
		d[1][r+1] -= -a;
		d[0][r+1] -= (r-l)*(r-l)*a;
	}

	for(int i = 1; i <= t; i++){
		for(int j = 2; j >= 0; j--)
			d[j][i] += d[j][i-1] + d[j+1][i];

		printn(d[0][i] + ans[i]), pc(32);
	}
}