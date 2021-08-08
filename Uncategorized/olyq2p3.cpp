#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;

int N, K;
ll dp[10][101][1<<10];
//row, number, previous king mask

vector<int> valid;

inline int cnt(int &mask){
    return __builtin_popcount(mask);
}

int main(){
    
    scan(N, K);
    
    for(int i = 0; i < (1<<N); i++){
        if(i & (i>>1))
            continue;
        valid.push_back(i);
        dp[0][cnt(i)][i] = 1;
    }
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j <= K; j++){
            for(int cur: valid){
                for(int pre: valid){
                    if(cur & pre || (cur >> 1) & pre || (cur << 1) & pre)
                        continue;
                    dp[i][j+cnt(cur)][cur] += dp[i-1][j][pre];
                }
            }
        }
    }
    
    ll ans = 0;
    
    for(int i: valid){
        ans += dp[N-1][K][i];
    }
    
    print(ans);
    
    return 0;
}