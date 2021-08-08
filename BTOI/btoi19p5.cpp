#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

string A, B;
pair<int, pair<int, int>> ans = {0, {1, 1}};

///find t in s
vector<int> kmp(string s, string t){
	int sub = sz(s);
	s = s+"#"+t;
	
	vector<int> pi(sz(s)), ret(sz(t));
	pi[0] = 0;
	for(int i = 1; i < sz(s); i++){
		int j = pi[i-1];
		while(j and s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	for(int i = 0; i < sz(t); i++)
		ret[i] = pi[sub+1+i];
	return ret;
}

void run(bool rev){
	for(int m = 0; m < sz(A); m++){
		auto p = kmp(A.substr(m), B);
		reverse(all(B));
		string ss = A.substr(0, m);
		reverse(all(ss));
		auto r = kmp(ss, B);
		reverse(all(B));

		for(int i = 0; i < sz(B); i++){
			int rs = (i >= 0 and i < sz(p)) ? p[i] : 0; //rs of a, ls of b
			if(!rs) continue;
			int o = sz(B)-1-(i+1); //correct
			int ls = (o >= 0 and o < sz(r)) ? r[o] : 0; //ls of a, rs of b

			int len = ls+rs;
			int a = (m-1-ls+1);
			int b = !rev ? (i-rs+1) : (sz(B)-1-(i+1+ls-1));

			ans = max(ans, {len, {a, b}});
		}
	}
}

int main(){
	cin>>A>>B;
	run(0);
	reverse(all(B));
	run(1);	
	print(ans.first);
	print(ans.second.first, ans.second.second);
}