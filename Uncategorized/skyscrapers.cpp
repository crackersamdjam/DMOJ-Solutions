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
const int MM = 1e5+5;

int n, m, a[MM], b[MM], psa[MM], psb[MM], lc, rc, ansl, ansr;

int main(){
	scan(n, m, lc, rc);
	for(int i = 0; i < n; i++){
		scan(a[i]);
	}
	for(int i = 0; i < m; i++){
		scan(b[i]);
	}
	sort(a, a+n);
	sort(b, b+m);
	if(a[n-1] != b[m-1]){
		puts("Impossible");
		return 0;
	}

	psb[0] = b[0];
	for(int i = 1; i <= m; i++)
		psb[i] = psb[i-1]+b[i];

	for(int i = 0, l = 0; i < n; i++){
		while(l < m && b[l] < a[i])
			l++;
		// print(i, a[i], l, b[l], l ? psb[l-1] : 0, a[i]*(m-l));
		ansr += a[i]*(m-l);
		ansr += l ? psb[l-1] : 0;
	}

	int la = n-1, lb = m-1;
	while(la >= 0 or lb >= 0){
		if(la >= 0 and lb >= 0 and a[la] == b[lb]){
			ansl += a[la];
			la--, lb--;
		}
		else if(lb < 0){
			ansl += a[la];
			la--;
		}
		else if(la < 0){
			ansl += b[lb];
			lb--;
		}
		else if(a[la] < b[lb]){
			ansl += b[lb];
			lb--;
		}
		else{
			ansl += a[la];
			la--;
		}
		// print(la, lb, ansl);
	}

	printf("Minimum: %d, maximum: %d\n", ansl*lc, ansr*rc);
}