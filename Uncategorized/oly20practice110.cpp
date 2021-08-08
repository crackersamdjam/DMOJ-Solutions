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
const int MM = 3005;

int n, m, k, a[MM][MM], mx[MM][MM], mn[MM][MM], ans = 1e9;

int main(){
	scan(n, m, k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scan(a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		deque<pair<int, int>> minq, maxq;
		for(int j = 0; j < m; j++){
			while(size(minq) and minq.front().first <= j-k)
				minq.pop_front();
			while(size(minq) and minq.back().second > a[i][j])
				minq.pop_back();
			minq.emplace_back(j, a[i][j]);
			mn[i][j] = minq.front().second;

			while(size(maxq) and maxq.front().first <= j-k)
				maxq.pop_front();
			while(size(maxq) and maxq.back().second < a[i][j])
				maxq.pop_back();
			maxq.emplace_back(j, a[i][j]);
			mx[i][j] = maxq.front().second;
		}
	}
	for(int j = k-1; j < m; j++){
		deque<pair<int, int>> minq, maxq;
		for(int i = 0; i < n; i++){
			while(size(minq) and minq.front().first <= i-k)
				minq.pop_front();
			while(size(minq) and minq.back().second > mn[i][j])
				minq.pop_back();
			minq.emplace_back(i, mn[i][j]);

			while(size(maxq) and maxq.front().first <= i-k)
				maxq.pop_front();
			while(size(maxq) and maxq.back().second < mx[i][j])
				maxq.pop_back();
			maxq.emplace_back(i, mx[i][j]);

			if(i >= k-1){
				// print(i, j, maxq.front().second - minq.front().second);
				ans = min(ans, maxq.front().second - minq.front().second);
			}
		}
	}
	print(ans);
}