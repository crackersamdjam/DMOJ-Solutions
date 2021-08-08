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
// using ll = __int128;
const int MM = 1e5+5;

ll m, n, a[MM], b[MM], ans = LLONG_MAX/3;

bool go(ll k){
	//get everyone to reach k
	ll rem = m;
	for(int i = 0; i < n; i++){
		ll sub = max(a[i]-k, (ll)0LL);
		b[i] = a[i]-sub;
		rem -= sub;
	}
	if(rem < 0)
		return 0;
	for(int i = 0; i < min(n, rem); i++)
		b[i] = max(b[i]-1, (ll)0LL);

	ll ret = 0;
	for(int i = 0; i < n; i++){
		// if(ret < ans)
			ret += b[i]*b[i];
	}
	// print(k, rem, ret);
	ans = min(ans, ret);
	return 1;
}

int main(){
	scan(m, n);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	sort(a, a+n);
	reverse(a, a+n);
	ll l = 0, md, r = 2e9;
	while(l <= r){
		md = (l+r)/2;
		if(go(md))
			r = md-1;
		else
			l = md+1;
	}
	go(r);
	go(l);
	// print(l, (int)go(l));
	sort(b, b+n);
	reverse(b, b+n);
	ll test = 0;
	for(int i = 0; i < n; i++){
		// print(b[i]);
		test += b[i]*b[i];
	}
	print(test);
	// print(ans);
}