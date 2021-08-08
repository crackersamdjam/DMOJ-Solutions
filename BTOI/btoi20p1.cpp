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

ll n;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
ll last, C = 4;
bool ask(ll a){
	cout<<"? "<<a<<endl;
	assert(a > 0 and a <= n);
	bool ret = abs(last-a) >= C;
	last = a;
	return ret;
}
#else
bool ask(ll a){
	assert(a > 0 and a <= n);
	cout<<"? "<<a<<endl;
	bool x;
	cin>>x;
	return x;
}
#endif

int main(){
	cin>>n;
	ll st = 1, dir = 1;
	ll l = 1, m, r = n-1;
	while(l <= r){
		m = (l+r)/2;
		st += dir*m;
		dir = -dir;
		l = m+1;
	}
	ll off = n-st;
	//offset (increase starting point by this)
	if(dir == 1){ //last one was negative
		st = n-(1-st);
		off = n-st;
	}

	ll i = off+1;
	dir = 1;
	ask(i); //init
	l = 1, r = n-1;
	while(l <= r){
		m = (l+r)/2;

		i += dir*m;
		dir = -dir;

		if(ask(i)) //if notices, then too large
			r = m-1;
		else
			l = m+1;
	}
	assert(l > 0 and l <= n);
	cout<<"= "<<l<<endl;
}
/*
alternate l/r jumps
if ans <= m, then works
otherwise, don't run out of space
precalc starting point in reverse
*/