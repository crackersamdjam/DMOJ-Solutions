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
const int MM = 1e6+5;

int n, m, k;
int a[MM], b[MM];

bool go(int v){
	int l = 0;
	for(int i = 0; i < m; i++){
		int cnt = v;
		while(cnt-- and l < n and a[l] >= b[i] and a[l] <= b[i]+k)
			l++;
	}
	return l == n;
}

int main(){
	scan(n, m, k);
	for(int i = 0; i < n; i++){
		scan(a[i]);
	}
	for(int i = 0; i < m; i++){
		scan(b[i]);
	}
	sort(a, a+n);
	sort(b, b+m);

	int l = 0, r = n;
	while(l <= r){
		int mid = l+r>>1;
		if(go(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	print(l > n ? -1 : l);
}