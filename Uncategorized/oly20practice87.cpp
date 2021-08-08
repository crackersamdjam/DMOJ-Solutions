#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll;
typedef std::pair<short, ll> pii;

inline void add(pii &x, const pii &y){
	if(y.first < x.first || !x.second) //better or empty
		x = y;
	else if(y.first == x.first)
		x.second += y.second;
}

const int M=4500007;
struct hashmap{
	ll key[M];
	pii val[M];
	int to[M],nxt[M],vis[M],sz,null=1;
	void clear(){
		sz=0; null++;
	}
	pii upd(ll x, pii v){
		int cur=x%M;
		if(vis[cur]!=null){vis[cur]=null; to[cur]=-1;}
		for(cur=to[cur];cur!=-1;cur=nxt[cur]) if(key[cur]==x){
				add(val[cur], v);
				return val[cur];
			}
		cur=x%M; nxt[sz]=to[cur]; to[cur]=sz; val[sz]=v; key[sz]=x;
		return val[sz++];
	}
} dd[2];
#define dp dd[p1]
#define pre dd[p2]

int p1, p2 = 1, p3 = 2, p4 = 3;
int n, a;
pii ans[41];

ll full[41][41];

int main(){
	for(int i = 0; i < 41; i++){
		for(int j = i; j < 41; j++){
			for(int k = i; k <= j; k++)
				full[i][j] |= 1LL<<k;
		}
	}
//	freopen("../in", "r", stdin);
	scan(n);
	for(int i = 1; i <= n; i++)
		ans[i] = {INT_MAX, 0};
	
//	dp[0] = {0, 1};
	dp.upd(0, {0, 1});
	
	int mv;
	ll mask, split = 0, tmp;
	int l, r, f;
	
	for(int i = 0; i < n; i++){
		scan(a);
		a--;
		pre.clear();
		std::swap(p1, p2);
		
		split |= 1LL<<a;
		l = r = a;
		while(l >= 0 and split&(1LL<<l))
			l--;
		while(r < n and split&(1LL<<r))
			r++;
		l++, r--;
		//new range is [l, r]
		
		for(int tt = 0; tt < pre.sz; tt++){
			std::pair<ll, pii> j = {pre.key[tt], pre.val[tt]};
			
			mask = j.first;
			mv = __builtin_popcountll(~mask&full[l][a]);
			tmp = mask&full[a][r];
			mask ^= tmp;
			mask ^= tmp>>mv;
			for(f = l; mask&(1LL<<f); f++);
			
			if(i == n-1){
				add(ans[__builtin_popcountll(mask)], j.second);
				add(ans[__builtin_popcountll(mask|(1LL<<f))], {j.second.first + __builtin_popcountll(j.first&full[a][n]), j.second.second});
				continue;
			}
			
			//don't take
			dp.upd(mask, j.second);
			//take
			
			dp.upd(mask|(1LL<<f), {j.second.first + __builtin_popcountll(j.first&full[a][n]), j.second.second});
		}
	}

//	for(const auto &j: dp)
//		add(ans[__builtin_popcountll(j.first)], j.second);
	
	for(int i = 1; i <= n; i++)
		print(ans[i].first, ans[i].second);
}