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
using pii = pair<int, int>;
const int MM = 1e5+5;

int n, m, cnt[MM];
vector<pair<int, int>> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;

int travel_plan(int n, int m, int r[][2], int w[], int k, int e[]){
	for(int i = 0; i < m; i++){
		adj[r[i][0]].emplace_back(r[i][1], w[i]);
		adj[r[i][1]].emplace_back(r[i][0], w[i]);
	}
	for(int i = 0; i < k; i++){
		int u = e[i];
		q.emplace(0, u);
		q.emplace(0, u);
	}
	while(q.size()){
		int cur = q.top().second, curd = q.top().first; q.pop();
		if(++cnt[cur] != 2)
			continue;
		if(cur == 0)
			return curd;
		for(auto e: adj[cur]){
			q.emplace(curd+e.second, e.first);
		}
	}
	return -1;
}

#ifndef ONLINE_JUDGE
int main(){
	int N = 5, M = 4, K = 3, R[][2] = {{0, 1}, {0, 2}, {3, 2}, {2, 4}}, W[] = {2, 3, 1, 4}, P[] = {1, 3, 4};
	print(travel_plan(N, M, R, W, K, P));
}
#endif