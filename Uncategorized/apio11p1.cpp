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
using pii = pair<int, int>;
const ll mod = 1e9;
const int MM = 4e5+5;

int n, m, k, par[MM];
ll ans = 1;

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

void merge(int a, int b){
	a = find(a), b = find(b);
	par[a] = b;
}

int main(){
	scan(n, m, k);
	for(int i = 1; i <= 2*(n+m); i++)
		par[i] = i;
	for(int i = 0,x,y,v; i < k; i++){
		scan(x, y, v);
		if(x%2 == 0 and y%2 == 0)
			v ^= 1;
		if(v){
			merge(x+n+m, y+n);
			merge(x, y+n+m+n);
		}
		else{
			merge(x, y+n);
			merge(x+n+m, y+n+n+m);
		}
	}
	int f = 0;

	for(int i = 1; i <= (n+m); i++){
		// print(i, find(i), find(i+n+m));
		if(find(i) == find(i+n+m)){
			print(0);
			exit(0);
		}
	}
	
	for(int i = 1; i <= (n+m); i++)
		merge(i, i+n+m);

	for(int i = 1; i <= 2*(n+m); i++){
		if(find(i) == i){
			if(f)
				ans = ans*2%mod;
			f = 1;
		}
	}

	print(ans);
}