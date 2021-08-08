#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n;
vector<int> v = {-2};
vector<pair<int, int>> undo;

int main(){
	scan(n);
	while(n--){
		int op, a;
		scan(op, a);
		if(!op){
			if(a >= v.back()){
				v.emplace_back(a);
				undo.emplace_back(-1, -1);
			}
			else{
				int id = upper_bound(all(v), a)-v.begin();
				undo.emplace_back(id, v[id]);
				v[id] = a;
			}
		}
		else{
			while((int)undo.size() > a){
				auto rm = undo.back(); undo.pop_back();
				if(rm.second == -1)
					v.pop_back();
				else
					v[rm.first] = rm.second;
			}
		}
		print(v.size()-1);
	}
	
	
	
}