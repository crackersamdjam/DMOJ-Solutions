#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e6+5, LOG = 31;

int n, q, a[MM], cnt[LOG][2];

void up(int i, int c){
	int l = a[i-1], r = a[i];
	int h = l^r;
	if(!h or i == 1) return;
	h = __lg(h);
	cnt[h][l > r] += c;
}

int getans(){
	int ans = 0;
	for(int i = LOG-1; i >= 0; i--){
		if(cnt[i][0] and cnt[i][1])
			return -1;
		if(cnt[i][1])
			ans |= 1<<i;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	a[n+1] = 2e9+1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		up(i, 1);
	}
	cin>>q;
	cout<<getans()<<'\n';
	while(q--){
		int i;
		cin>>i;
		up(i, -1);
		up(i+1, -1);
		cin>>a[i];
		up(i, 1);
		up(i+1, 1);
		cout<<getans()<<'\n';
	}
}