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
using ll = long long;
const ll mod = 1e9+9;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

int valid(int n, int a[]){
	bool br = 0;
	set<int> ins;
	for(int i = 0; i < n; i++){
		if(ins.count(a[i]))
			return 0;
		ins.insert(a[i]);
	}

	for(int i = 0; i < n; i++){
		if(a[i] <= n){
			rotate(a, a+(i-(a[i]-1)+n)%n, a+n);
			br = 1;
			break;
		}
	}
	if(!br) return 1;

	for(int i = 0; i < n; i++){
		if(a[i] <= n and a[i]-1 != i){
			return 0;
		}
	}
	return 1;
}

int replacement(int n, int a[], int b[]){
	for(int i = 0; i < n; i++){
		if(a[i] <= n){
			rotate(a, a+(i-(a[i]-1)+n)%n, a+n);
			break;
		}
	}
	int old[n];
	pair<int, int> ord[n];
	for(int i = 0; i < n; i++){
		old[i] = i+1;
		ord[i] = {a[i], i};
	}
	sort(ord, ord+n);
	int nx = n, ptr = 0;
	//now replace smallest index first, and keep going...
	for(int t = 0; t < n; t++){
		int i = ord[t].second;
		while(nx < a[i]){
			b[ptr++] = old[i];
			old[i] = ++nx;
		}
	}
	return ptr;
}

int countReplacement(int n, int a[]){
	int b[n];
	for(int i = 0; i < n; i++)
		b[i] = a[i];
	if(!valid(n, b)) return 0;
	ll ans = n;

	vector<ll> v = {n};
	for(int i = 0; i < n; i++){
		if(a[i] <= n)
			ans = 1;
		else
			v.emplace_back(a[i]);
	}
	sort(all(v));
	for(int i = 0; i < (int)v.size()-1; i++){
		ll l = v[i]+1, r = v[i+1]-1;
		ll d = r-l+1;
		ll rem = (ll)v.size()-i-1;
		if(d > 0){
			ans = ans*fpow(rem, d, mod)%mod;
		}
	}
	return (int)ans;
}

#ifdef LOCAL

// int vvalid(int n, vector<int> a){
// 	int b[n];
// 	for(int i = 0; i < n; i++)
// 		b[i] = a[i];
// 	return valid(n, b);
// }

// int rep(vector<int> v){
// 	int n = v.size();
// 	auto mx = *max_element(all(v));
// 	int a[n], b[mx];
// 	for(int i = 0; i < n; i++)
// 		a[i] = v[i];
// 	int m = replacement(n, a, b);
// 	print(m);
// 	for(int i = 0; i < m; i++)
// 		cout<<b[i]<<' ';
// 	cout<<'\n';
// 	return 0;
// }

void cntrep(vector<int> v){
	int n = v.size();
	int a[n];
	for(int i = 0; i < n; i++)
		a[i] = v[i];
	int m = countReplacement(n, a);
	print(m);
}

int main(){
	// cntrep({1 , 2 , 7 , 6});
	// cntrep({2 , 3 , 4 , 12 , 6 , 7 , 1});
	// cntrep({4 , 7 , 4 , 7});
	// cntrep({3, 4});

	// rep({3 , 1 , 4});
	// rep({5 , 1 , 2 , 3 , 4});
	// rep({2 , 3 , 4 , 9 , 6 , 7 , 1});

	// print(vvalid(7, {1 , 2 , 3 , 4 , 5 , 6 , 7}));
	// print(vvalid(6, {3 , 4 , 5 , 6 , 1 , 2}));
	// print(vvalid(7, {1 , 5 , 3 , 4 , 2 , 7 , 6}));
	// print(vvalid(4, {4 , 3 , 2 , 1}));
	// print(vvalid(7, {1 , 2 , 3 , 4 , 5 , 6 , 5}));
	// print(vvalid(7, {2 , 3 , 4 , 9 , 6 , 7 , 1}));
	// print(vvalid(5, {10 , 4 , 3 , 11 , 12}));
	int k, n;
	scan(k, n);
	int a[n];
	for(int i = 0; i < n; i++)
		scan(a[i]);
	print(countReplacement(n, a));
}
#endif