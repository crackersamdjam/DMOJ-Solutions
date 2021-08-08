#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5;

vector<int> adj[MM];
int n, d, ans;

int dfs(int cur, int pre){
	vector<int> v;
	for(int u: adj[cur]){
		v.emplace_back(dfs(u, cur));
	}
	int ret = 0;
	sort(all(v));
	for(int i: v){
		if(i+ret > d)
			ans--;
		else
			ret = i;
	}
	if(ret <= 0){
		ret = d;
		ans++;
	}
	return ret-1;
}

int main(){
	scan(n, d);
	for(int i = 1,p; i < n; i++){
		scan(p);
		adj[p].emplace_back(i);
	}
	dfs(0, -1);
	print(ans);
}