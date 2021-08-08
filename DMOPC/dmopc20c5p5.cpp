#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int n, m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(__builtin_popcount(i+j)&1)
				cout<<'B';
			else
				cout<<'Y';
		}
		cout<<'\n';
	}
}