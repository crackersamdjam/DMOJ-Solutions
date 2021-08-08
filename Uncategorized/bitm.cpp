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
const int MM = 4e6+5;

int n, l, r, dp[MM];
queue<int> q;

void go(int add){
	// pr("add", add);
	dp[add] = 0;
	q.emplace(add);
	while(q.size()){
		int cur = q.front(); q.pop();
		for(int i = 0; i < __lg(cur); i++){ //lg bc can not rm highest bit
			int ed = (1<<i)-1;
			ed &= cur;
			int st = (cur>>(i+1))<<i;
			int u = st|ed;
			if(dp[cur]+1 < dp[u]){
				dp[u] = dp[cur]+1;
				q.emplace(u);
			}	
		}
	}
}
vector<pair<int, int>> v[MM];
int ans[MM];

int main(){
	memset(dp, 0x3f, sizeof dp);
	memset(ans, 0x3f, sizeof ans);
	scan(n, l, r);
	for(int i = 0,a,b; i < n; i++){
		scan(a, b);
		v[min(r, a+b)].push_back({a, i});
	}

	for(int i = l; i <= r; i++){
		go(i);
		for(auto j: v[i])
			ans[j.second] = dp[j.first];
	}
	for(int i = 0; i < n; i++)
		print(ans[i] < 0x3f3f3f3f ? ans[i] : -1);
}