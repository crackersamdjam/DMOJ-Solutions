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
const int MM = 102;

int M, Q, a[MM], dp[MM], pre[MM];
//minimum time to get first n ppl across, group time spent
string names[MM];
bool split[MM];

int main(){
    
    scan(M, Q);
    
    for(int i = 1; i <= Q; i++){
        cin >> names[i];
        scan(a[i]);
        
        dp[i] = dp[i-1] + a[i];
        pre[i] = i-1;
        //travel alone
        
        for(int j = max(1, i-M+1); j < i; j++){
            
            int slow = 0;
            for(int k = j; k <= i; k++)
                slow = max(slow, a[k]);
            
            if(dp[j-1] + slow < dp[i]){
                dp[i] = dp[j-1] + slow;
                pre[i] = j-1;
            }
        }
    }
    printf("Total Time: %d\n", dp[Q]);
    
    for(int i = pre[Q]; i; i = pre[i]){
        split[i] = 1;
    }
    for(int i = 1; i <= Q; i++){
        cout << names[i];
        if(split[i])
            pc(10);
        else
            pc(32);
    }
    return 0;
}