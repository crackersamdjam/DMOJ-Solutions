#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, LOG = 18;

int n, m, a[MM], sp[LOG][MM];

int query(int l, int r){
	int k = __lg(r-l+1);
	return max(sp[k][l], sp[k][r-(1<<k)+1]);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>sp[0][i];
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j+(1<<i)-1 <= n; j++){
			sp[i][j] = max(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
		}
	}
	while(m--){
		int l, r;
		cin>>l>>r;
		cout<<query(l, r)<<'\n';
	}
}