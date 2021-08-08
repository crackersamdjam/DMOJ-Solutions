#include <bits/stdc++.h>

using namespace std;

int n, q, t[200000];

void build(){
	for(int i = n-1; i; i--)
		t[i] = min(t[i<<1], t[i<<1|1]);
}

void up(int i, int x){
	for(t[i+=n] = x; i; i >>= 1)
		t[i>>1] = min(t[i], t[i^1]);
}

int qu(int l, int r){
	static int x;
	for(x = INT_MAX, l += n, r += n; l < r; l >>= 1, r >>= 1){
		if(l&1) x = min(x, t[l++]);
		if(r&1) x = min(x, t[--r]);
	}
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	cin>>n>>q;
	for(int i = n; i < 2*n; i++)
		cin>>t[i];
	build();

	char c;	int l, r;
	while(q--){
		cin>>c>>l>>r;
		if(c == 'M'){
			up(l, r);
		}
		else{
			cout<<qu(l, r+1)<<'\n';
		}
	}
}