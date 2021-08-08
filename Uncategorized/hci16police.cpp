#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int M = 1e5+2;

int n, h;
ll a[M], dp[M];
deque<int> q;

#define sq(x) (x)*(x)

double thing(int j, int k){
    j++, k++;
    return (dp[k-1] - dp[j-1] + sq(a[k]) - sq(a[j]))/(2.0*(a[k] - a[j]));
}

int main(){
    
    scan(n, h);
    
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    q.push_back(0);
    
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    
    for(int i = 1; i <= n; i++){
        
        while(q.size() > 1 && thing(q[0], q[1]) <= a[i])
            q.pop_front();
        
        dp[i] = dp[q[0]] + sq(a[i] - a[q[0]+1]) + h;
        
        while(q.size() > 1 && thing(q[q.size()-2], q.back()) > thing(q.back(), i))
            q.pop_back();
        
        q.push_back(i);
    }
    
    print(dp[n]);
    
    return 0;
}
/*
 dp[j-1] + (a_i-a_j)^2 <= dp[k-1] + (a_i-a_k)^2; j < k
 dp[j-1] + a_i^2 - 2a_ia_j + a_j^2 <= dp[k-1] + a_i^2 - 2a_ia_k + a_k^2
 2a_ia_k - 2a_ia_j <= dp[k-1] - dp[j-1] + a_k^2 - a_j^2
 a_i <= (dp[k-1] - dp[j-1] + a_k^2 - a_j^2)/(2(a_k - a_j)
 */