#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n, a[MM], l[MM], r[MM], best[MM];
ll psa[MM], s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>s;
	l[0] = 1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		psa[i] = psa[i-1]+a[i];
		l[i] = l[i-1];
		while(psa[i-1]-psa[l[i]-1] > s){
			l[i]++;
		}
	}
	r[n+1] = n;
	for(int i = n; i; i--){
		r[i] = r[i+1];
		while(psa[r[i]]-psa[i-1] > s){
			r[i]--;
		}
	}
	for(int i = 1; i <= n; i++){
		int len = min(r[i]-i+1, i-l[i]);
		int ls = max(1, i-len);
		best[ls] = max(best[ls], i);
	}
	for(int i = 1; i <= n; i++){
		best[i] = max(best[i], best[i-1]);
		int len = best[i]-i;
		cout<<len*2<<'\n';
	}
}