#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using st = vector<ll>;
const int MM = 1e5+2;

st operator+(const st& v1, const st& v2){
	st r = v1;
	for(int i = 0; i < v2.size(); i++)
		r[i] += v2[i];
	return r;
}

st operator-(const st& v1, const st& v2){
	st r = v1;
	for(int i = 0; i < v2.size(); i++)
		r[i] -= v2[i];
	return r;
}

st bit[MM];

st vc(int v){
	st r(32);
	for(int i = 0; i < 32; i++){
		if(v&(1<<i))
			r[i] = 1;
	}
	return r;
}

void add(int i, st v){
	for(; i < MM; i += i&-i)
		bit[i] = bit[i]+v;
}
void sub(int i, st v){
	for(; i < MM; i += i&-i)
		bit[i] = bit[i]-v;
}
st query(int i){
	st r = vc(0);
	for(; i; i -= i&-i)
		r = r+bit[i];
	return r;
}

int n, q, a[MM];

int main(){

	#ifndef ONLINE_JUDGE
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	    freopen("err.txt", "w", stderr);
	#endif
	
	for(int i = 0; i < MM; i++)
		bit[i] = vc(0);
	
	scan(n, q);
	
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		add(i, vc(a[i]));
	}
	
	for(int i = 0,op,l,r; i < q; i++){
		scan(op, l, r);
		if(op == 1){
			sub(l, vc(a[l]));
			add(l, vc(a[l] = r));
			continue;
		}
		st v = query(r) - query(l-1);
		ll ans = 0, nm = r-l+1, mul;
		for(ll j = 0; j < 32; j++){
			mul = (1LL<<j);
			if(op == 2){
				ans += mul*(v[j]*(nm-1) - v[j]*(v[j]-1)/2);
			}
			else if(op == 3){
				ans += mul*v[j]*(v[j]-1)/2;
			}
			else{
				ans += mul*(v[j]*(nm-1) - v[j]*(v[j]-1)/2);
				ans -= mul*v[j]*(v[j]-1)/2;
			}
		}
		print(ans);
	}
	
	return 0;
}