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

int S, T, n, m, ea[MM], eb[MM], ans, t, tt, dfn[MM], low[MM];
vector<int> adj[MM], in[MM];
stack<pii> st;
set<int> art;

void process(int u, int v){
	if(st.empty()) return;
	tt++;
	while(st.size()){
		pii e = st.top(); st.pop();
		in[tt].push_back(e.first);
		in[tt].push_back(e.second);
		if(e == pii(u, v))
			break;
	}
}

void dfs(int cur, int pre){
	dfn[cur] = low[cur] = ++t;
	int ch = 0;
	for(int u: adj[cur]){
		if(u == pre) continue;
		if(!dfn[u]){
			ch++;
			st.emplace(cur, u);
			dfs(u, cur);
			
			low[cur] = min(low[cur], low[u]);
			
			if((pre == 0 && ch > 1) or (pre != 0 && low[u] >= dfn[cur])){
				art.insert(cur);
				process(cur, u);
			}
		}
		else
			low[cur] = min(low[cur], dfn[u]);
	}
}

int main(){
	scan(S, T);
	while(T--){
		scan(n, m);
		for(int i = 0; i < m; i++){
			scan(ea[i], eb[i]);
			adj[ea[i]].emplace_back(eb[i]);
			adj[eb[i]].emplace_back(ea[i]);
		}
		
		if(S == 1){
			dfs(1, 0);
			process(0, 0);
			for(int i = 1; i <= tt; i++){
				sort(all(in[i]));
				in[i].erase(unique(all(in[i])), in[i].end());
				int ins = 0, pts = 0;
				for(int j: in[i]){
					pts += art.count(j);
					for(int u: adj[j])
						ins += binary_search(all(in[i]), u);
				}
				if(ins/2 > size(in[i]))
					ans = 1;
			}
		}
		else if(S == 2){
			dfs(1, 0);
			process(0, 0);
			for(int i = 1; i <= tt; i++){
				sort(all(in[i]));
				in[i].erase(unique(all(in[i])), in[i].end());
				if(size(in[i]) >= 3)
					ans = 1;
			}
		}
		else if(S == 3){
			dfs(1, 0);
			process(0, 0);
			for(int i = 1; i <= tt; i++){
				sort(all(in[i]));
				in[i].erase(unique(all(in[i])), in[i].end());
				if(size(in[i]) >= 4)
					ans = 1;
			}
		}
		else if(S == 4){
			for(int i = 1; i <= n; i++)
				if(size(adj[i]) >= 3)
					ans = 1;
		}
		else if(S == 5){
			dfs(1, 0);
			process(0, 0);
			for(int i = 1; i <= tt; i++){
				sort(all(in[i]));
				in[i].erase(unique(all(in[i])), in[i].end());
				int ins = 0, pts = 0;
				for(int j: in[i]){
					pts += art.count(j);
					for(int u: adj[j])
						ins += binary_search(all(in[i]), u);
				}

				if(size(in[i]) < 3);
				else if(pts >= 2)
					ans = 1;
				else if(pts == 1 and ins/2 > size(in[i]))
					ans = 1;
				else if(pts == 0 and ins/2 > size(in[i])){

					if(size(in[i]) > 5 or (size(in[i]) == 5 and ins/2 >= size(in[i])+2))
						ans = 1;
					else if(size(in[i]) == 5){
						//check for edge case
						map<int, int> val;

						for(int j: in[i]){
							int cnt = 0;
							for(int u: adj[j])
								cnt += binary_search(all(in[i]), u);
							val[j] = cnt;
						}

						int yes = 0;

						for(int j: in[i]){
							for(int u: adj[j]){
								if(binary_search(all(in[i]), u)){
									if(val[u] == 2 and val[j] == 2)
										yes = 1;
								}
							}
						}
						if(yes)
							ans = 1;
					}
				}
			}
		}
		else abort();

		puts(ans ? "YES" : "NO");
		ans = t = tt = 0;
		art.clear();
		while(size(st))
			st.pop();
		for(int i = 0; i <= n; i++){
			adj[i].clear();
			in[i].clear();
			dfn[i] = low[i] = 0;
		}
	}
}

/*
Subtask 1
ans = if bcc of size n has more than n "interior" edges

Subtask 2
there exists cycle

Subtask 3
biconnected component has size >= 4

Subtask 4
node with 3 vertices

Subtask 5
articulation points can be a ear, if # art in cyc >= 2, then yes
other possibility:
interior edge in the cycle and sz >= 6 or (sz = 5 and is not edge case)
edge case is
1 2
2 3
3 4
4 1
1 5
5 3

if the 5 is in center, then no
this is true when no two bcc nodes with "interior" degree 2 are beside each other

*/