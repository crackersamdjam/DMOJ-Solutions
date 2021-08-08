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

ll dp[22][11][11][2];
string s;

ll go(int i, int a, int b, bool f){
	if(i >= (int)s.size()) return 1;

	ll &ret = dp[i][a][b][f];
	if(~ret) return ret;
	ret = 0;

	if(b == 10){
		ret += go(i+1, 10, 10, 0);
	}
	int r = f ? (s[i]-'0') : 10;
	for(int c = (b == 10); c < r; c++){
		if(c != a and c != b)
			ret += go(i+1, b, c, 0);
	}
	if(r != a and r != b and r < 10)
		ret += go(i+1, b, r, 1);

	// print(i, s[i]-'0', a, b, (int)f, ret);
	return ret;
}

string a, b;
ll ans;

ll val(){
	memset(dp, -1, sizeof dp);
	ll v = stoll(s);
	if(v < 10)
		return v+1;

	return go(0, 10, 10, 1);
}

int main(){
	cin>>a>>b;
	a = to_string(stoll(a)-1);

	s = b;
	ll tot = val();
	
	s = a;
	tot -= val();

	print(tot);
}