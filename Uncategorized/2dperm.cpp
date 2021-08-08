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
const int MM = 5005;

int n, m, q;
int psa[MM*MM];

int main(){
	scan(n, m, q);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int l = i*j, r = n*m-(n-i+1)*(m-j+1)+2;
			psa[l]++, psa[r]--;
			// print(i, j, l, r);
		}
	}
	for(int i = 1; i <= n*m; i++)
		psa[i] += psa[i-1];
	while(q--){
		int a;
		scan(a);
		print(psa[a]);
	}
}