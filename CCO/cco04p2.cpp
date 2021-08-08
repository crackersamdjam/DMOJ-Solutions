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
using pii = pair<int, int>;

int t, n;
pii a[1005];

int main(){
	scan(t);
	while(t--){
		scan(n);
		for(int i = 0; i < n; i++){
			scan(a[i].first, a[i].second);
			if(a[i].first > a[i].second)
				swap(a[i].first, a[i].second);
		}
		sort(a, a+n);
		vector<vector<pii>> v;
		for(int d = 0; d < n; d++){
			auto i = a[d];
			bool f = 0;
			for(auto &j: v){
				if(i.first >= j.back().first and i.second >= j.back().second){
					j.emplace_back(i);
					f = 1;
					break;
				}
			}
			if(!f){
				v.emplace_back();
				v.back().emplace_back(i);
			}
		}
		
		printf("%d\n", (int)size(v));
		for(auto &i: v){
			for(auto j: i)
				printf("%d-%d ", j.first, j.second);
			printf("\n");
		}
	}
}