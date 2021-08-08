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
using ld = long double;
const ld eps = 1e-9;

int n, l, r, x, y;
map<ld, int> mp;

int main(){
	scan(n, l, r, x, y);
	mp[l-eps] = 1;
	mp[r+eps] = -1;
	for(int t = 0; t < n; t++){
		int a, b, c, d;
		scan(a, b, c, d);

		ld ls, rs;
		if(a == x)
			ls = x;
		else{
			ld m = ld(y-b)/ld(x-a);
			ls = x-y/m;
		}

		swap(a, c);
		swap(b, d);
		if(a == x)
			rs = x;
		else{
			ld m = ld(y-b)/ld(x-a);
			rs = x-y/m;
		}

		if(ls > rs)
			swap(ls, rs);
		
		mp[ls]--, mp[rs]++;
	}
	ld ans = 0, last = -1e9;
	int cnt = 0;
	for(auto i: mp){
		if(cnt > 0)
			ans += i.first-last;
		last = i.first;
		cnt += i.second;
	}
	cout<<setprecision(10)<<ans<<'\n';
}