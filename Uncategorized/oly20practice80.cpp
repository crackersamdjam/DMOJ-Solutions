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
const int MM = 63;

int n, q, cnt[MM];
ll a[MM];
int b;

int main(){
	scan(n);
	while(n--){
		ll v;
		scan(v);
		for(int i = MM-1; i >= 0; i--){
			if(v&(1LL<<i)){
				if(a[i]){
					v ^= a[i];
				}
				else{
					a[i] = v;
					break;
				}
			}
		}
		if(v == 0)
			b = 1;
	}
	ll tot = 1;
	for(int i = MM-1; i >= 0; i--){
		if(a[i])
			tot <<= 1;
	}
	cnt[0] = !!a[0];
	for(int i = 1; i < MM; i++)
		cnt[i] = cnt[i-1] + !!a[i];

	scan(q);
	while(q--){
		ll k, ans = 0;
		scan(k);
		if(b){
			k--;
		}
		if(k >= tot){
			print(-1);
			continue;
		}
		for(int i = MM-1; i >= 0; i--){
			if(~cnt[i] and k&(1LL<<(cnt[i]-1))){
				ans = max(ans, ans^a[i]);
			}
			else{
				ans = min(ans, ans^a[i]);
			}
		}
		print(ans);
	}
	
}