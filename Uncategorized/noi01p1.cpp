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
const int MM = 5e4+5;

int n, k, ans, par[MM], val[MM];
vector<int> v[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

void merge(int a, int b, int off){
	int fa = find(a), fb = find(b);
	if(fa == fb)
		return;
	if(size(v[fa]) < size(v[fb])){
		swap(v[fa], v[fb]);
		off = -off;
	}
	for(int i: v[fb]){
		v[fa].emplace_back(i);
		val[i] = (val[i]+off+9)%3;
	}
	par[fb] = fa;
}

int main(){
	scan(n, k);
	for(int i = 1; i <= n; i++){
		par[i] = i;
		val[i] = 0;
		v[i].emplace_back(i);
	}
	while(k--){
		int c, a, b;
		scan(c, a, b);
		if(a > n or b > n){
			ans++;
			continue;
		}
		int fa = find(a), fb = find(b);
		if(c == 1){
			if(fa == fb)
				ans += val[a] != val[b];
			else
				merge(a, b, val[a]-val[b]);
		}
		else{
			if(fa == fb)
				ans += (val[a]+1)%3 != val[b];
			else
				merge(a, b, val[a]+1-val[b]);
		}
	}
	print(ans);
}