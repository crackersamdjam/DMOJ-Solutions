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
using ar = array<int, 2>;
const int MM = 3e5+5;

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

int n;
int ans, r, nr;
vector<ar> v;

int main(){
	scan(n);
	for(int i = 0,a,b; i < n; i++){
		scan(a, b);
		v.push_back({a, b});
		v.push_back({b, -a});
	}
	sort(all(v));

	for(auto i: v){
		if(i[1] > 0){
			nr = max(nr, i[1]);
		}
		else{
			if(r <= -i[1]){
				r = nr;
				ans++;
			}
		}
	}

	print(ans);
}
/*
when see left, update mx right
when see right, see if cover_right contains it
cover_right is for future (next one takes)
*/