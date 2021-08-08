#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using ld = double;
const ll mod = 998244353;
const int MM = 300, NN = 100;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T mulmod(T _a, T _b, T _mod){ return _a%_mod*(_b%_mod)%_mod;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int t;
ll n, x, y;
ld lx, ly;
bool vis[MM][NN];
ll ways[MM][NN];
bool over[MM][NN];

struct stt{
	int a, b;
	ld eval() const{
		return a*lx + b*ly;
	}
	bool operator<(const stt &o) const{
		return eval() > o.eval();
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		lx = log(x);
		ly = log(y);
		memset(vis, 0, sizeof vis);
		memset(ways, 0, sizeof ways);
		memset(over, 0, sizeof over);
		ll cx = 1, cy = 1;

		ways[0][1] = ways[1][0] = 1;
		vis[1][1] = 1;
		ways[1][1] = 1;
		priority_queue<stt> q;
		q.push({1, 1});

		int maxa = 1, maxb = 1;
		vector<array<int, 2>> v;
		v.push_back({0, 1});
		v.push_back({1, 0});

		while(n){
			assert(size(q));
			auto [a, b] = q.top(); q.pop();
			ll take = min(ways[a][b], n);
			if(over[a][b])
				take = n;
			n -= take;
			take %= mod-1;
			cx += take*a;
			cy += take*b;
			cx %= mod-1;
			cy %= mod-1;

			maxa = max(maxa, a);
			maxb = max(maxb, b);
			assert(a < MM-5);
			assert(b < MM-5);

			v.push_back({a, b});
			for(int i = 0; i < (int)size(v)-1; i++){
				auto [c, d] = v[i];
				if(a+c > MM-5 or b+d > MM-5)
					break;

				if(over[a][b] or over[c][d])
					over[a+c][b+d] = 1;
				else
					ways[a+c][b+d] += ways[a][b]*ways[c][d];
				//no overflow...

				if(over[a+c][b+d] or ways[a+c][b+d] > n){
					over[a+c][b+d] = 1;
					ways[a+c][b+d] = 0;
				}

				if(!vis[a+c][b+d]){
					vis[a+c][b+d] = 1;
					q.push({a+c, b+d});
				}
			}
			//also check within same group
			if(a*2 < MM-5 and b*2 < MM-5){
				if(over[a][b])
					over[a*2][b*2] = 1;
				else
					ways[a*2][b*2] += ways[a][b]*(ways[a][b]-1)/2;

				if(over[a*2][b*2] or ways[a*2][b*2] > n){
					over[a*2][b*2] = 1;
					ways[a*2][b*2] = 0;
				}
				if(!vis[a*2][b*2]){
					vis[a*2][b*2] = 1;
					q.push({a*2, b*2});
				}
			}
		}
		assert(!n);
		ll ans = fpow(x, cx, mod)*fpow(y, cy, mod)%mod;
		cout<<ans<<'\n';
	}
}
/*
sum(1) = 2
sum(2) = 1
sum(3) = 2
sum(4) = 4
sum(5) = sum(2)*sum(3) + sum(4)*sum(1) = 1*2 + 2*4 = 2+8 = 10
growth is like catalan numbers
at sum = x, ~ C_i for the cost of i numbers
(2x! / ((n+1)!)^2)

if "compressed", takes at most 40*40
but what about n,x,y = 1000000000000000000 2 999999733
293*10 is max needed
*/