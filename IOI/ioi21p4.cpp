#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 1e5+5;

int a[MM][3][3];
int cnta[MM][3], cntb[MM][3];
map<char, int> mp;
int n;

void init(string s, string t){
	mp['A'] = 0;
	mp['C'] = 1;
	mp['T'] = 2;
	n = size(s);
	s = " "+s;
	t = " "+t;
	for(int i = 1; i <= n; i++){
		memcpy(a[i], a[i-1], sizeof a[i-1]);
		a[i][mp[s[i]]][mp[t[i]]]++;

		memcpy(cnta[i], cnta[i-1], sizeof cnta[i-1]);
		memcpy(cntb[i], cntb[i-1], sizeof cntb[i-1]);
		cnta[i][mp[s[i]]]++;
		cntb[i][mp[t[i]]]++;
	}
}

int b[3][3];

int get_distance(int l, int r){
	r++;
	int ans = 0, tot = r-l;
	for(int i = 0; i < 3; i++){
		if(cnta[r][i]-cnta[l][i] != cntb[r][i]-cntb[l][i])
			return -1;
		for(int j = 0; j < 3; j++){
			b[i][j] = a[r][i][j] - a[l][i][j];
			if(i == j){
				tot -= b[i][j];
			}
			else if(i > j){
				int sub = min(b[i][j], b[j][i]);
				ans += sub;
				tot -= sub*2;
			}
		}
	}
	if(tot%3) return -1;
	ans += tot/3*2;
	return ans;
}

#ifdef LOCAL

int main(){
	init("ATACAT", "ACTATA");
	cout<<get_distance(1, 3)<<endl;
	cout<<get_distance(4, 5)<<endl;
	cout<<get_distance(3, 5)<<endl;
}

#endif