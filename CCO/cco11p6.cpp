#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ar = array<int, 2>;
const int MM = 1e4+5;

int n, m, k, ans;
vector<int> in[MM];

int main(){
	cin>>n>>m>>k;
	for(int i = 0,x,y; i < k; i++){
		cin>>x>>y;
		in[y].emplace_back(x);
	}
	for(int i = 0; i <= n; i++)
		in[m].emplace_back(i);

	for(int i = 0; i <= m; i++){
		sort(all(in[i]), greater<int>());
		in[i].emplace_back(0);
	}

	for(int i = 0; i <= n; i++){
		vector<ar> q;
		q.push_back({0, 0});
		for(int j = 0; j <= m; j++){
			if(size(in[j]) >= 2 and in[j].end()[-2] < i)
				in[j].pop_back();

			if(size(in[j]) and in[j].back() < i){
				int y = in[j].back();
				while(size(q) and q.back()[1] <= y){
					int l = size(q) > 1 ? q.end()[-2][0] : 0;
					ans = max(ans, (j-l)*(i-q.back()[1]));
					q.pop_back();
				}
				q.push_back({j, y});
			}
		}
	}
	cout<<ans<<'\n';
}