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
const int MM = 1e6+5, LOG = 20;

int n, q, k, cnt[MM];
char s[MM];
ll a[MM], psa[MM], sp[LOG][MM];

ll qu(int l, int r){
	int i = __lg(r-l+1);
	return max(sp[i][l], sp[i][r-(1<<i)+1]);
}

int main(){
	scan(n, q, k);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		psa[i] = a[i]+psa[i-1];
		sp[0][i] = max(0LL, a[i]*a[i-1]-a[i]-a[i-1]);
	}
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			sp[i][j] = max(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
		}
	}
	scanf("%s", s+1);
	for(int i = 1; i <= n; i++){
		cnt[i] = cnt[i-1] + (s[i] == 'E');
	}
	int l, r;
	while(q--){
		scan(l, r);
		if(cnt[r]-cnt[l-1] < k){
			puts("Not enough oils!");
			continue;
		}
		ll s = psa[r]-psa[l-1];
		if(l^r) s += qu(l+1, r);
		print(s);
	}
}