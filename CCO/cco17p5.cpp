#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 2e5+5;

int n, psa[MM];
vector<int> v[MM];
priority_queue<int, vector<int>, greater<int>> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 0,a,b; i < n; i++){
		cin>>a>>b;
		v[a].emplace_back(b);
		psa[a]++;
	}
	for(int i = 1; i <= n; i++)
		psa[i] += psa[i-1];

	int ans = 0, cnt = 0, hi = 0;

	for(int i = n; i; i--){
		for(int j: v[i]){
			q.push(j);
			hi++;
		}
		while(cnt < i-psa[i-1]){
			cnt++;
			ans += q.top();
			q.pop();
		}
	}

	cout<<ans<<'\n';
}