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
const int MM = 2005;

int n, q, a[MM];
vector<pair<int, int>> v;

void go(int l, int r){
	if(l < r){
		reverse(a+l, a+r+1);
		v.emplace_back(l, r);
	}
}

int main(){
	scan(n, q);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	for(int i = 1; i < n; i++){
		int id = lower_bound(a, a+i, a[i])-a;
		go(id, i-1);
		go(id, i);
	}
	print(v.size());
	for(auto i: v)
		print(i.first+1, i.second+1);
	// for(int i = 0; i < n; i++)
		// cout<<a[i]<<' ';
}
/*
sliding window
4fecta edwardweary
*/