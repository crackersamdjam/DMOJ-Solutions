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
const int MM = 50005;

int n, m;
ll k;
ll dp[MM][11][5];
char s[MM];

map<char, int> mp;

ll go(int i, int j, int l){
	if(i > n)
		return 0;
	if((i and l >= 4) or j > m)
		return 0;
	if(i and (s[i] != 'N' and mp[s[i]] != l))
		return 0;
	if(i == n)
		return 1;
	ll &ret = dp[i][j][l];
	if(~ret)
		return ret;
	ret = 0;
	for(int c = 0; c < l; c++)
		ret += go(i+1, j+1, c);
	for(int c = l; c < 4; c++)
		ret += go(i+1, j, c);
	
	return ret;
}

char let[] = {'A','C','G','T'};

void find(int i, int j, int l){
	if(i)
		pc(let[l]);
	if(i == n)
		return;

	for(int c = 0; c < l; c++){
		ll v = go(i+1, j+1, c);
		if(v and k <= v){
			find(i+1, j+1, c);
			return;
		}
		k -= v;
	}
	for(int c = l; c < 4; c++){
		ll v = go(i+1, j, c);
		if(v and k <= v){
			find(i+1, j, c);
			return;
		}
		k -= v;
	}
	cout<<flush;
	abort();
}

int main(){
	memset(dp, -1, sizeof dp);
	mp['A'] = 0;
	mp['C'] = 1;
	mp['G'] = 2;
	mp['T'] = 3;
	scan(n, m, k);
	scanf("%s", s+1);
	go(0, 0, 4);
	find(0, 0, 4);
}