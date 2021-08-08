#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
const int MM = 1e6+2;

int N;
ll R, S, a[MM];
llu dp[MM];

deque<pair<int, ll>> q;

int main(){

#ifndef ONLINE_JUDGE
    freopen("DATA41.txt", "r", stdin);
#endif
    
    for(int tc = 1; tc <= 10; tc++){
        
        q.clear();
        
        scan(N, R, S);
        
        scan(a[1]);
        dp[1] = (llu)a[1]*(S+R);
        
        q.push_back({1, a[1]});
        
        for(int i = 2; i <= N; i++){
            
            dp[i] = ULLONG_MAX;
            
            scan(a[i]);
            
            while(!q.empty()){
                auto j = q.back();
                
                ll sub = min(a[i], a[j.first]);
                ll rem = max(0LL, a[i]-a[j.first]);
                dp[i] = min(dp[i], dp[j.first] + (llu)sub*(llu)R*(i-j.first) + (llu)rem*(llu)(S+R));
                
                if(j.second <= a[i]){
                    q.pop_back();
                }
                else{
                    break;
                }
            }
            
            while(!q.empty() and a[i] >= q.back().second)
                q.pop_back();
            
            q.push_back({i, a[i]});
        }
        
        printf("%llu\n", dp[N]);
    }
    
    return 0;
}