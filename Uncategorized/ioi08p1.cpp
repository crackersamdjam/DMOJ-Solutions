#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;

int n, ans;
string s;
vector<char> out;

struct node{
	map<char, node*> ch;
	int cnt, dep;
	char id;
	void dfs(){
		for(auto i: ch){
			i.second->dfs();
			int l = i.second->dep+1;
			if(l > dep){
				dep = l;
				id = i.first;
			}
		}
		// print(cnt, dep, (int)id-'a');
	}
	void go(bool f){
		if(!f) id = 0;
		while(cnt--)
			out.emplace_back('P');
		for(auto i: ch){
			if(i.first == id)
				continue;
			out.emplace_back(i.first);
			i.second->go(0);
			out.emplace_back('-');
		}
		if(id){
			out.emplace_back(id);
			ch[id]->go(1);
		}
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	node *rt = new node();
	cin>>n;
	while(n--){
		cin>>s;
		node *cur = rt;
		for(auto c: s){
			if(!cur->ch.count(c))
				cur->ch[c] = new node();
			cur = cur->ch[c];
		}
		cur->cnt++;
	}
	rt->dfs();
	rt->go(1);
	cout<<size(out)<<'\n';
	for(auto i: out)
		cout<<i<<'\n';
}