#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> int size(const T &x){return int(x.size());}
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ld = long double;
const int MM = 1e5+5;

int n;
char s[MM];
vector<int> v[26];
pair<ld, pair<int, int>> ans = {2, {1, 1}};

int main(){
	scan(n);
	scanf("%s", s);
	for(int i = 0; i < n; i++){
		v[s[i]-'a'].emplace_back(i);
	}
	for(int i = 0; i < n; i++){
		vector<int> a = {n-1};
		for(int j = 0; j < 26; j++){
			auto it = lower_bound(all(v[j]), i);
			if(it != v[j].end())
				a.emplace_back((*it)-1);
		}
		sort(all(a));
		for(int j = 1; j < (int)a.size(); j++){
			ld f = (ld)(j)/(ld)(a[j]-i);
			ans = min(ans, {f, {i, a[j]}});
		}
	}
	print(ans.second.first+1, 1+ans.second.second);
}