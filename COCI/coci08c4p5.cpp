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

ll A, B, L, ans[3];

ll go(ll a){
	if(!a)
		return 1;
	vector<ll> v;
	for(ll i = 2; i*i <= a; i++){
		if(a%i == 0){
			v.emplace_back(i);
			while(a%i == 0)
				a /= i;
		}
	}
	if(a > 1)
		v.emplace_back(a);
	ll ret = 0;
	for(int i = 0; i < (1<<(int(v.size()))); i++){
		ll prod = 1;
		for(int j = 0; j < (int)v.size(); j++)
			if((i>>j)&1)
				prod *= v[j];
		if(__builtin_popcount(i)&1)
			ret -= L/prod;
		else
			ret += L/prod;
	}
	return ret;
}

int main(){
	scan(A, B, L);
	A = -A;

	for(ll i = B; i >= A; i--){
		ll oka = go(i-A), okb = go(B-i), okab = go((i-A)*(B-i));
		ans[0] += L-oka-okb+okab;
		ans[1] += oka+okb-2*okab;
		ans[2] += okab;
	}
	print(ans[0]);
	print(ans[1]);
	print(ans[2]);
}