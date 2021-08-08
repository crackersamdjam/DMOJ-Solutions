#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using st = array<array<bool, 5>, 4>;
const int MM = 1<<20;

int n, m, a, b, c;
bool no[MM];
int dis[MM], to[MM];
queue<int> q;

int encode(st arr){
	int v = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			v = (v<<1)|arr[i][j];
	return v;
}

st decode(int v){
	st arr;
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--)
			arr[i][j] = v&1, v >>= 1;
	}
	return arr;
}

int getnext(int cur){
	auto curarr = decode(cur);
	st nxarr;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int cnt = 0;
			for(int ii = max(0, i-1); ii <= min(n-1, i+1); ii++){
				for(int jj = max(0, j-1); jj <= min(m-1, j+1); jj++){
					if(ii == i and jj == j)
						continue;
					cnt += curarr[ii][jj];
				}
			}
			if(curarr[i][j])
				nxarr[i][j] = !(cnt < a or cnt > b);
			else
				nxarr[i][j] = (cnt > c);
		}
	}
	return encode(nxarr);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>a>>b>>c;
	st starr;
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		for(int j = 0; j < m; j++)
			starr[i][j] = s[j] == '*';
	}
	int start = encode(starr);

	for(int mask = 0; mask < (1<<(n*m)); mask++){
		to[mask] = getnext(mask);
		no[to[mask]] = 1;
	}
	
	memset(dis, 0x3f, sizeof dis);
	for(int mask = 0; mask < (1<<(n*m)); mask++){
		if(!no[mask]){
			dis[mask] = 0;
			q.emplace(mask);
		}
	}

	while(size(q)){
		auto cur = q.front(); q.pop();
		if(cur == start){
			cout<<dis[cur]<<'\n';
			exit(0);
		}
		int nx = to[cur];
		if(dis[nx] == 0x3f3f3f3f){
			dis[nx] = dis[cur]+1;
			q.emplace(nx);
		}
	}
	cout<<"-1\n";
}