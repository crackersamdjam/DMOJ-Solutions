#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 3e5+5;

ll ans;
int n, k;
string s, t;

struct SuffixAutomaton{
	struct st{
		int len, par;
		int cnt[2];
		map<char, int> ch;
		vector<int> adj;
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
	
	void extend(char c, int type){
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
		last = cur;
		if(type != -1){
			v[cur].cnt[type]++;
		}
	}
	void build(){
		for(int i = 1; i <= sz; i++){
			v[v[i].par].adj.emplace_back(i);
		}
	}

	void dfs(int cur){
		for(int u: v[cur].adj){
			dfs(u);
			v[cur].cnt[0] += v[u].cnt[0];
			v[cur].cnt[1] += v[u].cnt[1];
		}
		if(cur){
			int len = min(k, v[cur].len);
			int sub = min(v[cur].cnt[0], v[cur].cnt[1]);
			ans += (ll)len*sub;
			v[cur].cnt[0] -= sub;
			v[cur].cnt[1] -= sub;
		}
	}

} sam;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	sam.init(MM);
	cin>>n>>k;
	cin>>s>>t;
	reverse(all(s));
	reverse(all(t));
	for(int i = 0; i < k-1; i++)
		sam.extend(s[i], -1);
	for(int i = k-1; i < n; i++)
		sam.extend(s[i], 0);

	for(int i = 0; i < k-1; i++)
		sam.extend(t[i], -1);
	for(int i = k-1; i < n; i++)
		sam.extend(t[i], 1);

	sam.build();
	sam.dfs(0);

	ans = (ll)k*(n-k+1) - ans;
	cout<<ans<<'\n';
}