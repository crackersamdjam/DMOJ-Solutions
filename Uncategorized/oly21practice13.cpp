#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 5005;

int n, a[MM], at[MM];
int dp[MM];

struct BIT{
	int bit[MM];
	void up(int i, int v){
		for(i++; i < MM ; i += i&-i)
			bit[i] += v;
	}
	int qu(int i){
		int v = 0;
		for(i++; i; i -= i&-i)
			v += bit[i];
		return v;
	}
	void clear(){
		memset(bit, 0, sizeof bit);
	}
} lo, hi;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		at[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		dp[i] = 1e9;
		int hiadd = 0, loadd = 0;
		lo.clear();
		hi.clear();
		for(int j = 1; j <= i; j++)
			lo.up(at[j], 1);

		for(int j = i; j > 0; j--){
			hiadd += (i-j)-hi.qu(at[j]);
			//add non-inversions

			loadd -= hi.qu(at[j]);
			//remove old inversions
			
			hi.up(at[j], 1);
			lo.up(at[j], -1);

			loadd += j-1-lo.qu(at[j]);
			//add inversions

			dp[i] = min(dp[i], dp[j-1]+hiadd+loadd);
		}
	}

	cout<<dp[n]<<'\n';
}
/*
create "going down" segments
dp[i] = cost to get first i #s in a valid order
dp[i] = min(dp[j] + create new segment of [j+1, i])    ([j+1, i] in reversed order, of course)
*/