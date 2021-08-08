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
using ld = double;
const int MM = 1e4+5;

int n;
ll s, t[MM], f[MM], dp[MM];
deque<int> q = {0};

ld eval(int i, int l, int r){
	return ld(t[i]*(f[l]-f[r]) + dp[r]-dp[l])/(f[r]-f[l]);
}

int main(){
	scan(n, s);
	for(int i = 1; i <= n; i++){
		scan(t[i], f[i]);
		t[i] += t[i-1];
		f[i] += f[i-1];
	}
	
	for(int i = 1; i <= n; i++){

		while(size(q) > 1 and s >= eval(i, q[0], q[1]))
			q.pop_front();

		dp[i] = s*f[n] + t[i]*(f[i]-f[q[0]]) + dp[q[0]] - s*f[q[0]];

		while(size(q) > 1 and eval(i, q[size(q)-2], q.back()) >= eval(i, q.back(), i))
			q.pop_back();
		
		q.emplace_back(i);
	}

	print(dp[n]);
}
/*
dp[i] = min{ (s+t[i])*(f[i]-f[j]) + s*(f[n]-f[i]) + dp[j]}
= min{ s*f[i] - s*f[j] + t[i]*f[i] - t[i]*f[j] + s*f[n] - s*f[i] + dp[j]}
= min{ - s*f[j] + t[i]*f[i] - t[i]*f[j] + s*f[n] + dp[j]}
= min{ t[i]*(f[i]-f[j]) + s*f[n] - s*f[j] + dp[j]}
= s*f[n] + min{ t[i]*(f[i]-f[j]) + dp[j] - s*f[j]}

if f(l, i) >= f(r, i)   ; l <= r
then rm l
t[i]*(f[i]-f[l]) + dp[l] - s*f[l] >= t[i]*(f[i]-f[r]) + dp[r] - s*f[r]
s*f[r] - s*f[l] >= t[i]*(f[i]-f[r]) - t[i]*(f[i]-f[l]) + dp[r] - dp[l]
s*(f[r]-f[l]) >= t[i]*(f[l]-f[r]) + (dp[r]-dp[l])
s >= (t[i]*(f[l]-f[r]) + dp[r]-dp[l])/(f[r]-f[l])
*/