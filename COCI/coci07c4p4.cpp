#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(32);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 5002;

int T, N, num[MM], a[MM], t1, t2;
bool dp[MM], fst[MM];

int main(){
    
    scan(T, N);
    
    dp[0] = 1;
    for(int i = 1,t; i <= N; i++){
        scan(t);
        a[i] = t;
        for(int j = T; j >= t; j--){
            if(!dp[j] && dp[j-t]){
                dp[j] = 1;
                num[j] = i;
            }
        }
    }
    
    int val = T;
    for(; !dp[val]; val--);
    
    while(val){
        fst[num[val]] = 1;
        val -= a[num[val]];
    }
    
    for(int i = 1; i <= N; i++){
        if(fst[i]){
            print(t1);
            t1 += a[i];
        }
        else{
            print(t2);
            t2 += a[i];
        }
    }
    
    
    return 0;
}
/*
 * two on break at a time
 * comes down to splitting sum of times as evenly as possible
 */