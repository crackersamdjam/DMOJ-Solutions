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
using ll = long long;
constexpr int MM = 2005;
const ll base = 131;

int n, m, a[MM][MM];
ll l[MM][MM], r[MM][MM], u[MM][MM], d[MM][MM], p[MM];
pair<int, pair<int, int>> ans;

bool go(int i, int j, int k){
	if(i <= k or j <= k or i+k > n or j+k > m)
		return 0;
	ll lh = l[i][j-1]-l[i][j-k-1]*p[k];
	ll rh = r[i][j+1]-r[i][j+k+1]*p[k];
	ll uh = u[i-1][j]-u[i-k-1][j]*p[k];
	ll dh = d[i+1][j]-d[i+k+1][j]*p[k];
	// print(i, j, k, lh, rh, uh, dh);
	return lh == rh and lh == uh and lh == dh;
}

int main(){
	scan(n, m);
	p[0] = 1;
	for(int i = 1; i < MM; i++)
		p[i] = p[i-1]*base;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scan(a[i][j]);
			l[i][j] = l[i][j-1]*base+a[i][j]+'0';
			u[i][j] = u[i-1][j]*base+a[i][j]+'0';
		}
	}
	for(int i = n; i; i--){
		for(int j = m; j; j--){
			r[i][j] = r[i][j+1]*base+a[i][j]+'0';
			d[i][j] = d[i+1][j]*base+a[i][j]+'0';
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int lo = 1, mid, hi = MM;
			while(lo <= hi){
				mid = (lo+hi)/2;
				if(go(i, j, mid))
					lo = mid+1;
				else
					hi = mid-1;
			}
			ans = max(ans, {hi, {i, j}});
		}
	}
	print(ans.first, ans.second.first, ans.second.second);
}