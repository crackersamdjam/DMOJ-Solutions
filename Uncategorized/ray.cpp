#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

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
using T = long long;
constexpr T inf = LLONG_MAX/3;

struct matrix{
	int n, m;
	vector<vector<T>> a;
	matrix(int _n = 0, int _m = 0, T val = 0){
		n = _n, m = _m;
		a.resize(n);
		for(int i = 0; i < n; i++)
			a[i].resize(m, val);
	}
};

struct vect{
	int n;
	vector<T> a;
	vect(int _n = 0, T val = 0){
		n = _n;
		a.resize(n, val);
	}
};

vect mul(const vect &va, const matrix &mb){
	assert(va.n == mb.n);
	vect vc(mb.m, inf);
	for(int i = 0; i < mb.m; i++){
		for(int j = 0; j < mb.n; j++)
			vc.a[i] = min(vc.a[i], va.a[j]+mb.a[j][i]);
	}
	return vc;
}

matrix mul(const matrix &ma, const matrix &mb){
	matrix c(ma.n, mb.m, inf);
	for(int i = 0; i < ma.n; i++){
		for(int j = 0; j < mb.m; j++){
			for(int k = 0; k < ma.m; k++)
				c.a[i][j] = min(c.a[i][j], ma.a[i][k] + mb.a[k][j]);
		}
	}
	return c;
}

matrix fpow(matrix m, T exp){
	if(exp == 1)
		return m;
	matrix ret = fpow(m, exp/2);
	ret = mul(ret, ret);
	if(exp&1)
		ret = mul(ret, m);
	return ret;
}

vect fpow(vect res, matrix base, int exp){
	assert(res.n == base.n);
	while(1){
		if(exp&1)
			res = mul(res, base);
		exp /= 2;
		if(!exp) break;
		base = mul(base, base);
	}
	return res;
}

matrix p[32];

int main(){
	int n, m, q;
	scan(n, m, q);
	p[0] = matrix(n, n, inf);
	while(m--){
		int a, b; T c;
		scan(a, b, c);
		a--, b--;
		p[0].a[a][b] = min(p[0].a[a][b], c);
	}
	for(int i = 1; i < 32; i++)
		p[i] = mul(p[i-1], p[i-1]);

	while(q--){
		int a, b, k;
		scan(a, b, k);
		a--, b--;
		vect res(n, inf);
		res.a[a] = 0;
		for(int i = 0; i < 32; i++)
			if(k&(1<<i))
				res = mul(res, p[i]);

		T ans = res.a[b];
		print(ans < inf ? ans : -1);
	}
}