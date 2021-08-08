#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef __int128 ll;
const int MM = 1e5+5;
const ll base = 131, mod = 1e15+7;

int n;
string s, out;
set<int> a[30];
//a open b close
ll hs[MM], pre[MM];
int in[MM], sz;
map<ll, deque<int>> mp[30];

void go(int l, int r){
	if(l >= r)
		return;
	out[l] = '(';
	int i = *--upper_bound(all(mp[s[l]][pre[r]]), r);
	// mp[s[l]][pre[r]].pop_back();
	out[i] = ')';
	go(l+1, i-1);
	go(i+1, r);
}

int main(){
	cin>>s;
	n = s.size();
	s = "."+s;
	out = s;
	for(int i = 1; i <= n; i++){
		s[i] -= 'a';
		if(sz and in[sz] == s[i])
			sz--;
		else{
			in[++sz] = s[i];
			hs[sz] = hs[sz-1]*base+(s[i]+'a')%mod;
		}
		mp[s[i]][hs[sz]].emplace_back(i);
		pre[i] = hs[sz];
		// cout<<i<<' '<<(int)pre[i]<<endl;
	}
	if(sz){
		print(-1);
		exit(0);
	}
	go(1, n);
	cout<<out.substr(1);
}