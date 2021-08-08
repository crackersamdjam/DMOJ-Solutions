#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
const int lcm = 2520;
ll dp[20][lcm+2][(1<<8) + 2], a, b;
int s[22], T, N;
ll go(int pos, int val, int mask, bool r){
    ll ret = (r ? -1 : dp[pos][val][mask]);
    if(ret != -1)
        return ret;

    if(pos == 0){
        for(int i = 2; i <= 9; i++){
            if(mask & (1<<(i-2))){
                if(val % i)
                    return 0;
            }
        }
        return (r ? 1: dp[pos][val][mask] = 1);
    }

    ret = 0;
    for(int i = 0, nmask; i <= (r ? s[N-pos]: 9); i++){
        nmask = mask;
        if(i > 1)
            nmask |= (1<<(i-2));
        ret += go(pos-1, (val*10 + i) % lcm, nmask, r & (i == s[N-pos]));
    }
    return (r ? ret : dp[pos][val][mask] = ret);
}
inline ll f(ll n){
    string str = to_string(n);
    N = str.size();
    for(int i = 0; i < N; i++)
        s[i] = str[i] - '0';

    return go(N, 0, 0, 1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    sc(T);
    while(T--){
        sc(a); sc(b);
        printf("%lld\n", f(b) - f(a-1));
    }
    return 0;
}