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
const int MM = 1e3+5;


array<int, 2> a[MM];
int n;
int dpl[MM], dpr[MM];

int main(){
	scan(n);
	for(int i = 0; i < n; i++){
		scan(a[i][0], a[i][1]);
		dpl[i] = dpr[i] = MM;
	}
	sort(a, a+n);

	for(int i = n-1; i >= 0; i--){
		dpl[i] = min(dpl[i], 1+min(dpl[i+1], dpr[i+1]));
		dpr[i] = min(dpr[i], 1+min(dpl[i+1], dpr[i+1]));
		for(int j = i+1; j < n; j++){
			if(a[i][0]+a[i][1] >= a[j][0]){
				dpr[i] = min(dpr[i], dpl[j+1]+1);
				dpr[i] = min(dpr[i], dpr[j]);
				if(a[i][0]+a[i][1] <= a[j][0]+a[j][1])
					break;
			}
			else break;
		}
		for(int j = i-1; j >= 0; j--){
			if(a[i][0]-a[i][1] <= a[j][0]){
				dpl[j] = min(dpl[j], dpl[i]);
				if(a[i][0]-a[i][1] >= a[j][0]-a[j][1])
					break;
			}
			else break;
		}
	}
	print(min(dpl[0], dpr[0]));
}