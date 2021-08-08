#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
const int MM = 2e5+5;

int n, par[MM], val[MM], noa, nob, no[MM];
char s[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

vector<tuple<int, int, int>> v;

int main(){
	scan(n, n);
	scanf("%s", s);
	for(int i = 0; i < n; i++){
		par[i] = i;
		val[i] = s[i]-'0';
	}
	for(int i = 0,a,b,c; i < n-3; i++){
		scan(a, b, c);
		v.emplace_back(a-1, b-1, c);
	}
	sort(all(v), [](auto x, auto y){
		return abs(get<1>(x)-get<0>(x)) < abs(get<1>(y)-get<0>(y));
	});

	for(auto i: v){
		int a, b, c, m;
		tie(a, b, c) = i;
		if(a != find(a) or b != find(b))
			noa = 1;

		// a = find(a), b = find(b);
		m = find((a+1)%n);
		if(find((m+1)%n) != b){
			swap(a, b);
			m = find((a+1)%n);
		}
		// print(a, m, b, find((m+1)%n));
		if(find((m+1)%n) != b)
			noa = 1;
		
		if(val[a]+val[m]+c != 6 or val[a] == val[m] or val[m] == c or val[a] == c)
			nob = 1;
		
		par[m] = b;
		val[a] = c;
	}

	if(noa)
		puts("neispravna triangulacija");
	else if(nob)
		puts("neispravno bojenje");
	else
		puts("tocno");
}