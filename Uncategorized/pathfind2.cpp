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
const int MM = 5e5+5;

int n, m, k, q, t, par[MM*2], at[2][MM];
vector<int> in[MM];
vector<array<int, 3>> pre, cur, ask[MM];
// pre,cur --> l r id
// ask[i] --> j id 0/1

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int main(){
	scan(n, m, k, q);
	for(int i = 0,a,b; i < k; i++){
		scan(a, b);
		in[a].emplace_back(b);
	}
	for(int i = 0,a,b,c,d; i < q; i++){
		scan(a, b, c, d);
		ask[a].push_back({b, i, 0});
		ask[c].push_back({d, i, 1});
	}

	for(int i = 1; i <= n; i++){
		in[i].emplace_back(0);
		in[i].emplace_back(m+1);
		sort(all(in[i]));
		sort(all(ask[i]));
		reverse(all(ask[i]));

		for(int j = 1; j < size(in[i]); j++){
			int l = in[i][j-1]+1, r = in[i][j]-1;
			if(l > r) continue;
			
			int id = ++t; par[t] = t;
			cur.push_back({l, r, id});

			while(size(pre) and pre.back()[1] < l)
				pre.pop_back();

			while(size(pre) and pre.back()[0] <= r){
				auto rm = pre.back();

				par[find(id)] = rm[2]; //merge

				if(rm[1] <= r) pre.pop_back();
				else break;
			}

			while(size(ask[i]) and ask[i].back()[0] <= r){
				auto rm = ask[i].back(); ask[i].pop_back();
				at[rm[2]][rm[1]] = id;
			}
		}
		reverse(all(cur));
		pre = move(cur);
		cur.clear();
	}
	for(int i = 0; i < q; i++)
		puts(find(at[0][i]) == find(at[1][i]) ? "YES" : "NO");

}