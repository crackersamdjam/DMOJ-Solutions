#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 2e5+5;

int n, k, a[MM], last[MM], in[MM];
vector<int> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		last[a[i]] = i;
	}
	for(int i = 0; i < n; i++){
		if(in[a[i]])
			continue;
		while(size(v) and v.back() >= a[i] and last[v.back()] >= i){
			in[v.back()] = 0;
			v.pop_back();
		}
		v.push_back(a[i]);
		in[a[i]] = 1;
	}
	// for(auto i: v)
		// cerr<<i<<' ';
	// cerr<<endl;
	assert(size(v) == k);
	for(int i = 0; i < k; i++){
		cout<<v[i]<<" \n"[i == k-1];
	}
}