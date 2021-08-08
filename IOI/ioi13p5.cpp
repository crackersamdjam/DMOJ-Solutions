#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e6+5;

int n, m, k, x[MM], y[MM];
array<int, 2> a[MM];

bool go(int t){
	priority_queue<int> q;
	int l = 0;
	for(int i = 0; i < n; i++){
		while(l < k and a[l][0] < x[i])
			q.push(a[l++][1]);
		
		for(int j = 0; j < t and size(q); j++)
			q.pop();
	}
	while(l < k)
		q.push(a[l++][1]);

	for(int i = m-1; i >= 0; i--){
		for(int j = 0; j < t and size(q) and q.top() < y[i]; j++)
			q.pop();
	}
	return !size(q);
}

int putaway(int _n, int _m, int _k, int xx[], int yy[], int aa[], int ab[]){
	n = _n, m = _m, k = _k;
	for(int i = 0; i < n; i++){
		x[i] = xx[i];
	}
	for(int i = 0; i < m; i++){
		y[i] = yy[i];
	}
	for(int i = 0; i < k; i++){
		a[i] = {aa[i], ab[i]};
	}
	sort(x, x+n);
	sort(y, y+m);
	sort(a, a+k);
	int l = 0, r = k;
	while(l <= r){
		int mm = l+r>>1;
		if(go(mm))
			r = mm-1;
		else
			l = mm+1;
	}
	if(l > k) l = -1;
	return l;
}

#ifdef LOCAL
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;
	int xx[n+1], yy[m+1], aa[k+1], bb[k+1];
	for(int i = 0; i < n; i++)
		cin>>xx[i];
	for(int i = 0; i < m; i++)
		cin>>yy[i];
	for(int i = 0; i < k; i++)
		cin>>aa[i]>>bb[i];
	cout<<putaway(n, m, k, xx, yy, aa, bb)<<'\n';
}
#endif