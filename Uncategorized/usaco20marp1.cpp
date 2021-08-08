#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 2005;
const ll mod = 1e9+7;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

int n;
char s[MM][MM];
ll dp[MM][MM], down[MM][MM], ans, pw[MM*2];
ll *p = pw+MM;

int main(){
    scanf("%d", &n);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%s", s[i]+1);
        p[i] = p[i-1]*2%mod;
    }
    ll inv = fpow(2, mod-2, mod);
    for(int i = 1; i <= n; i++){
        p[-i] = p[-i+1]*inv % mod;
    }
    /*
    dp[0][0] = 1;
    if(s[1][1] == 'W')
        down[0][1] = fpow(2, mod-2, mod); // 1/2
    */
//    down[0][1] = fpow(2, mod-2, mod);
//    for(int j = 2; j <= n; j++)
//        down[0][j] = fpow(4, mod-2, mod);
//    dp[0][0] = 1;

/*
    ll stv = 1;
    int st = 1;
    while(s[st][1] == 'W'){
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            cnt += (s[st][j] == 'W');
        stv = stv*p[cnt]%mod;
        st++;
    }
    dp[st-1][0] = stv;
    */
    dp[0][0] = 1;
//    for(int j = 1; j <= n; j++){
//        if(s[1][j] == 'W' and s[1][j-1] == '.')
//            down[0][j] = fpow(4, mod-2, mod);
//    }

    for(int i = 1; i <= n; i++){
        ll sum = 0;
        int no = 0;
        for(int j = 1; j <= n; j++)
            no += (s[i][j] == 'W');
        
        for(int j = 1; j <= n; j++){
            sum = (sum + dp[i-1][j-1]) % mod;
            
            down[i][j] = down[i-1][j]*p[n-no] % mod;
            
            if(s[i][j] == 'W'){
                if(s[i][j-1] != 'W'){
                    int cnt = n-no-2 + (j==1);
                    down[i][j] += sum*p[cnt]%mod;
                    down[i][j] %= mod;
                }
                
                //can not use this as split
                continue;
            }
            
            if(s[i][j-1] != 'W'){
                //can change col in this case
                
                int cnt = n-no-2 + (j==1);
                dp[i][j] += sum*p[cnt]%mod;
                dp[i][j] %= mod;
                
                //add to down
                down[i][j] += sum*p[cnt]%mod;
                down[i][j] %= mod;
            }
            else{
//                int cnt = n-no-1; //one more
                //add to down
//                down[i][j] += sum*p[cnt]%mod;
//                down[i][j] %= mod;
            }
    
            //bring down last left and right sprinkler
            dp[i][j] = (dp[i][j] + down[i-1][j]*p[n-no]) % mod;
        }
        dp[i][n+1] = dp[i-1][n+1]*p[n-no] % mod;
        
        sum = (sum + dp[i-1][n]) % mod;
        //printerr("sum", i, sum);
        
        if(s[i][n] != 'W'){
//            if(i == st and st != 1) sum--; //edge case
            
            dp[i][n+1] += sum*p[n-no-1]%mod;
            dp[i][n+1] %= mod;
        }
    }
    
    for(int j = 1; j <= n+1; j++){
        ans = (ans + dp[n][j])%mod;
    }
    print(ans);
    
    return 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n+1; j++)
            printf("%lld ", dp[i][j]);
        pc(10);
    }
    pc(10);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n+1; j++)
            printf("%lld ", down[i][j]);
        pc(10);
    }
    
    return 0;
}