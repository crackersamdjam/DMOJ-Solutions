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

int n, m, v, ans;
string s;
int k[2] = {0, (1LL<<31)-1};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>s>>v;
		for(int j = 0; j < 2; j++){
			if(s == "AND")
				k[j] &= v;
			if(s == "OR")
				k[j] |= v;
			if(s == "XOR")
				k[j] ^= v;
		}
	}
	for(int i = 31; i >= 0; i--){
		if(k[0]&(1<<i))
			ans |= (1<<i);
		else if((k[1]&(1<<i) and (1<<i) <= m))
			ans |= (1<<i), m -= (1<<i);
	}
	cout<<ans;
}