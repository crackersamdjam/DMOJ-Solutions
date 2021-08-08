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
const ll mod = 1e9+7;
const int MM = 3e6+5;

ll ans;
int n, m, ea[MM], eb[MM];
vector<int> adj[MM];

int cnt(int a, int b){
	if(size(adj[a]) > size(adj[b]))
		swap(a, b);
	int ret = 0;
	auto l = adj[b].begin();
	for(int i: adj[a]){
		auto j = lower_bound(l, adj[b].end(), i);
		if(j == adj[b].end())
			break;
		ret += *j == i;
		l = j;
	}
	return ret;
}

int main(){
	scan(n, m);
	for(int i = 0; i < m; i++){
		scan(ea[i], eb[i]);
		adj[ea[i]].emplace_back(eb[i]);
		adj[eb[i]].emplace_back(ea[i]);
	}
	for(int i = 1; i <= n; i++)
		sort(all(adj[i]));
	
	for(int i = 0,a,b; i < m; i++){
		tie(a, b) = tie(ea[i], eb[i]);
		ans += cnt(a, b);
	}
	print(ans/3);
}