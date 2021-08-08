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
const int MM = 20;

string all[] = {"B1", "B2", "B3", "B4", "B5", "G1", "G2", "G3", "G4", "G5", "R1", "R2", "R3", "R4", "R5", "Y1", "Y2", "Y3", "Y4", "Y5"};
map<string, int> mp;
int dp[2][1<<MM], sa;
bool vis[2][1<<MM];

int go(const int m, const int t){
	if(vis[t][m]) return dp[t][m];
	int ret = -100;
	
	for(int i = 0; i < MM; i++){
		if(((m>>i)&1) and ((sa>>i)&1) != t);
		else continue;

		int has = 0, cur = 100;

		for(int j = 0; j < MM; j++){
			if(((m>>j)&1) and ((sa>>j)&1) == t);
			else continue;
			if(i/5 == j/5)
				has = 1;
		}

		for(int j = 0; j < MM; j++){
			if(((m>>j)&1) and ((sa>>j)&1) == t);
			else continue;

			auto nx = m;
			nx ^= 1<<i;
			nx ^= 1<<j;
			
			if(has){
				if(i/5 != j/5) continue;
				if(i > j) cur = min(cur, go(nx, t)+1);
				else cur = min(cur, __builtin_popcount(nx)/2-go(nx, !t));
			}
			else cur = min(cur, go(nx, t)+1);
		}

		ret = max(ret, cur);
	}
	vis[t][m] = 1;
	return dp[t][m] = ret;
}

int main(){
	for(int i = 0; i < MM; i++)
		mp[all[i]] = i;
	string s;
	while(1){
		getline(cin, s);
		if(s[0] == '*')
			break;

		memset(vis, 0, sizeof vis);
		vis[0][0] = vis[1][0] = 1;
		sa = 0;

		stringstream ss(s);
		while(getline(ss, s, ' ')){
			sa |= 1<<mp[s];
		}
		print(go((1<<20)-1, 0));
	}
}