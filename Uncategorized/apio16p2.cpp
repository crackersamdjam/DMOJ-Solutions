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
const int MM = 3e5+5;

struct sfun{
	priority_queue<ll> q;
	ll m, b;
	sfun(){}
	void merge(sfun &o){
		if(size(o.q) > size(q))
			swap(o, *this);
		m += o.m, b += o.b;
		while(size(o.q)){
			q.push(o.q.top());
			o.q.pop();
		}
	}
};

int n, m, p[MM], c[MM];
sfun t[MM];

int main(){
	scan(n, m);
	for(int i = 2; i <= n+m; i++){
		scan(p[i], c[i]);
		if(i > n){
			t[i].q.push(0);
			t[i].q.push(0);
			t[i].m = 1;
			t[i].b = 0;
		}
	}

	for(int i = n+m; i; i--){

		// right side: remove higher than slope 1 because par edge can always increase
		while(t[i].m > 1){
			t[i].m--;
			t[i].b += t[i].q.top();
			t[i].q.pop();
		}

		// left side: par edge can decrease until 0
		// afterwards, edges must individually decrease
		// so move the -1&0 and 0&1 points left by c
		// shift left b/c x loses c[i] to become f(x-c[i])

		ll f = t[i].q.top(); t[i].q.pop();
		ll s = t[i].q.top(); t[i].q.pop();
		t[i].q.push(f+c[i]);
		t[i].q.push(s+c[i]);
		t[i].b -= c[i];

		t[p[i]].merge(t[i]);
	}

	// pop last point to get 0 slope on left end of f(x)
	t[0].b += t[0].q.top();

	print(t[0].b);
}