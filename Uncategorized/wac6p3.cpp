#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

constexpr int MM = 2e5;

int n;
long long a[MM], b[MM], ans, hi;

int main(){
	scan(n);
	for(int i = 0; i < n; i++){
		scan(b[i]);
		a[i] = b[i];
	}
	std::sort(b, b+n);
	for(int i = 0; i < n; i++){
		hi = std::max(hi, a[i]);
		if(hi > b[i])
			ans = std::max(ans, b[i+1]-b[i]);
	}
	print(ans);
}