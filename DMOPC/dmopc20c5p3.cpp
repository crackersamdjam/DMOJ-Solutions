#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e6+5;

int n, k;
int inr[MM], inc[MM];
int mx[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	while(k--){
		int a, b; cin>>a>>b;
		inr[a] = b;
		inc[b] = a;
	}

	int c = 1;
	for(int i = 1; i <= n; i++){
		if(inr[i] and inr[i] >= c-1){
			c = inr[i];
			mx[c] = max(mx[c], i);
		}
		else break;
	}

	int r = n;
	for(int i = n; i > 0; i--){
		if(inc[i] and inc[i] <= r+1){
			r = inc[i];
			mx[i] = max(mx[i], r);
		}
		else break;
	}

	mx[n+1] = n-1;
	for(int i = 1; i <= n; i++){
		mx[i] = max(mx[i], mx[i-1]);
	}

	if(mx[1] or mx[n] >= n){
		cout<<"IMPOSSIBLE\n";
		exit(0);
	}

	int i = 1, j = 1;
	string ans;

	while(i+j < n+n){
		if(j <= mx[i+1]){
			ans += 'U';
			j++;
		}
		else{
			ans += 'R';
			i++;
		}
	}
	cout<<ans<<'\n';
}