#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e6+2;

char a[MM], b[MM];
int N, dp[MM], psa[MM], psb[MM];

inline int query(int l, int r){
    return psa[r] - psa[max(0, l-1)] + psb[r] - psb[max(0, l-1)];
}

int main(){
    
    scan(N);
    
    scanf("%s %s", a+1, b+1);
    
    for(int i = 1; i <= N; i++){
        psa[i] = psa[i-1] + (a[i] == '0');
        psb[i] = psb[i-1] + (b[i] == '1');
        dp[i] = 1e9;
        if(a[i] == b[i])
            dp[i] = dp[i-1];
        else if(b[i] == '1')
            dp[i] = dp[i-1]+1;
        
        if(i >= 3)
            dp[i] = min(dp[i], dp[i-3] + query(i-2, i)+1);
        if(i >= 4)
            dp[i] = min(dp[i], dp[i-4] + query(i-3, i)+1);
    }
    
    print(dp[N]);
    
    return 0;
}