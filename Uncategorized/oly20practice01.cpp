#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

struct stt{
	int len, par, maxlen;
	bool isclone;
	map<char, int> ch;
	vector<int> adj;
};

vector<stt> v;
int sz, last;
const int MM = 4e5+5;
int n;
string s;
int ans[MM];
int id[MM];

void init(int n){
	v.resize(n*2);
	v[0].len = 0; //0 is the root
	v[0].par = -1;
	sz = 1;
	last = 0;
}

void extend(char c, int i){
	int cur = sz++;
	v[cur].len = v[last].len+1;
	assert(!id[v[cur].len]);
	id[v[cur].len] = i;

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

			v[clone].isclone = 1;
			v[clone].maxlen = v[o].maxlen;

			while(p != -1 and v[p].ch[c] == o){
				//redirect all these to clone
				v[p].ch[c] = clone;
				p = v[p].par;
			}
			v[o].par = v[cur].par = clone;
		}
	}
	last = cur;
}

int dfs(int cur){
	int lo = 1e9;
	if(!v[cur].isclone)
		lo = v[cur].len;

	for(auto u: v[cur].adj){
		int a = dfs(u);
		if(a != 1e9 and lo != 1e9 and id[a] != id[lo])
			lo = 0;
		lo = min(lo, a);
	}
	if(lo != 1e9 and id[lo]){
		int i = id[lo];
		int len = max(0, min(v[cur].len, v[cur].maxlen)-v[v[cur].par].len);
		ans[i] += len;
	}
	return lo;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	init(MM+n);
	for(int i = 1; i <= n; i++){
		cin>>s;
		extend('#', 0);
		int j = 0;
		for(auto c: s){
			v[sz].maxlen = ++j;
			extend(c, i);
		}
	}
	for(int i = 1; i < sz; i++){
		v[v[i].par].adj.emplace_back(i);
		int cur = i;
		int len = max(0, min(v[cur].len, v[cur].maxlen)-v[v[cur].par].len);
	}
	dfs(0);

	for(int i = 1; i <= n; i++)
		cout<<ans[i]<<'\n';
}