#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1505;

int n, m, k, ans, in[MM][MM], a[MM][MM], ul[MM][MM], dl[MM][MM], ur[MM][MM], dr[MM][MM];

inline bool ok(int i, int j){
	return i >= k and i <= n and j >= k and j <= m;
}

inline int get(int i, int j){
	assert(ok(i, j));
	return a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k];
}

void go(){
	memset(ul, -0x3f, sizeof ul);
	memset(ur, -0x3f, sizeof ur);
	memset(dl, -0x3f, sizeof dl);
	memset(dr, -0x3f, sizeof dr);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			a[i][j] += a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	for(int i = k; i <= n; i++){
		for(int j = k; j <= m; j++)
			ul[i][j] = max(get(i, j), max(ul[i-1][j], ul[i][j-1]));
		for(int j = m-k+1; j; j--)
			ur[i][j] = max(get(i, j+k-1), max(ur[i][j+1], ur[i-1][j]));
	}
	for(int i = n-k+1; i; i--){
		for(int j = k; j <= m; j++)
			dl[i][j] = max(get(i+k-1, j), max(dl[i+1][j], dl[i][j-1]));
		for(int j = m-k+1; j; j--)
			dr[i][j] = max(get(i+k-1, j+k-1), max(dr[i+1][j], dr[i][j+1]));
	}
	//split row
	for(int i = k; i <= n; i++){
		for(int j = k; j <= m; j++){
			ans = max(ans, get(i, j) + ur[i-k][1] + dr[i+1][1]);
		}
	}
	//split three blocks
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//cent is (i, j)
			ans = max(ans, ul[i][j] + ur[i][j+1] + dr[i+1][1]);
		}
	}
}

int main(){
	scan(n, m, k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scan(in[i][j]);
			a[i][j] = in[i][j];
		}
	go();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = in[n+1-i][m+1-j];
	go();
	swap(n, m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = in[j][i];
	go();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = in[m+1-j][n+1-i];
	go();

	print(ans);
}