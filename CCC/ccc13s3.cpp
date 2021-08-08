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

int t, g, done[4][4], val[4], ans;
vector<pair<int, int>> v;

void go(int i){
	if(i == size(v)){
		for(int i = 0; i < 4; i++)
			if(i != t and val[i] >= val[t])
				return;
		ans++;
		return;
	}
	auto [a, b] = v[i];
	val[a] += 3;
	go(i+1);
	val[a] -= 3;
	val[b] += 3;
	go(i+1);
	val[b] -= 3;
	val[a]++;
	val[b]++;
	go(i+1);
	val[a]--;
	val[b]--;
}

int main(){
	scan(t, g);
	t--;
	while(g--){
		int a, b, ax, bx;
		scan(a, b, ax, bx);
		a--, b--;
		if(ax > bx)
			val[a] += 3;
		else if(ax < bx)
			val[b] += 3;
		else
			val[a]++, val[b]++;
		done[a][b] = 1;
	}
	for(int i = 0; i < 4; i++){
		for(int j = i+1; j < 4; j++){
			if(!done[i][j])
				v.push_back({i, j});
		}
	}
	go(0);
	print(ans);
}