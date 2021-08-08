#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const ll mod = 1e9+7;
const int MM = 1e5+5;

int n, v[MM];
int cnta[MM], cntb[MM], cntc[MM];
ll sa, sb, sc;
ll va, vb, vc;
ll f, s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>f>>s;

	int la = 1, lb = 1, lc = 1;
	for(int i = 1; i <= n; i++){
		cin>>v[i];
		sa += v[i];
		sb += v[i];
		sc += v[i];
		cnta[v[i]]++;
		cntb[v[i]]++;
		cntc[v[i]]++;

		while(cnta[v[i]] > f){
			cnta[v[la++]]--;
		}
		while(cntc[v[i]] > f){
			sc -= v[lc];
			cntc[v[lc]]--;
			lc++;
		}

		while(sb > s){
			sb -= v[lb++];
		}
		while(sc > s){
			sc -= v[lc];
			cntc[v[lc]]--;
			lc++;
		}

		va += i-la+1;
		vb += i-lb+1;
		vc += i-lc+1;
	}
	cout<<va%mod*vb%mod*vc%mod<<'\n';
}