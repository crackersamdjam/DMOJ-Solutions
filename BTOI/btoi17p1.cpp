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
using pii = pair<int, int>;
const int MM = 5e4+5;

int n, k, ans;
set<int> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
bool vis[MM];

int main(){
	scan(n, k);
	for(int i = 0,d,j; i < n; i++){
		scan(d);
		while(d--){
			scan(j);
			adj[i].insert(j);
			// print(i, j);
		}
	}
	for(int i = 0; i < n; i++)
		q.emplace(adj[i].size(), i);

	while(q.size()){
		int cur = q.top().second; q.pop();
		if(vis[cur])
			continue;
		vis[cur] = 1;
		assert(adj[cur].size() < k);
		vector<int> all, in;
		for(int i: adj[cur])
			all.emplace_back(i);
		
		for(int mask = 0; mask < (1<<all.size()); mask++){
			in.clear();
			for(int i = 0; i < all.size(); i++){
				if(mask&(1<<i)){
					for(int j: in){
						if(!adj[all[i]].count(j))
							goto no;
					}
					in.emplace_back(all[i]);
				}
			}
			ans = max(ans, (int)in.size()+1);
			no:;
		}

		for(int i: all){
			adj[i].erase(adj[i].find(cur));
			q.emplace(adj[i].size(), i);
		}
	}

	print(ans);
}