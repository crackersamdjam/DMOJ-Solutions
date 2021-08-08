#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int n, m;
string s, t;
vector<int> v[200];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s>>t;
	for(int i = 0; i < n; i++){
		v[s[i]].emplace_back(i);
	}
	int i = -1, cnt = 0;
	for(auto c: t){
		if(!size(v[c]))
			return cout<<-1,0;
		if(v[c].back() <= i){
			i = -1;
			cnt++;
		}
		auto it = upper_bound(all(v[c]), i);
		i = *it;
	}
	cout<<(long long)cnt*n + i + 1;
}