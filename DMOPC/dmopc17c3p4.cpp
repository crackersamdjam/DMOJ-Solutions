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
const int MM = 2e5+5;

int n, q;
bool done[MM];
map<int, pair<int, int>> st;

int main(){
	scan(n, q);
	int op, i, j, v;
	st[0] = {0, 0};
	st[2*n+1] = {n+1, 0};
	while(q--){
		scan(op);
		if(op == 1){
			scan(i, j, v);
			st[v] = {j, i-1};
			done[v] = 1;
		}
		else if(op == 2){
			scan(v);
			if(done[v]){
				print(1);
				continue;
			}
			auto r = st.lower_bound(v);
			auto l = r; l--;

			int la = l->second.first+1;
			int lb = l->first-l->second.first+1;

			int d = v-l->first-1;
			int ra = la+d;
			int rb = lb+d;
			if(l->second.second != r->second.second){
				swap(la, lb);
				swap(ra, rb);
			}

			int ra2 = r->second.first-1;
			int rb2 = n-((2*n-r->first+1)-(n+1-r->second.first));

			int d2 = r->first-v-1;
			int la2 = ra2-d2;
			int lb2 = rb2-d2;

			la = max(la, la2);
			lb = max(lb, lb2);
			ra = min(ra, ra2);
			rb = min(rb, rb2);

			int cnta = ra-la+1;
			int cntb = rb-lb+1;
			print(cnta+cntb);
		}
		else abort();
	}
}