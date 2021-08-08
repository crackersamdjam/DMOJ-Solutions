#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 100;

int n;
int adj[MM][MM];
int vis[MM][2];

void dfs(int cur, bool turn){
	vis[cur][turn] = 1;
	if(turn){
		int u = 26-(cur-26);
		if(vis[u][0] == 1){
			cout<<"1\n";
			exit(0);
		}
		else if(!vis[u][0])
			dfs(u, 0);
	}
	else{
		for(int u = 0; u < MM; u++){
			if(adj[cur][u]){
				if(vis[u][1] == 1){
					cout<<"1\n";
					exit(0);
				}
				else if(!vis[u][1])
					dfs(u, 1);
			}
		}
	}
	vis[cur][turn] = 2;
}

void addedge(int a, int b){
	if(!a or !b) return;
	a += 26, b += 26;
	adj[a][b] = adj[b][a] = 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int t = 0; t < n; t++){
		vector<int> v(4);
		for(int &a: v)
			cin>>a;

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(i != j)
					addedge(v[i], v[j]);
			}
		}
	}

	for(int i = 0; i <= 52; i++){
		if(!vis[i][1])
			dfs(i, 1);
	}

	cout<<"0\n";
}