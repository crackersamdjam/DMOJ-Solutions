#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

#if defined(LOCAL) && !defined(ONLINE_JUDGE)
#define RUN
#endif

using namespace std;
const int MM = 1e5+5;

int n, m;
int cnt;
set<pair<int, int>> good;

int askand(int a, int b){
	if(a > b)
		swap(a, b);

	assert(good.count({a, b}));

	cout<<"? "<<a<<" & "<<b<<endl;
	cnt++;
	assert(cnt < 2*n);

	#ifdef RUN
	return a&b;
	#endif

	int x;
	cin>>x;
	return x;
}

int askor(int a, int b){
	if(a > b)
		swap(a, b);

	assert(good.count({a, b}));

	cout<<"? "<<a<<" | "<<b<<endl;
	cnt++;
	assert(cnt < 2*n);
	
	#ifdef RUN
	return a|b;
	#endif

	int x;
	cin>>x;
	return x;
}

vector<int> adj[MM];

int par[MM];
int dep[MM];
int ans[MM];
bool done[MM];
int tmp[MM];

int sa, sb;

void dfs(int cur){
	for(int u: adj[cur]){
		if(!dep[u]){
			par[u] = cur;
			dep[u] = dep[cur]+1;
			dfs(u);
		}
		else if(dep[cur]%2 == dep[u]%2){
			sa = cur, sb = u;
		}
	}
}

int main(){
	cin>>n>>m;
	while(m--){
		int a, b;
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
		good.insert({a, b});
		good.insert({b, a});
	}
	for(int i = 1; i <= n; i++){
		if(!dep[i]){
			dep[i] = 1;
			sa = sb = 0;
			dfs(i);
			assert(sa);

			vector<int> ls, rs;
			while(sa != sb){
				if(dep[sa] > dep[sb]){
					ls.emplace_back(sa);
					sa = par[sa];
				}
				else{
					rs.emplace_back(sb);
					sb = par[sb];
				}
			}
			ls.emplace_back(sa);
			reverse(all(rs));
			ls.insert(ls.end(), all(rs));

			int sz = size(ls);
			assert(sz%2);
			int xorv = 0;
			int sum = 0;
			for(int i = 1; i < sz; i++){
				int o = askor(ls[i-1], ls[i]), a = askand(ls[i-1], ls[i]);
				tmp[i] = o^a;
				xorv ^= o^a;
				if(i%2)
					sum += o+a;
				else
					sum -= o+a;
			}
			int andv = askand(ls[0], ls[sz-1]);
			int orv = xorv^andv;
			int sumv = andv+orv;
			sum += sumv;

			assert(sum%2 == 0);
			ans[ls[0]] = sum/2;

			for(int i = 1; i < sz; i++){
				ans[ls[i]] = ans[ls[i-1]]^tmp[i];
			}

			queue<int> q;
			for(int i = 0; i < sz; i++){
				done[ls[i]] = 1;
				q.push(ls[i]);
			}

			while(size(q)){
				int cur = q.front(); q.pop();
				for(int u: adj[cur]){
					if(!done[u]){
						int xv = askand(cur, u)^askor(cur, u);
						ans[u] = ans[cur]^xv;
						done[u] = 1;
						q.push(u);
					}
				}
			}
		}
	}
	cout<<"!";
	for(int i = 1; i <= n; i++){
		assert(done[i]);
		cout<<' '<<ans[i];
	}
	cout<<endl;
}