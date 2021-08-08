#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

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
using pii = tuple<int, int, int>;
constexpr int MM = 3e4+5, NN = (MM<<15);

#define val(b, a) ((b)|((a)<<15))

deque<pii> q;
int n, m, a[MM], b[MM];
vector<int> in[MM];
bitset<NN> vis;

int main(){
	scan(n, m);
	for(int i = 0; i < m; i++){
		scan(b[i], a[i]);
		in[b[i]].emplace_back(a[i]);
	}
	vis[val(b[0], a[0])] = 1;
	q.emplace_back(0, b[0], a[0]);
	while(size(q)){
		auto [dis, i, d] = q.front(); q.pop_front();
		if(i == b[1]){
			print(dis);
			return 0;
		}
		int u = i-d;
		if(u >= 0){
			if(!vis[val(u, d)]){
				vis[val(u, d)] = 1;
				q.emplace_back(dis+1, u, d);
			}
		}
		u = i+d;
		if(u < n){
			if(!vis[val(u, d)]){
				vis[val(u, d)] = 1;
				q.emplace_back(dis+1, u, d);
			}
		}
		for(int dd: in[i]){
			if(!vis[val(i, dd)]){
				vis[val(i, dd)] = 1;
				q.emplace_front(dis, i, dd);
			}
		}
		in[i].clear();
	}
	print(-1);
}