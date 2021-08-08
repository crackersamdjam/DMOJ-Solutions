#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifdef LOCAL
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
const int MM = 2e5+5;
const ll inf = 1e12;

#define f first
#define s second

int n, last[MM];
pair<ll, bool> a[MM];
ll dp[MM], psa[MM];

ll f(int j, int m, int i){
	ll rcnt = i-m, lcnt = m-j+1;
	ll val = psa[i]-psa[m] - rcnt*a[m+1].f + lcnt*a[m].f - (psa[m]-psa[j-1]) + (a[m+1].f-a[m].f)*max(rcnt, lcnt);
	return dp[j-1] + val;
}

long long min_total_length(std::vector<int> R, std::vector<int> B){
	n = 0;
	for(int i: R)
		a[++n] = {i, 0};
	for(int i: B)
		a[++n] = {i, 1};
	
	sort(a+1, a+1+n);
	a[0] = {-inf, 0};

	for(int i = 1,m,l=0; i <= n; i++){
		dp[i] = inf*i; //so that monotonic order works
		psa[i] = psa[i-1]+a[i].f;
		auto [x, t] = a[i];

		if(t == a[i-1].s)
			m = last[i] = last[i-1];
		else
			m = last[i] = i-1;
		
		dp[i] = min(dp[i], dp[i-1] + x-a[m].f);
		
		if(m == i-1){
			//monotonically decreasing decision point
			l = i-1;
		}

		if(l > last[m]) dp[i] = min(dp[i], f(l, m, i));

		while(l-1 > last[m] and f(l-1, m, i) <= dp[i]){
			l--;
			dp[i] = f(l, m, i);
		}

		// pr(i, a[i].f, a[i].s, dp[i], ",", l);
	}

	return dp[n];
}

#ifdef LOCAL
int main(){
	string sss;
	cin>>sss;
	int n, m;
	cin>>n>>m;
	vector<int> r(n), b(m);
	for(int &i: r)
		cin>>i;
	for(int &i: b)
		cin>>i;
	cout<<min_total_length(r, b);
}

// int main(){
	// print(min_total_length({1, 2, 3, 7}, {0, 4, 5, 9, 10}));
// }
#endif