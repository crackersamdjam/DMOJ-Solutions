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
const int MM = 1005;

int n, m, k;
ll a[MM], b[MM];
ll dp[MM];
struct ss{
	ll t, c, v; 
};
vector<ss> vec;

int main(){
	scan(n, m, k);
	for(int i = 1; i <= n; i++){
		scan(a[i], b[i]);
		vec.push_back({k, a[i], b[i]});
	}
	while(m--){
		int num, i, c, t;
		scan(num, i, c, t);
		vec.push_back({t, c, (ll)num*b[i]});
	}
	for(auto q: vec){
		for(int j = 0; j <= 10; j++){
			int f = 1<<j;
			if(q.t >= f){
				q.t -= f;
				ll c = q.c*f, v = q.v*f;
				for(int i = k; i >= c; i--)
					dp[i] = max(dp[i], dp[i-c]+v);
			}
		}
		for(int j = 10; j >= 0; j--){
			int f = 1<<j;
			while(q.t >= f){
				q.t -= f;
				ll c = q.c*f, v = q.v*f;
				for(int i = k; i >= c; i--)
					dp[i] = max(dp[i], dp[i-c]+v);
			}
		}
	}
	print(dp[k]);
}