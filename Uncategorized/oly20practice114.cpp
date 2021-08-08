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
const int MM = 1e5+5, LOG = 17;

int n, m, a[MM], sp[LOG][MM];

int query(int l, int r){
	if(l == r)
		return sp[0][l];
	int k = __lg(r-l+1);
	return max(sp[k][l], sp[k][r-(1<<k)+1]);
}

int main(){
	// memset(sp, 0x3f, sizeof sp);
	scan(n);
	for(int i = 1; i <= n; i++){
		scan(sp[0][i]);
	}

	for(int i = 1; i < LOG; i++){
		for(int j = 1; j+(1<<i)-1 <= n; j++){
			sp[i][j] = max(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
		}
	}

	for(int i = 1; i <= n; i++){
		int mx = 0;
		int r = i;
		for(int j = 1; ; j++){
			int l = max(1, i-j*j);
			int res = query(l, r-1);
			mx = max(mx, res+j);

			if(l <= 1) break;
			r = l;
		}
		r = i;
		for(int j = 1; ; j++){
			int l = min(n, i+j*j);
			int res = query(r+1, l);
			mx = max(mx, res+j);

			if(l >= n) break;
			r = l;
		}
		print(max(0, mx-sp[0][i]));
	}
}