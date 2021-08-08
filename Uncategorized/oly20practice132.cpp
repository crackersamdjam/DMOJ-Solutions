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
const int MM = 1e4+5;

int n, m, par[MM*4], ll[MM], rr[MM], v[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	map<int, int> mp;
	int t = 0;
	for(int i = 0; i < m; i++){
		string s;
		cin>>ll[i]>>rr[i]>>s;
		ll[i]--;
		mp[ll[i]] = mp[rr[i]] = 0;
		v[i] = s == "odd";
	}
	for(auto &i: mp)
		i.second = ++t;

	for(int i = 1; i <= t*2; i++)
		par[i] = i;

	for(int i = 0; i < m; i++){
		int l = mp[ll[i]], r = mp[rr[i]];
		if(v[i]){
			par[find(r)] = find(l+t);
			par[find(r+t)] = find(l);
		}
		else{
			par[find(r)] = find(l);
			par[find(r+t)] = find(l+t);
		}
		if(find(r) == find(r+t)){
			cout<<i<<'\n';
			return 0;
		}
	}
	cout<<m<<'\n';
}