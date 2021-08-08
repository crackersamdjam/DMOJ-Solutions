#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int n, d, m;
vector<int> vd;
string s;

vector<int> adj[MM];
int dfn[MM], low[MM], t, id[MM];
bool ins[MM];
stack<int> stk;
vector<vector<int>> scc;

void dfs(int cur){
	dfn[cur] = low[cur] = ++t;
	stk.push(cur);
	ins[cur] = 1;
	
	for(auto u: adj[cur]){
		if(!dfn[u]){
			dfs(u);
			low[cur] = min(low[cur], low[u]);
		}
		else if(ins[u])
			low[cur] = min(low[cur], dfn[u]);
	}
	
	if(dfn[cur] == low[cur]){
		int u = -1;
		scc.emplace_back();
		while(u != cur){
			u = stk.top(); stk.pop();
			ins[u] = 0;
			id[u] = (int)size(scc);
			scc.back().emplace_back(u);
		}
	}
}

int take[MM];

int ma[MM], mb[MM];
char mca[MM], mcb[MM];

int main(){
	cin>>n>>d>>s>>m;
	for(int i = 0; i < n; i++){
		if(s[i] == 'x'){
			vd.emplace_back(i);
		}
		s[i] -= 'a';
	}
	for(int i = 0; i < m; i++){
		cin>>ma[i]>>mca[i]>>mb[i]>>mcb[i];
		ma[i]--, mb[i]--;
		// assert(mca[i] >= 'A' and mca[i] <= 'C');
		// assert(mcb[i] >= 'A' and mcb[i] <= 'C');
		mca[i] -= 'A', mcb[i] -= 'A';
	}
	
	// assert((int)size(vd) == d);

	for(int mask = 0; mask < (1<<d); mask++){

		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(id, 0, sizeof id);
		memset(ins, 0, sizeof ins);
		for(int i = 0; i < 2*n; i++){
			adj[i].clear();
		}
		scc.clear();

		for(int i = 0; i < d; i++){
			s[vd[i]] = (mask>>i)&1;
		}

		for(int i = 0; i < m; i++){
			int a = ma[i], b = mb[i];
			int ca = mca[i], cb = mcb[i];
			int ida = a*2+ca-(s[a] < ca);
			int idb = b*2+cb-(s[b] < cb);
			
			if(ca == s[a]){
				//will never happen, so ignore
				continue;
			}
			if(cb == s[b]){
				//then this should never happen
				//add a to !a
				adj[ida].emplace_back(ida^1);
			}
			else{
				adj[ida].emplace_back(idb);
				adj[idb^1].emplace_back(ida^1);
				//contrapositive
			}
		}

		for(int i = 0; i < 2*n; i++){
			if(!dfn[i]){
				dfs(i);
			}
		}
		int no = 0;
		memset(take, 0, sizeof take);
		for(int i = 0; i < n; i++){
			if(id[i*2] == id[i*2+1]){
				no = 1;
				break;
			}
			if(id[i*2] < id[i*2+1]){
				take[i] = 0;
			}
			else{
				take[i] = 1;
			}
		}

		if(!no){
			for(int i = 0; i < n; i++){
				int out = take[i];
				if(s[i] <= out)
					out++;
				cout<<char('A'+out);
			}
			cout<<'\n';
			return 0;
		}
	}
	cout<<"-1\n";
}