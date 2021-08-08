#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 302;

int N, dp[MM][MM];

string str;

inline bool match(int na, int nb){
    
    char a = str[na], b = str[nb];
    
    if(a == '(' and b == ')')
        return 1;
    if(a == '[' and b == ']')
        return 1;
    return 0;
}

int go(int l, int r){
    
    if(l > r)
        return 0;
    
    int &ret = dp[l][r];
    
    if(ret != -1)
        return dp[l][r];
    
    ret = go(l+1, r) + 1;
    ret = min(ret, go(l, r-1) + 1);
    //add one to make it work
    
    if(match(l, r)){
        ret = min(ret, go(l+1, r-1));
    }
    
    for(int k = l+1; k < r; k++){
        if(match(l, k)){
            ret = min(ret, go(l+1, k-1) + go(k+1, r));
        }
        ret = min(ret, go(l, k) + go(k+1, r));
        //AB
    }
    
    return ret;
}

int main(){
    
    memset(dp, -1, sizeof dp);
    
    cin >> str;
    
    N = str.size();
    
    for(int i = 0; i < N; i++){
        dp[i][i] = 1;
        if(i < N-1 and match(i, i+1))
            dp[i][i+1] = 0;
    }
    
    print(go(0, N-1));
    
    return 0;
}
/*
][][(())((([])))
 */