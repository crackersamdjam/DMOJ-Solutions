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
const int MM = 1e5+5, inf = 1e9;

struct node{
	int len, link;
	map<char, int> adj;
} a[MM*2];
int sz, last;

void init(){
	a[0].len = 0;
	a[0].link = -1;
	sz++;
	last = 0;
}

void extend(char c){
	int cur = sz++;
	a[cur].len = a[last].len + 1;
	int p = last;
	while(p != -1 && !a[p].adj.count(c)){
		a[p].adj[c] = cur;
		p = a[p].link;
	}
	if(p == -1)
		a[cur].link = 0;
	else{
		int q = a[p].adj[c];
		if(a[p].len + 1 == a[q].len){
			a[cur].link = q;
		}
		else{
			int clone = sz++;
			a[clone].len = a[p].len + 1;
			a[clone].adj = a[q].adj;
			a[clone].link = a[q].link;
			while(p != -1 && a[p].adj[c] == q){
				a[p].adj[c] = clone;
				p = a[p].link;
			}
			a[q].link = a[cur].link = clone;
		}
	}
	last = cur;
}

int main(){
	string s, t;
	cin>>s>>t;
	int n = size(s), m = size(t);
	init();
	for(auto c: s)
		extend(c);

	int i = 0, ans = 1;
	int cur = 0;
	while(i < m and ans <= m){
		if(a[cur].adj.count(t[i]))
			cur = a[cur].adj[t[i++]];
		else{
			cur = 0;
			ans++;
		}
	}
	print(ans > m ? -1 : ans);
}