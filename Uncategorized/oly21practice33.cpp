#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 4005;

struct SuffixAutomaton{
	struct st{
		int len, par;
		ll cnt;
		map<char, int> ch;
	};
	vector<st> v;
	int sz, last;
	
	void init(int n){
		v.resize(n*2);
		v[0].len = 0; //0 is the root
		v[0].par = -1;
		sz = 1;
		last = 0;
	}
	
	void extend(char c){
		int cur = sz++;
		v[cur].len = v[last].len+1;
		int p = last;
		while(p != -1 && !v[p].ch.count(c)){
			v[p].ch[c] = cur;
			p = v[p].par;
		}
		if(p == -1){
			v[cur].par = 0;
		}
		else{
			int o = v[p].ch[c]; //"other"
			if(v[p].len+1 == v[o].len){
				v[cur].par = o;
			}
			else{
				int clone = sz++; //clone
				v[clone].ch = v[o].ch;
				v[clone].par = v[o].par;
				v[clone].len = v[p].len+1;
				while(p != -1 && v[p].ch[c] == o){
					//redirect all these to clone
					v[p].ch[c] = clone;
					p = v[p].par;
				}
				v[o].par = v[cur].par = clone;
			}
		}
		last = cur;
	}
} samb;

string a, b;
int lena, lenb;
set<ll> allb;

int nexta[MM][200];
int nextb[MM][200];
int dp1[MM][MM];
int dp2[MM][MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>a>>b;
	lena = size(a);
	lenb = size(b);

	samb.init(MM);
	for(auto c: b)
		samb.extend(c);

	a = " "+a;
	b = " "+b;

	memset(nexta, -1, sizeof nexta);
	for(int i = 1; i <= lena; i++){
		nexta[i][a[i]] = i;
	}
	for(int i = lena-1; i >= 0; i--){
		for(int j = 'a'; j <= 'z'; j++){
			if(nexta[i][j] == -1)
				nexta[i][j] = nexta[i+1][j];
		}
	}

	memset(nextb, -1, sizeof nextb);
	for(int i = 1; i <= lenb; i++){
		nextb[i][b[i]] = i;
	}
	for(int i = lenb-1; i >= 0; i--){
		for(int j = 'a'; j <= 'z'; j++){
			if(nextb[i][j] == -1)
				nextb[i][j] = nextb[i+1][j];
		}
	}

	int l1 = 1e9;
	for(int i = 1; i <= lena; i++){
		int at = 0;
		for(int j = i; j <= lena; j++){
			if(!samb.v[at].ch.count(a[j])){
				l1 = min(l1, j-i+1);
				break;
			}
			at = samb.v[at].ch[a[j]];
		}
	}
	if(l1 == 1e9) l1 = -1;
	cout<<l1<<'\n';

	int l2 = 1e9;
	for(int i = 1; i <= lena; i++){
		int at = -1;
		for(int j = i; j <= lena; j++){
			if(nextb[at+1][a[j]] == -1){
				l2 = min(l2, j-i+1);
				break;
			}
			at = nextb[at+1][a[j]];
		}
	}
	if(l2 == 1e9) l2 = -1;
	cout<<l2<<'\n';

	memset(dp1, 0x3f, sizeof dp1);

	for(int i = lena; i >= 0; i--){
		for(int at = samb.sz-1; at >= 0; at--){
			for(int c = 'a'; c <= 'z'; c++){
				int ii = nexta[i+1][c];
				if(ii > i){
					if(!samb.v[at].ch.count(c)){
						dp1[i][at] = 1;
					}
					else{
						int nx = samb.v[at].ch[c];
						dp1[i][at] = min(dp1[i][at], dp1[ii][nx]+1);
					}
				}
			}
		}
	}
	int l3 = dp1[0][0];
	for(int i = 0; i <= lena; i++){
		l3 = min(l3, dp1[i][0]);
	}
	if(l3  > 1e9) l3 = -1;
	cout<<l3<<'\n';


	memset(dp2, 0x3f, sizeof dp2);
	for(int i = lena; i >= 0; i--){
		for(int j = lenb; j >= 0; j--){
			for(int c = 'a'; c <= 'z'; c++){
				int ii = nexta[i+1][c], jj = nextb[j+1][c];
				if(ii > i){
					if(jj == -1){
						dp2[i][j] = 1;
					}
					else{
						dp2[i][j] = min(dp2[i][j], dp2[ii][jj]+1);
					}
				}
			}
		}
	}
	int l4 = dp2[0][0];
	if(l4  > 1e9) l4 = -1;
	cout<<l4<<'\n';
}