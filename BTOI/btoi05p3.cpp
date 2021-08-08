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
const int MM = 1005;

int n, m, dis[MM][MM][2], sta, stb, eda, edb;
char h[MM][MM], v[MM][MM];
queue<tuple<int, int, int>> q;

bool ok(int cur, char c){
	if(c != 'n'){
		if(cur == 0 and c == 'b')
			return 1;
		if(cur == 1 and c == 'w')
			return 1;
	}
	return 0;
}

int main(){
	scan(n, m);
	scan(sta, stb, eda, edb);
	sta++, stb++, eda++, edb++;
	swap(sta, stb);
	swap(eda, edb);
	scanf("%s", h[1]+1);
	for(int i = 2; i <= m+1; i++){
		scanf("%s", v[i]+1);
		scanf("%s", h[i]+1);
	}
	dis[sta][stb][0] = dis[sta][stb][1] = 1;
	q.emplace(sta, stb, 0);
	q.emplace(sta, stb, 1);
	while(size(q)){
		auto [curx, cury, cc] = q.front(); q.pop();
		int curd = dis[curx][cury][cc];
		if(curx == eda and cury == edb){
			print(curd-1);
			break;
		}

		auto go = [&](int x, int y, char w){
			// pr("try", x, y, w, curx, cury*2 -1);
			if(x <= m+1 && x > 0 and y > 0 and y <= n+1);
			else return;
			if(dis[x][y][!cc]) return;
			if(!w or !ok(cc, w)) return;
			dis[x][y][!cc] = curd+1;
			q.emplace(x, y, !cc);
		};
		go(curx, cury+1, h[curx][cury]);
		go(curx, cury-1, h[curx][cury-1]);
		go(curx+1, cury-1, v[curx+1][cury*2-1 -1]);
		go(curx+1, cury, v[curx+1][cury*2 -1]);
		go(curx-1, cury, v[curx][cury*2 -1]);
		go(curx-1, cury+1, v[curx][cury*2+1 -1]);
	}
}