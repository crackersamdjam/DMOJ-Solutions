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
using ld = double;
const ld eps = 1e-9;

int n, t;
array<ld, 2> a[22];
pair<ld, ld> ans = {-1, 0};

ld val(int i, ld m){
	return m/a[i][0] + (t-m)/a[i][1];
}

ld eval(ld m){
	ld v = 1e9;
	for(int i = 0; i < n-1; i++){
		v = min(v, val(i, m));
	}
	return v-val(n-1, m);
}

int main(){
	cin>>t>>n;
	for(int i = 0; i < n; i++)
		cin>>a[i][0]>>a[i][1];
	
	sort(a, a+n-1);
	ld l = 0, r = t;
	while(l+eps <= r){
		ld m1 = l+(r-l)/3, m2 = l+(r-l)*2/3;
		ld lv = eval(m1), rv = eval(m2);

		ans = max(ans, {lv, m1});
		ans = max(ans, {rv, m2});

		if(lv < rv)
			l = m1+eps;
		else
			r = m2-eps;
	}
	if(ans.first > -eps)
		printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n", abs(60*60*ans.first), ans.second, t-ans.second);
	else
		cout<<"The cheater cannot win.\n";
}