// S5 solution in O(N log N)
#include <bits/stdc++.h>
using namespace std;
constexpr int MM = 1e6+2;

int n, a[MM];
map<int, int> mp;
double dp[MM], suf;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a+i);
	
	if(a[1] == a[n])
		return printf("1\n"), 0;

	mp[a[n]] = n;
	
	for(int i = n-1; i > 1; i--){
		if(a[i] == a[1]){
			dp[i] = 1;
			mp[a[i]] = i;
		}
		else if(mp[a[i]])
			dp[i] = dp[mp[a[i]]];
		else
			dp[i] = (suf+1)/(n-i+1);
		
		mp[a[i]] = i;
		suf += dp[i];
	}
	
	printf("%.8lf\n", accumulate(dp+2, dp+n, 1.0)/n);
}