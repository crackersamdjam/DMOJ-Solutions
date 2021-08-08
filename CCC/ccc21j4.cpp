#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 5e5+5;

string s, t;
int cnt[99][99];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>s;
	t = s;
	sort(all(t));
	for(int i = 0; i < size(s); i++){
		cnt[s[i]][t[i]]++;
	}

	int tot = size(s), ans = 0;

	for(auto a: {'L', 'M', 'S'}){
		tot -= cnt[a][a];
		for(auto b: {'L', 'M', 'S'}){
			if(a > b){
				int sub = min(cnt[a][b], cnt[b][a]);
				tot -= 2*sub;
				ans += sub;
			}
		}
	}
	assert(tot % 3 == 0);
	ans += tot/3*2;
	cout<<ans<<'\n';
}