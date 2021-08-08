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
using ll = long long;
using T = long long;
const int MM = 6e5+5;

ll bit[MM];
int cnt[MM];

void update(int i, ll v, int c){
	for(; i < MM; i += i&-i)
		bit[i] += v, cnt[i] += c;
}

int qu(int i){
	int ret = 0;
	for(; i; i -= i&-i)
		ret += cnt[i];
	return ret;
}

int query(ll k){
	int id = 0, ret = 0;
	for(int i = 20; i >= 0; i--){
		int j = 1<<i;
		if(id+j < MM and bit[id+j] < k){
			k -= bit[id+j];
			ret += cnt[id+j];
			id += j;
		}
	}
	return qu(id+1);
}

ll sum, tot;
set<pair<int, int>, greater<pair<int, int>>> mp;
int n, q, a[MM], id[MM], nv[MM], re[MM], pre[MM];
int x;

int main(){
	scan(n, q);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		mp.insert({a[i], i});
	}
	for(int i = 0; i < q; i++){
		scan(id[i], nv[i]);
		mp.insert({nv[i], n+1+i});
	}
	int ptr = 0;
	for(auto i: mp){
		re[i.second] = ++ptr;
		// print(i.first, i.second, ptr);
	}

	for(int i = 1; i <= n; i++){
		tot += a[i];
		update(re[i], a[i], 1);
		pre[i] = re[i];
		// print(a[i], pre[i]);
	}
	print(query((tot+2)/2));
	
	for(int i = 0; i < q; i++){
		int j = id[i];

		update(pre[j], -a[j], -1);

		tot = tot-a[j]+nv[i];
		a[j] = nv[i];

		pre[j] = re[n+1+i];
		update(pre[j], a[j], 1);

		// print(a[j], pre[j], n+1+i);

		print(query((tot+2)/2));
	}
}