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
const int MM = 2005;

set<pair<int, int>> st;
int n, m, dp[MM][MM][2];
// if possible to cover [l, r] with current edge coming from 0/1 l/r

bool ok(int a, int b){
	if(a > n) a -= n;
	if(b > n) b -= n;
	if(a > b) swap(a, b);
	return st.count({a, b});
}

int go(int l, int r, bool t){
	int &ret = dp[l][r][t];
	if(l+1 >= r) return ret = 3;
	if(~ret) return ret;
	ret = 0;
	if(!t){
		if(ok(l, l+1) and go(l+1, r, 0))
			ret = 1;
		else if(ok(l, r-1) and go(l, r-1, 1))
			ret = 2;
	}
	else{
		if(ok(l+1, r) and go(l+1, r, 0))
			ret = 1;
		else if(ok(r-1, r) and go(l, r-1, 1))
			ret = 2;
	}
	return ret;
}

int main(){
	memset(dp, -1, sizeof dp);
	scan(n, m);
	while(m--){
		int a, b;
		scan(a, b);
		if(a > b) swap(a, b);
		st.insert({a, b});
	}

	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= i+n; j++){
			//both endpoints are at 1, so have not actually done rs yet
			//a covers [i, j-1], b covers [j, n]
			int a = go(i, j, 0), b = go(j-1, i+n, 1);
			if(a and b){
				vector<int> v;
				int l = i, r = j, t = 0;
				while(dp[l][r][t] != 3){
					if(dp[l][r][t] == 1){
						l++, t = 0;
						v.emplace_back(l);
					}
					else{
						r--, t = 1;
						v.emplace_back(r);
					}
				}
				reverse(all(v));
				v.emplace_back(i);

				l = j-1, r = i+n, t = 1;
				while(dp[l][r][t] != 3){
					if(dp[l][r][t] == 1){
						l++, t = 0;
						v.emplace_back(l);
					}
					else{
						r--, t = 1;
						v.emplace_back(r);
					}
				}
				for(int u: v)
					print(u);
				return 0;
			}
		}
	}
	print(-1);
}