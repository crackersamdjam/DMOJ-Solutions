// S1 solution in O(N log N)
#include <bits/stdc++.h>
using namespace std;

pair<double, double> a[100005];
int n;
double ans = 0;

int main(){
	cin>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i].first>>a[i].second;
	sort(a, a+n);
	for(int i = 1; i < n; i++){
		ans = max(ans, abs(a[i].second-a[i-1].second)/(a[i].first-a[i-1].first));
	}
	cout<<fixed<<setprecision(9)<<ans;
}