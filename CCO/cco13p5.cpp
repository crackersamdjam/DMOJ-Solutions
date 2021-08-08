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
using ld = double;
using co = array<ll, 2>;
using pt = array<ld, 2>;
const int MM = 5e5+5;
const ld pi = acos(-1), eps = 1e-9;

bool equal(pt a, pt b){
	return abs(a[0]-b[0]) < eps and abs(a[1]-b[1]) < eps;
}

ld sq(ld x){
	return x*x;
}

ld dist(co a, co b){
	return sqrtl(sq(a[0]-b[0]) + sq(a[1]-b[1]));
}

vector<pt> get(vector<array<ll, 2>> a){
	int n = (int)size(a);
	vector<pt> v(n);
	for(int i = 0; i < n; i++){
		int j = (i+1)%n, k = (j+1)%n;
		ld aa = atan2(a[i][1] - a[j][1], a[i][0] - a[j][0]);
		ld ac = atan2(a[k][1] - a[j][1], a[k][0] - a[j][0]);
		ld ang = aa-ac;
		while(ang < 0) ang += 2*pi;
		while(ang >= 2*pi) ang -= 2*pi;
		ld d = dist(a[j], a[k]) / dist(a[i], a[j]);
		v[i] = {ang, d};
	}
	return move(v);
}

// pi[i] = length of longest proper prefix equal to suffix of s ending at i ( s.substr(0, i+1) )
// find earliest occurrence of s in t
int kmp(vector<pt> s, vector<pt> t){
	int ret = 0, len = (int)size(s);

	s.push_back({69, 69});
	s.insert(s.end(), all(t));

	vector<int> pi(size(s));

	for(int i = 1, j = 0; i < (int)size(s)-1; i++){ //-1 last one ignore
		while(j and !equal(s[i], s[j]))
			j = pi[j-1];
		if(equal(s[i], s[j]))
			j++;
		pi[i] = j;
		if(pi[i] == len)
			return i-2*len+1;
	}
	return 0;
}

int main(){
	int t, n;
	scan(t);
	while(t--){
		scan(n);
		vector<array<ll, 2>> a(n), b(n);
		for(int i = 0; i < n; i++)
			scan(a[i][0], a[i][1]);

		b.resize(n);
		for(int i = 0; i < n; i++)
			scan(b[i][0], b[i][1]);

		auto va = get(a);
		b.insert(b.end(), all(b));
		auto vb = get(b);

		print(kmp(va, vb));
	}
}