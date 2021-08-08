#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+2;

int n, cur, pre = 1;
ll t;
bool s[2][MM];

ll norm(ll x){
	return (x%n+n)%n;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    
    scan(n, t);

    for(int i = 0; i < n; i++)
    	s[0][i] = gc-'0';

    for(int i = 0; i < 64; i++){
    	if((t>>i)&1){
    		swap(cur, pre);
    		for(int j = 0; j < n; j++){
    			s[cur][j] = s[pre][norm(j-(1LL<<i))] ^ s[pre][norm(j+(1LL<<i))];
    		}
    	}
    }

    for(int i = 0; i < n; i++)
    	pc(s[cur][i]+'0');
    
    return 0;
}