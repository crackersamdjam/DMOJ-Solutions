#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 401;

int N, a[MM], psa[MM], ans;
bool dp[MM][MM];
//whether left, right and be combined

int main(){
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        psa[i] = psa[i-1] + a[i];
        dp[i][i] = 1;
        ans = max(ans, a[i]);
    }
    
    for(int d = 1; d <= N; d++){
        //distance
        for(int i = 1; i+d <= N; i++){
            int j = i+d;
            
            //find split point(s)
            //depending on whether one or two splits
            
            //two splits
            for(int k = i; k <= j; k++){
                for(int l = k; l <= j; l++){
                    if(dp[i][k] && ((k+1 > l-1) || dp[k+1][l-1]) && dp[l][j] && (psa[k] - psa[i-1] == psa[j] - psa[l-1])){
                        dp[i][j] = 1;
                        //between k and l is centre ball
                        ans = max(ans, psa[j] - psa[i-1]);
                    }
                }
            }
        }
    }
    
    print(ans);
    
    return 0;
}