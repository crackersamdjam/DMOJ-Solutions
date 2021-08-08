#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 1002;

int N, sa[MM], sb[MM], dp[MM][MM];
char a[MM], b[MM];

inline bool match(int i, int j){
    i--; j--;
    if(a[i] == 'W' && b[j] == 'L' && sa[i] > sb[j])
        return 1;
    if(a[i] == 'L' && b[j] == 'W' && sa[i] < sb[j])
        return 1;
    return 0;
}

int main(){
    
    scan(N);
    scanf("%s", a);
    for(int i = 0; i < N; i++)
        scan(sa[i]);
    scanf("%s", b);
    for(int i = 0; i < N; i++){
        scan(sb[i]);
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(match(i, j)){
                dp[i][j] = dp[i-1][j-1] + sa[i-1] + sb[j-1];
            }
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }
    
    print(dp[N][N]);
    
    return 0;
}