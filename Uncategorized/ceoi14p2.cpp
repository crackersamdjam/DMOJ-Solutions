#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define ld double
using namespace std;
constexpr int MM = 1e4+1;
constexpr ld eps = 1e-9;

int ans, w, h, stx, sty, C, T, cx[MM], cy[MM], tx[MM], ty[MM];
int cnt[MM];
vector<int> out;
vector<ld> v;

int main(){
	scan(w, h, stx, sty, C);
	for(int i = 1; i <= C; i++)
		scan(cx[i], cy[i]);

	cx[0] = stx, cy[0] = sty;
	scan(T);
	for(int i = 1; i <= T; i++)
		scan(tx[i], ty[i]);
	
	for(int i = 1; i <= T; i++){
		ld tar = atan2(sty-ty[i], stx-tx[i]);
		v.clear();
		for(int j = 1; j <= T; j++)
			if(j != i)
				v.emplace_back(atan2(ty[i]-ty[j], tx[i]-tx[j]));

		sort(all(v));
		auto it = lower_bound(all(v), tar);
		bool f = 0;
		ld lo, hi;
		if(it == v.begin() || it == v.end()){
			hi = v.back();
			lo = v[0];
			f = 1;
		}
		else{
			hi = *it;
			lo = *--it;
		}
		for(int j = 1; j <= C; j++){
			ld ang = atan2(cy[j]-ty[i], cx[j]-tx[i]);
			if(!f){
				if(ang > lo+eps and ang+eps < hi)
					cnt[j]++;
			}
			else{
				if(ang > hi+eps or ang+eps < lo)
					cnt[j]++;
			}
		}
	}
	for(int i = 1; i <= C; i++)
		if(cnt[i] == T)
			out.emplace_back(i);
	
	print(out.size());
	for(int i: out)
		printn(i), pc(32);
}