#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = unsigned short;
const int MM = 1<<6, NN = 4e5;

// map<int, ll> cnt[MM][MM];

int gethash(string &s){
	int v = 0;
	for(auto c: s)
		v = (v*31+c);
	return v;
}

int n, m;
unsigned int ans;

vector<int> cord[MM][MM];
vector<ll> cnt[MM][MM];
string s[NN], t;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int l = 0; l < n; l++){
		cin>>s[l];
		int cur = 0;
		for(int j = 0; j < m; j++)
			if(s[l][j] != '?')
				cur |= 1<<j;

		for(int i = 0; i < (1<<m); i++){
			t = s[l];
			for(int j = 0; j < m; j++){
				if(!((i>>j)&1))
					t[j] = '?';
			}
			cord[i][cur].emplace_back(gethash(t));
		}

		for(int i = 0; i < (1<<m); i++){
			t = s[l];
			for(int j = 0; j < m; j++){
				if(!((i>>j)&1))
					t[j] = '?';
			}
			cord[cur][i].emplace_back(gethash(t));
		}
	}

	for(int i = 0; i < MM; i++){
		for(int j = 0; j < MM; j++){
			sort(all(cord[i][j]));
			cord[i][j].erase(unique(cord[i][j].begin(), cord[i][j].end()), cord[i][j].end());
			cord[i][j].shrink_to_fit();
			cnt[i][j].resize(size(cord[i][j]));
		}
	}

	for(int l = 0; l < n; l++){
		int cur = 0;
		for(int j = 0; j < m; j++)
			if(s[l][j] != '?')
				cur |= 1<<j;

		for(int i = 0; i < (1<<m); i++){
			t = s[l];
			for(int j = 0; j < m; j++){
				if(!((i>>j)&1))
					t[j] = '?';
			}
			int id = lower_bound(all(cord[i][cur]), gethash(t)) - cord[i][cur].begin();
			ans += cnt[i][cur][id];
			// if(cnt[i][cur].count(gethash(t)))
				// ans += cnt[i][cur][gethash(t)];
		}

		for(int i = 0; i < (1<<m); i++){
			t = s[l];
			for(int j = 0; j < m; j++){
				if(!((i>>j)&1))
					t[j] = '?';
			}
			int id = lower_bound(all(cord[cur][i]), gethash(t)) - cord[cur][i].begin();
			cnt[cur][i][id]++;
			// cnt[cur][i][gethash(t)]++;
		}
	}
	cout<<ans<<'\n';
}