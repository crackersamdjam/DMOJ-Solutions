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

int n, m, par[105];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

struct edge{
	int a, b, c, d;
	bool operator<(const edge &o) const{
		if(d != o.d)
			return d < o.d;
		return c < o.c;
	}
};
vector<edge> edges;

int main(){
	scan(n, m);
	for(int i = 1; i <= n; i++)
		par[i] = i;
	while(m--){
		int a, b, c, d;
		scan(a, b, c, d);
		edges.push_back({a, b, c, d});
	}
	sort(all(edges));
	int ans1 = 0, ans2 = 0;
	for(auto e: edges){
		int fa = find(e.a), fb = find(e.b);
		if(fa != fb){
			par[fa] = fb;
			ans1 += e.d;
			ans2 += e.c;	
		}
	}
	print(ans1, ans2);
}