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
const int MM = 5005;

int n, m, k, a[MM];
int dp[MM][MM];
int win[MM], lose[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int j = 0; j < n; j++){
		cin>>a[j];
		lose[j]++;
	}
	for(int i = m-1; i >= 0; i--){
		for(int j = 0; j < n; j++){
			if(a[(j+1)%n] == a[j])
				dp[i][j] = win[(j+1)%n] ? 1 : 0;
			else
				dp[i][j] = lose[(j+1)%n] ? 1 : 0;
		}

		for(int j = 0; j < n; j++){
			win[j] += dp[i][j] == 1;
			lose[j] += dp[i][j] == 0;
			if(i+k <= m){
				win[j] -= dp[i+k][j] == 1;
				lose[j] -= dp[i+k][j] == 0;
			}
		}
	}
	for(int j = 0; j < n; j++)
		cout<<(1^dp[1][j]^a[j])<<' ';
}