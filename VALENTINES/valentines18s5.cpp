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
const int MM = 1e6+5, MN = 1e5+1;

long long ans;
int n, k, a[MM], b[MM], f[MM];

void go(int l, int r){
	if(l == r){
		ans += f[a[l]] == k;
		return;
	}
	
	int m = (l+r)/2;
	b[m+1] = a[m+1];
	for(int i = m+2; i <= r; i++)
		b[i] = __gcd(b[i-1], a[i]);

	int cur = 0, ll = r, rr = r;
	for(int i = m; i >= l; i--){
		cur = __gcd(cur, a[i]);
		while(ll > m and f[__gcd(cur, b[ll])] <= k) //keep going until too high
			ll--;
		while(rr > m and f[__gcd(cur, b[rr])] < k) //keep going until works
			rr--;
		ans += rr-ll;
	}
	go(l, m);
	go(m+1, r);
}

int main(){
	for(int i = 2; i < MN; i++){
		int rem = i;
		for(int j = 2; j*j <= rem; j++){
			while(rem%j == 0){
				rem /= j;
				f[i]++;
			}
		}
		f[i] += rem > 1;
	}
	scan(n, k);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	go(0, n-1);
	print(ans);
}