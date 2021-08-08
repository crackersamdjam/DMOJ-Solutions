#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int gcd(int gcd_a, int gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}

int n, d[501], c[501];
map<int, int, greater<int>> dp;

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        scan(d[i], c[i]);
        dp[d[i]] = c[i];
    }
    
    //merge afterwards
    //should be using 1-n in order to merge
    
    for(int i = 0; i < n; i++){
        for(auto it = dp.begin(); it != dp.end(); it++){
            int v = gcd(it->first, d[i]);
            if(v == it->first || v == d[i])
                continue;
            if(!dp.count(v) || dp[v] >= it->second + c[i]){
                //printf("insert %d\n", v);
                dp[v] = it->second + c[i];
            }
            else if(v != 1){
                //printf("gone %d\n", it->first);
                //dp.erase(it--);
            }
        }
    }
    
    if(dp[1])
        print(dp[1]);
    else
        puts("Hooray!");
    
    
    return 0;
}
/*
 * no point considering multiples of existing factor (if cost is >= lower)
 * start from back of map, whenever merging down >= cost, delete it
 * will always only have possible bests, each with their own factors n*n/2 every two only go down once
 */