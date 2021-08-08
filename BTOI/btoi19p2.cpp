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
const int MM = 500;

int n, m, k;
bitset<MM*MM> cur, base, U, D, W, E;
char s[5005];

int main(){
	scan(n, m, k);
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		for(int j = 0; j < m; j++){
			if(s[j] == '.')
				base[i*m+j] = 1;
		}
	}
	cur = base;
	for(int i = 0; i < n; i++)
		for(int j = 1; j < m; j++)
			E[i*m+j] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m-1; j++)
			W[i*m+j] = 1;


	scanf("%s", s);
	for(int i = 0; i < k; i++){
		if(s[i] == 'N')
			cur = (cur>>m)&base;
		else if(s[i] == 'S')
			cur = (cur<<m)&base;
		else if(s[i] == 'W')
			cur = (cur>>1)&W&base;
		else if(s[i] == 'E')
			cur = (cur<<1)&E&base;
		else{
			cur = ((cur>>m)|(cur<<m)|((cur>>1)&W)|((cur<<1)&E))&base;
		}
	}
	print(cur.count());
}