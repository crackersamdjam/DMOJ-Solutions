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
string op = "+-*/%";

bool isop(string s){
	return op.find(s) != -1;
}

int main(){
	int t = 5;
	while(t--){
		string str, t;
		vector<string> v;
		getline(cin, str);
		stringstream ss(str);
		while(getline(ss, t, ' ')){
			if(t != "")
				v.push_back(t);
		}
		
		bool rev = 0;
		if(isop(v.back())){
			reverse(all(v));
			rev = 1;
		}

		vector<string> st;
		for(auto i: v){
			st.push_back(i);
			while(size(st) >= 3 and !isop(st.back()) and !isop(st[size(st)-2]) and isop(st[size(st)-3])){
				int b = stoi(st.back()); st.pop_back();
				int a = stoi(st.back()); st.pop_back();
				if(rev)
					swap(a, b);
				string o = st.back();
				if(o == "+")
					st.back() = to_string(a+b);
				else if(o == "-")
					st.back() = to_string(a-b);
				else if(o == "*")
					st.back() = to_string(a*b);
				else if(o == "/")
					st.back() = to_string(a/b);
				else if(o == "%")
					st.back() = to_string(a%b);
				else abort();
			}
		}
		cout<<st[0]<<'\n';
	}
}