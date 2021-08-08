#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ld = long double;
const int MM = 1e5+2;
const ld eps = 1e-11;

int n, k, cnt[MM], q[MM];
ld dp[MM];

ld thing(int j, int k){
	return (j-k)/(dp[j] - dp[k]);
}

bool run(ld c){
	int l = 0, r = 0;
	for(int i = 1; i <= n; i++){

		while(r-l >= 1 && i*(dp[q[l]] - dp[q[l+1]]) <=  q[l] - q[l+1])
            l++;


		dp[i] = dp[q[l]] + ld(i-q[l])/i - c;
		cnt[i] = cnt[q[l]] + 1;

		while(r-l >= 1 && thing(q[r-1], q[r]) >= thing(q[r], i))
			r--;

		q[++r] = i;
	}
	//out << c << ' ' << cnt[n] << ' ' << dp[n]+cnt[n]*c << '\n';
	return cnt[n] <= k;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    
    scan(n, k);

    ld l = 0, m, r = 20;
    while(r-l > eps){
    	m = (l+r)/2;
    	if(run(m))
    		r = m;
    	else
    		l = m;
    }

    run(r);

    printf("%.9Lf\n", dp[n]+r*k);
    
    return 0;
}
/*
dp[i] = dp[j] + (i-j)/i + c
dp[j] + (i-j)/i <= dp[k] + (i-k)/i; j < k
dp[j] - dp[k] <= (i-k)/i - (i-j)/i
dp[j] - dp[k] <= ((i-k) - (i-j))/i
i*(dp[j] - dp[k]) <= (i-k) - (i-j)
i*(dp[j] - dp[k]) <= j-k
i <= (j-k)/(dp[j] - dp[k])
*/