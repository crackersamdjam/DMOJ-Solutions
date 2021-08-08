#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 2e5+5;

int t, n, A, B, c[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n>>A>>B;
		priority_queue<pair<int, int>> q;
		int ans = 0;
		for(int i = 1; i <= A; i++)
			cin>>c[i];
		sort(c+1, c+A+1);

		for(int i = 2; i <= A; i++){
			int l = c[i]-1-c[i-1];
			q.emplace((l+1)/2, l);
		}
		q.emplace(c[1]-1, 0);
		q.emplace(n-c[A], 0);

		while(size(q) and B--){
			auto [v, w] = q.top(); q.pop();
			ans += v;
			if(w == INT_MAX){
				q.emplace(1, 0);
			}
			else if(w){
				if(w%2){
					if(w > 1){
						q.emplace(w-v-1, INT_MAX);
					}
				}
				else{
					q.emplace(w-v, 0);
				}
			}
		}
		cout<<ans<<'\n';
	}
}