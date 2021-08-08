#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n, m;
ll b1[MM], b2[MM], a[MM];

void update(int i, int v, ll *bit){
	for(; i < MM; i += i&-i)
		bit[i] += v;
}
ll query(int i, ll *bit){
	ll ret = 0;
	for(; i; i-= i&-i)
		ret += bit[i];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		update(i, a[i], b1);
		update(a[i], 1, b2);
	}
	while(m--){
		char op; int i, l, r, v;
		cin>>op;
		if(op == 'C'){
			cin>>i>>v;
			update(i, v-a[i], b1);
			update(a[i], -1, b2);
			update(a[i] = v, 1, b2);
		}
		if(op == 'S'){
			cin>>l>>r;
			cout<<query(r, b1)-query(l-1, b1)<<'\n';
		}
		if(op == 'Q'){
			cin>>v;
			cout<<query(v, b2)<<'\n';
		}
	}

	
	return 0;
}