// https://dmoj.ca/problem/bf3hard
// Source: https://github.com/wesley-a-leung/Resources/blob/master/Content/C++/math/Primes.h
// Determines whether N is prime using the Miller Rabin Primality Test
// Time Complexity: iterations * time complexity of powMod
// Memory Complexity: O(iterations)
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
using ll = unsigned long long;
using lll = __int128;

//mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 g((uint64_t) new char);
mt19937_64 g(0);
int randint(int l, int r){return uniform_int_distribution<int>(l, r)(g);}
ll randll(ll l, ll r){return uniform_int_distribution<ll>(l, r)(g);}

template<class T> T mulMod(T a, T b, T mod){
	return a*b%mod;
}

template<class T, class U> T fpow(T base, U pow, T mod){
	T x = 1;
	for(; pow > 0; pow >>= 1){
		if(pow&1) x = mulMod(x, base, mod);
		base = mulMod(base, base, mod);
	}
	return x;
}

template<class T> bool prime(T N, int iterations = 7){
	if(N < 2 or N%6%4 != 1)
		return (N|1) == 3;
	vector<T> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	while(int(A.size()) < iterations)
		A.emplace_back(uniform_int_distribution<long long>(1795265023, numeric_limits<long long>::max())(g));
	int s = 0;
	while(!(((N-1)>>s)&1))
		s++;
	T d = N>>s;
	for(T a: A){
		T p = fpow(a%N, d, N);
		int i = s;
		while(p != 1 and p != N-1 and a%N and i--)
			p = mulMod(p, p, N);
		if(p != N-1 and i != s)
			return 0;
	}
	return 1;
}

int main(){
	lll n;
	scan(n);
	while(!prime(n))
		n++;
	print(n);
}