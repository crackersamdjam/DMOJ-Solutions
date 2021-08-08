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
using pii = array<ll, 2>;
const int MM = 150005, CH = 500;
// CH stands for cheese

int n;
pii a[MM];
ll ans;
vector<ll> my = {-1, 0};
int cnt[MM], bit[MM];

void up(int i){
	for(; i < MM; i += i&-i)
		bit[i]++;
}

int qu(int i){
	int v = 0;
	for(; i; i -= i&-i)
		v += bit[i];
	return v;
}

int main(){
	#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#endif
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i][0]>>a[i][1];
		my.emplace_back(a[i][1]);
	}
	sort(a, a+n+1);
	sort(all(my));
	my.erase(unique(my.begin(), my.end()), my.end());
	
	pair<ll, int> best = {0, 1};

	for(int i = 0; i <= n; i++){
		ll rsum = (n-i)*a[i+1][0];
		int y = lower_bound(all(my), a[i][1])-my.begin();
		up(y);
		cnt[y]++;

		{
			int j = max(1, best.second-CH);
			int num = i+1-qu(j-1);
			best = max(best, {num*my[j], j});
			for(int t = 0; t < CH*2 and j <= n; t++){
				num -= cnt[j];
				j++;
				best = max(best, {num*my[j], j});
			}
		}
		{
			int j = max(1, y-CH);
			int num = i+1-qu(j-1);
			best = max(best, {num*my[j], j});
			for(int t = 0; t < CH*2 and j <= n; t++){
				num -= cnt[j];
				j++;
				best = max(best, {num*my[j], j});
			}
		}

		ans = max(ans, best.first+rsum);
	}
	cout<<ans<<'\n';
}