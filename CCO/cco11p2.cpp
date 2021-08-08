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

int n, m, k, dis[1600];
vector<tuple<int, int, int>> adj[1600];

struct st{
	int u, d, c;
	bool operator<(const st &o) const{
		return c > o.c; //reversed
	}
};
priority_queue<st> q;
bool inq[1601];

int main(){
	scan(k, n, m);
	k++;
	while(m--){
		int a, b, c, d;
		scan(a, b, c, d);
		adj[a].emplace_back(b, c, c*d);
		adj[b].emplace_back(a, c, c*d);
	}
	memset(dis, 0x3f, sizeof dis);
	q.push({0, dis[0] = 0, 0});
	while(size(q)){
		auto [cur, curd, cc] = q.top(); q.pop();
		dis[cur] = min(dis[cur], curd);
		for(auto [a, b, c]: adj[cur]){
			if(cc+c < k and curd+b < dis[a])
				q.push({a, curd+b, cc+c});
		}
	}
	print(dis[n-1] == 0x3f3f3f3f ? -1 : dis[n-1]);
}