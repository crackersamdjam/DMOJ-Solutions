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
const int MM = 2e5+5;

int n, q, a[MM], mx[MM], mn[MM];

int main(){
	scan(n, q);
	for(int i = 1; i <= n; i++)
		scan(a[i]);
	mx[n+1] = INT_MIN, mn[n+1] = INT_MAX;
	for(int i = n; i; i--){
		mx[i] = max(mx[i+1], a[i]);
		mn[i] = min(mn[i+1], a[i]);
	}
	while(q--){
		int v, d;
		scan(v, d);
		int l = 1, m, r = n;
		while(l <= r){
			m = (l+r)/2;
			if(mx[m]-v <= d and v-mn[m] <= d)
				r = m-1;
			else
				l = m+1;
		}
		print(n-l+1);
	}
}