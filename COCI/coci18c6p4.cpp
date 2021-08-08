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
const int MM = 1e5+5;

int n, k;
ll a[MM], b[MM];

int main(){
	scan(n, k);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	for(int i = 0; i < n; i++){
		scan(b[i]);
		a[i] -= b[i];
	}
	sort(a, a+n);

	multiset<ll> ls, l, r, rs;
	ll sum = 0, ans = LLONG_MAX;
	for(int i = n-1; i >= 0; i--){
		if((int)rs.size() < k){
			rs.insert(a[i]);
		}
		else{
			r.insert(a[i]);
			sum += abs(a[i] - (ll)(-2e6-2));
		}
	}

	for(ll i = -2e6-1; i <= 2e6+1; i++){
		sum += l.size();
		sum -= r.size();
		//l moves away, r moves closer
		while(r.size() and *r.begin() <= i){
			l.insert(*r.begin());
			r.erase(r.begin());
		}
		while(rs.size() and *rs.begin() < i){
			ls.insert(*rs.begin());
			rs.erase(rs.begin());
		}
		
		while(rs.size() and l.size()){
			ll rd = (*rs.begin()) - i;
			ll ld = i - (*l.begin());
			if(rd <= ld){
				sum += rd-ld;
				ls.insert(*l.begin());
				l.erase(l.begin());
				r.insert(*rs.begin());
				rs.erase(rs.begin());
			}
			else break;
		}
		while(r.size() and *r.begin() <= i){
			l.insert(*r.begin());
			r.erase(r.begin());
		}
		ans = min(ans, sum);
	}
	print(ans);
}