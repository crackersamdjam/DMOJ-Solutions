#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll;
constexpr int MM = 201, NN = 61;
constexpr ll inf = LLONG_MAX/3;

bool done[2][NN][MM][MM];
ll a[MM], dp[2][NN][MM][MM], k;
int n;

inline ll sum(int l, int r){
	return a[r] - a[l-1];
}

ll go(int l, int r, int i, bool f){
	if(l > r)
		return 0;
	if(i == -1)
		return (l < r) ? -inf : 0;
	
	if(done[f][i][l][r])
		return dp[f][i][l][r];
	done[f][i][l][r] = 1;
	ll &ret = dp[f][i][l][r] = -inf;
	bool g = k&(1LL<<i);
	
	for(int m = l-1; m <= r; m++){
		if(!f or g or m == r)
			ret = std::max(ret, go(l, m, i-1, f and !g) + go(m+1, r, i-1, f) + sum(m+1, r));
	}
	
	return ret;
}

int main(){
	scan(n, k);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		a[i] += a[i-1];
	}
	print(go(1, n, 60, 1));
}