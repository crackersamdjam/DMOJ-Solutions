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


int q, n, m, sum;
bitset<150001> dp;

int main(){
	scan(q, n, m);
	dp[0] = 1;
	for(int i = 0,a; i < n; i++){
		scan(a);
		sum += a;
		dp |= dp<<a;
	}

	if(sum >= q){
		print(q - !dp[q]);
		return 0;
	}

	vector<int> v(m);
	for(int &i: v)
		scan(i);
	sort(all(v));

	int ans;
	for(int i = q; i; i--){
		if(dp[i]){
			ans = i;
			break;
		}
	}
	int rem = q-ans;
	while(rem){
		int rm = v.back(); v.pop_back();
		int sub = min(rem, rm);
		rem -= sub;
		ans += sub-1;
	}
	print(ans);
}
/*
if can reach exactly by taking circles, ans = Q
else want to waste as little as possible, so get as high as possible
if only with circles, can > Q, then ans = Q-1
else keep taking largest lines reaches Q and calc ans during process
*/