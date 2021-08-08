#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 202, MOD = 1e5;

int N;
ll dp[MM][MM];
bool lead[MM][MM];
char str[MM];
bool flag;

inline int match(int a, int b){
    char c = str[a], d = str[b];
    if(c == ']' || c == ')' || c == '}' || d == '(' || d == '[' || d == '{')
        return 0;
    if(c == '?' && d == '?')
        return 3;
    if(c == '?' || d == '?')
        return 1;
    return (c == '(' && d == ')') || (c == '{' && d == '}') || (c == '[' && d == ']');
}

ll go(int l, int r){
    if(l >= r)
        return 1;
    
    if(dp[l][r] != -1)
        return dp[l][r];
    
    ll ret = 0;
    
    for(int i = l+1; i <= r; i += 2){
        
        ll val = match(l, i) * go(l+1, i-1) * go(i+1, r);
        if(val){
            ret += val;
            lead[l][r] |= lead[l+1][i-1] | lead[i+1][r];
        }
        
        if(ret >= MOD){
            ret %= MOD;
            lead[l][r] = 1;
        }
    }
    
    return dp[l][r] = ret;
}

int main(){
    
    memset(dp, -1, sizeof dp);
    
    scan(N);
    
    scanf("%s", str);
    
    ll ans = go(0, N-1);
    
    if(lead[0][N-1])
        printf("%05lld\n", ans);
    else
        print(ans);
    
    return 0;
}