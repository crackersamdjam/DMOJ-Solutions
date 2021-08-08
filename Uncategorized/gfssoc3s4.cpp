#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int mod = (1e9)+7;
int R, C;
typedef long long ll;
ll dp[102][3002], ans;
vector<int> v;
void f(int pos, int mask){
    if(pos >= C-1){
        v.push_back(mask);
        return;
    }
    f(pos+1, mask);
    if(pos <= C-2)
        f(pos+3, mask | (1<<pos));
}
int main(){
    sc(R); sc(C);
    f(1,0);
    for(int i = 0; i < v.size(); i++){
        dp[0][i] = 1;
    }
    ans = (v.size()-1) % mod;
    for(int i = 1; i < R-1; i++){
        for(int j = 0; j < v.size(); j++){ // current
            for(int k = 0; k < v.size(); k++){ // previous
                if(((v[j]&v[k])==0) && (((v[j]<<1)&v[k])==0) && (((v[j]>>1)&v[k]) == 0)){
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
                }
            }
            if(v[j] != 0){
                ans = (ans + dp[i][j]) % mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
/*
50 22
753128983

97 22
486296353

100 22
2602308
 */