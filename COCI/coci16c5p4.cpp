#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1005;

int n, m, adj[MM][MM];
int take[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	while(m--){
		int a, b; cin>>a>>b;
		adj[a][b] = adj[b][a] = 1;
	}
	for(int st = 1; st <= n; st++){
		int ok = 1;
		for(int j = 1; j <= n; j++){
			if(j != st and !adj[st][j]){
				ok = 0;
			}
		}
		if(!ok){
			//take or don't take st
			//don't take
			for(int i = 1; i <= n; i++){
				if(i != st and !adj[st][i]){
					take[i] = 1;
				}
			}
			ok = 1;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i != j and adj[i][j]^take[i]^take[j]^1){
						ok = 0;
					}
				}
			}
			if(ok){
				cout<<"DA\n";
				return 0;
			}

			//try only taking st
			ok = 1;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i != j and adj[i][j]^(i == st)^(j == st)^1){
						ok = 0;
					}
				}
			}
			if(ok){
				cout<<"DA\n";
				return 0;
			}

			cout<<"NE\n";
			return 0;
		}
	}
	cout<<"DA\n";
}