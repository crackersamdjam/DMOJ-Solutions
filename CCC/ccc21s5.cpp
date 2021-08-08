#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 150005, LOG = 18;

int n, m;
int dif[MM][17];
int cnt[17];
int l[MM], r[MM], x[MM];
int sp[LOG][MM];

int get(int ll, int rr){
	int k = __lg(rr-ll+1);
	return __gcd(sp[k][ll], sp[k][rr-(1<<k)+1]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		cin>>l[i]>>r[i]>>x[i];
		dif[l[i]][x[i]]++;
		dif[r[i]+1][x[i]]--;
	}
	for(int i = 1; i <= n; i++){
		int lcm = 1;
		for(int j = 0; j < 17; j++){
			cnt[j] += dif[i][j];
			if(cnt[j]){
				lcm = lcm*j/__gcd(lcm, j);
			}
		}
		sp[0][i] = lcm;
	}
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j+(1<<i)-1 <= n; j++){
			sp[i][j] = __gcd(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
		}
	}

	for(int i = 0; i < m; i++){
		int v = get(l[i], r[i]);
		if(v != x[i]){
			cout<<"Impossible\n";
			return 0;
		}
	}

	for(int i = 1; i <= n; i++){
		cout<<sp[0][i]<<' ';
	}
}