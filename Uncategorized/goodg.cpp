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
#ifndef ONLINE_JUDGE
const int MM = 100, MN = 100;
#else
const int MM = 1e6+2, MN = 1e6+2;
#endif

struct line{
	ll m = 0, b = -1e9;
	inline ll f(ll x){
		return m*x + b;
	}
} tree[MN*2];

int n;

void add(line ln, int l = 0, int r = n+1, int rt = 1){
	int m = (l+r)/2;
	bool bl = ln.f(l) > tree[rt].f(l);
	bool bm = ln.f(m) > tree[rt].f(m);
	if(bm)
		swap(tree[rt], ln);
	if(l == r)
		return;
	if(bl != bm)
		add(ln, l, m, rt+1);
	else
		add(ln, m+1, r, rt+(m-l+1)*2);
}

ll get(int x, int l = 0, int r = n+1, int rt = 1){
	int m = (l+r)/2;
	if(l == r)
		return tree[rt].f(x);
	if(x <= m)
		return max(tree[rt].f(x), get(x, l, m, rt+1));
	return max(tree[rt].f(x), get(x, m+1, r, rt+(m-l+1)*2));
}

int main(){
	scan(n);
	add({0, 0});
	for(int i = 1; i <= n; i++){
		ll dp = get(i), a, d;
		scan(a, d);
		add({-d, dp+a + d*i});
	}
	print(get(n+1));
}