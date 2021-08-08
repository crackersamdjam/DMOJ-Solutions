#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int n, ans;
string s;
int psa[200][200];
int last[200];
int val[200][200];
int await[200][200][2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	memset(last, -0x3f, sizeof last);
	
	cin>>n>>s;
	for(int i = 0; i < n; i++){
		auto c = s[i];
		last[c] = i;

		for(char b = 'a'; b <= 'z'; b++){
			psa[b][c]++;
			psa[c][b]--;
			if(last[b] < 0)
				continue;

			ans = max(ans, psa[b][c]-val[b][c]);
			ans = max(ans, psa[c][b]-val[c][b]);
			val[b][c] = min(val[b][c], await[b][c][1]);
			val[c][b] = min(val[c][b], await[c][b][0]);
		}

		for(char b = 'a'; b <= 'z'; b++){
			await[b][c][1] = min(await[b][c][1], psa[b][c]);
			await[c][b][0] = min(await[c][b][0], psa[c][b]);
		}
	}
	cout<<ans<<'\n';
}