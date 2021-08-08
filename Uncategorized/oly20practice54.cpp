#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;

struct SuffixAutomaton{
	struct st{
		int len, par;
		ll cnt;
		map<char, int> ch;
	};
	vector<st> v;
	int sz, last;
	
	void init(int n){
		v.resize(n*2);
		v[0].len = 0; //0 is the root
		v[0].par = -1;
		sz = 1;
		last = 0;
	}
	
	int extend(char c){

		int cur = sz++;
		v[cur].len = v[last].len+1;
		int p = last;
		while(p != -1 && !v[p].ch.count(c)){
			v[p].ch[c] = cur;
			p = v[p].par;
		}
		if(p == -1){
			v[cur].par = 0;
		}
		else{
			int o = v[p].ch[c]; //"other"
			if(v[p].len+1 == v[o].len){
				v[cur].par = o;
			}
			else{
				int clone = sz++; //clone
				v[clone].ch = v[o].ch;
				v[clone].par = v[o].par;
				v[clone].len = v[p].len+1;
				while(p != -1 && v[p].ch[c] == o){
					//redirect all these to clone
					v[p].ch[c] = clone;
					p = v[p].par;
				}
				v[o].par = v[cur].par = clone;
			}
		}
		return last = cur;
	}
	
	ll getsz(int x){
		if(v[x].cnt)
			return v[x].cnt;
		for(auto i: v[x].ch)
			v[x].cnt += getsz(i.second);
		return ++v[x].cnt;
	}
} SAM;

const int MM = 1e5+5;
int n, C, c[MM];
vector<int> adj[MM];
int par[MM], id[MM];

void dfs(int cur, int pre){
	par[cur] = pre;
	id[cur] = SAM.extend(c[cur]);
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
	SAM.last = id[pre];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	SAM.init(MM*20);
	cin>>n>>C;
	for(int i = 1; i <= n; i++){
		cin>>c[i];
	}
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	vector<int> l;
	for(int i = 1; i <= n; i++){
		if(size(adj[i]) == 1){
			dfs(i, 0);
		}
	}
	auto ans = SAM.getsz(0)-1;
	cout<<ans<<'\n';
}