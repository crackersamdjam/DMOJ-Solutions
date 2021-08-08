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
const int MM = 2e5+5, NN = 1073741824;
const int M = 100007;

struct hashmap{
	int key[M];
	int val[M];
	int to[M], nxt[M], vis[M], sz, null=1;
	void clear(){
		sz = 0; null++;
	}
	int update(int x, int v){
		int cur = x%M;
		if(vis[cur] != null)
			vis[cur] = null, to[cur] = -1;
		for(cur = to[cur]; cur != -1; cur = nxt[cur])
			if(key[cur] == x){
				val[cur] += v;
				return val[cur];
			}
		cur = x%M; nxt[sz] = to[cur]; to[cur] = sz; val[sz] = v; key[sz] = x;
		return val[sz++];
	}
} cnt;

int t, n;
int a[MM];

void add(int i){
	i += NN;
	if(cnt.update(i, 0)) return;
	for(; i; i >>= 1)
		cnt.update(i, 1);
}

int qu(int v){
	int sz = NN, ret = 0;
	for(int i = 1; sz; i <<= 1, sz >>= 1){
		int j = sz&v;
		if(j) i ^= 1;

		if(cnt.update(i, 0) == sz){
			i ^= 1;
			ret += sz;
		}
	}
	return ret;
}

int main(){
// 	scan(t);
    t = 1;
	while(t--){
		cnt.clear();
		scan(n);
		for(int i = 0; i < n; i++){
			scan(a[i]);
			add(a[i]);
		}
		pair<int, int> ans = {-1, -1};

		for(int i = 0; i < n; i++)
			ans = max(ans, {qu(a[i]), -a[i]});
		
		print(ans.first, -ans.second);
	}
}