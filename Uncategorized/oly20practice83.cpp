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

int n, k, a[16], all;
ll dp[16][1<<16], ans;
bool vis[16][1<<16];

ll go(int last, int mask){
	if(vis[last][mask])
		return dp[last][mask];
	if(mask == all)
		return 1;
	vis[last][mask] = 1;
	for(int l = 0; l < n; l++){
		if(!((mask>>l)&1) and abs(a[last]-a[l]) > k){
			dp[last][mask] += go(l, mask|(1<<l));
		}
	}
	return dp[last][mask];
}

int main(){
	scan(n, k);
	for(int i = 0; i < n; i++){
		scan(a[i]);
		all |= 1<<i;
	}
	for(int i = 0; i < n; i++)
		ans += go(i, 1<<i);
	print(ans);
}