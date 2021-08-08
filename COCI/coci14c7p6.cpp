#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1005;

int n, m, a[MM][MM], b[MM][MM], ans, ok[MM*MM], okk;
array<int, 2> dest[MM*MM];
int par[MM], sz[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

void merge(int fa, int fb){
	fa = find(fa), fb = find(fb);
	if(fa == fb)
		return;
	par[fa] = fb;
	ok[fb] |= ok[fa];
	sz[fb] += sz[fa];
}

int getlis(vector<int> &v){
	vector<int> lis;
	for(int i: v){
		if(!size(lis) or i > lis.back()){
			lis.emplace_back(i);
		}
		else{
			*lower_bound(all(lis), i) = i;
		}
	}
	return size(lis);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>a[i][j];
			if(!a[i][j]){
				ok[i] = 1;
				okk = 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>b[i][j];
			dest[b[i][j]] = {i, j};
		}
	}
	iota(par, par+n, 0);
	fill(sz, sz+n, 1);
	for(int i = 0; i < n; i++){
		vector<int> c;
		for(int j = 0; j < m; j++){
			int v = a[i][j];
			if(!v) continue;
			if(dest[v][0] == i){
				c.emplace_back(dest[v][1]);
			}
			else{
				ans++;
				merge(i, dest[v][0]);
			}
		}
		ans += (int)size(c) - getlis(c);
		if(size(c) == m and !is_sorted(all(c)))
			ans++;
	}

	for(int i = 0; i < n; i++){
		if(find(i) == i){
			if(!ok[i] and sz[i] > 1)
				ans++;
		}
	}

	if(ans and !okk)
		ans = -1;
	cout<<ans<<'\n';
}