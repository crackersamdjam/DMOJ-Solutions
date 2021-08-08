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
const int MM = 1e6+5;

int t, bit[MM];
char s[105];

void up(int i, int v){
	for(; i < MM; i += i&-i)
		bit[i] += v;
}

int qu(int i){
	int v = 0;
	for(; i; i -= i&-i)
		v += bit[i];
	return v;
}

struct st{
	int op, x, l, r;
	bool operator<(const st &o) const{
		if(x != o.x)
			return x < o.x;
		return op < o.op;
	}
};
//op -1 remove, 0 query, 1 add

int main(){
	scan(t);
	while(t--){
		scanf("%s", s);
		vector<st> v;
		
		for(int z = 0; z < 2; z++){	
			int x, y, n, d, k;
			scan(x, y, n);

			while(n--){
				d = gc;
				scan(k);
				if(d == 'U' or d == 'D'){
					if(d == 'D')
						k = -k;
					int l = y, r = y+k;
					if(l > r)
						swap(l, r);

					v.push_back({0, x, l, r});
					y += k;
				}
				else{
					if(d == 'L')
						k = -k;
					
					int l = x, r = x+k;
					if(l > r)
						swap(l, r);

					v.push_back({1, l, y});
					v.push_back({-1, r, y});
					x += k;
				}
			}
		}
		long long ans = 0;
		sort(all(v));
		for(auto i: v){
			if(i.op)
				up(i.l, i.op);
			else
				ans += qu(i.r-1)-qu(i.l);
		}
		print(ans);
	}
}