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
const int MM = 1e5+1;

ll cnt[MM][200], ans, f;
int n, m;
string s, t;

int main(){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	cin>>n>>m>>s>>t;
	if(s.size() < t.size()){
		swap(s, t);
		swap(n, m);
	}
	ll gcd = __gcd(s.size(), t.size());
	ll lcm = s.size()*t.size()/gcd;
	for(int i = 0; i < s.size(); i++){
		cnt[i%gcd][s[i]]++;
	}
	for(int i = 0; i < t.size(); i++){
		ans += cnt[i%gcd][t[i]];
	}
	f = n/(t.size()/gcd);

	// print(ans, f);
	print(ans*f);
}