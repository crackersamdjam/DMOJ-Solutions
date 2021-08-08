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
const int MM = 3005;
// const int MM = 55;
const ll mod = 1e9+7;

void add(ll &a, ll b){
	a += b;
	if(a >= mod) a -= mod;
}

int n;
pair<int, int> a[MM*2];
ll pre[MM*2][MM], suf[MM*2][MM];
// dp[index][how many smaller need to be taken]
ll f[MM];

int main(){
	scan(n);
	f[0] = 1;
	for(ll i = 1; i <= n; i++)
		f[i] = f[i-1]*i%mod;

	for(int i = 1; i <= n; i++){
		scan(a[i].first);
		a[i].second = 0;
	}
	for(int i = n+1; i <= 2*n; i++){
		scan(a[i].first);
		a[i].second = 1;
	}
	sort(a+1, a+2*n+1);
	for(int z = 0; z < 2; z++){
		pre[0][0] = 1;
		for(int i = 1; i <= 2*n; i++){
			if(a[i].second^z){ //hmmm
				for(int j = 0; j <= n; j++){
					//assign barn to cow
					add(pre[i][j], pre[i-1][j+1]*(j+1)%mod);
					//don't assign
					add(pre[i][j], pre[i-1][j]);
				}
			}
			else{
				for(int j = 0; j <= n; j++){
					//must add cpw
					if(j) add(pre[i][j], pre[i-1][j-1]);
				}
			}
		}
		swap(pre, suf);
		reverse(a+1, a+2*n+1);
	}
	ll ans = pre[2*n][0];
	//one case, all match

	for(int i = 1; i <= 2*n; i++){
		if(a[i].second){
			//skip this barn
			for(int j = 0; j <= n; j++){
				//same # of open/close on each side
				add(ans, pre[i-1][j]*suf[2*n-(i+1)+1][j]%mod * f[j] %mod);
			}
		}
	}
	print(ans);
}