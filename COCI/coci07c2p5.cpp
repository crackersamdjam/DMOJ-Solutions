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
using ll = long long;
const int MM = 1e4+5;

int n;
ll a[MM], dis[MM], mn[3], add[MM];

int main(){
	mn[0] = mn[1] = mn[2] = 1;
	scan(n);
	for(int i = 0; i < n; i++)
		scan(a[i]);

	for(int t = 0; t < 3; t++){
		for(int i = t, j = -1; !(i == t and j != -1); i = j){
			j = (i+3)%n;
			ll d = a[(i+2)%n]-a[(i+1)%n];
			dis[j] = dis[i]+d;
			mn[j%3] = min(mn[j%3], dis[j]);
		}
		if(n%3) break;
	}

	if(n%3){
		ll v = a[1] - (dis[1]+dis[2]+dis[0]);
		assert(v%3 == 0);
		v /= 3;
		for(int i = 0; i < n; i++)
			print(dis[i]+v);
	}
	else{
		ll v = a[1] - (dis[1]+dis[2]+dis[0]);
		for(int i = 0; i < 3; i++){
			mn[i]--; //positive integers only
			v -= -mn[i];
			add[i] += -mn[i];
		}
		add[0] += v;

		for(int i = 0; i < n; i++)
			print(dis[i]+add[i%3]);
	}
}