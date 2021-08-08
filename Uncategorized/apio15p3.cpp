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
const int MM = 1e5+5;

int k, n;
ll ans, sum, pre[MM], suf[MM];
vector<pair<int, int>> v;
priority_queue<int> lo;
priority_queue<int, vector<int>, greater<int>> hi;

int main(){
	scan(k, n);
	while(n--){
		int a, b;
		char ca, cb;
		ca = gc; scan(a);
		cb = gc; scan(b);
		if(ca != cb){
			sum++;
			v.emplace_back(min(a, b), max(a, b));
		}
		else
			sum += abs(b-a);
	}
	sort(all(v), [](auto x, auto y){
		return x.first+x.second < y.first+y.second;
	});
	n = size(v);
	ll hisum = 0, losum = 0;
	for(int i = 0; i < n; i++){
		losum += v[i].first;
		lo.push(v[i].first);
		hisum += v[i].second;
		hi.push(v[i].second);
		while(hi.top() < lo.top()){
			int l = hi.top(), r = lo.top();
			hi.pop(); lo.pop();
			hi.push(r); lo.push(l);
			hisum += r-l;
			losum += l-r;
		}
		// print(i, v[i].first, v[i].second, hi.top(), hisum, losum);
		pre[i] = hisum-losum;
	}
	hisum = losum = 0;
	while(size(hi))
		hi.pop();
	while(size(lo))
		lo.pop();
	for(int i = n-1; i >= 0; i--){
		losum += v[i].first;
		lo.push(v[i].first);
		hisum += v[i].second;
		hi.push(v[i].second);
		while(hi.top() < lo.top()){
			int l = hi.top(), r = lo.top();
			hi.pop(); lo.pop();
			hi.push(r); lo.push(l);
			hisum += r-l;
			losum += l-r;
		}
		suf[i] = hisum-losum;
	}
	if(k == 1){
		print(pre[n-1]+sum);
		return 0;
	}
	ans = suf[0];
	for(int i = 0; i < n; i++){
		ans = min(ans, pre[i]+suf[i+1]);
	}
	print(ans+sum);
}