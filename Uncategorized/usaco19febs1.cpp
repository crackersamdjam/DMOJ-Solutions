#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int n, a[MM];

int getmin(){
	int l = 0, r = 0, ans = n;
	while(r < n){
		int cnt = r-l+1;
		int space = a[r]-a[l]+1 - cnt;
		if(space <= n-cnt){
			if(cnt == n-1 and !space);
			else ans = min(ans, n-cnt);
			r++;
		}
		else{
			l++;
		}
	}
	return ans;
}

int getmax(){
	int all = a[n-1]-a[0]+1 - n; //# of free spaces
	all -= min(a[n-1]-a[n-2], a[1]-a[0])-1;
	return all;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	sort(a, a+n);
	cout<<getmin()<<'\n';
	cout<<getmax()<<'\n';
}