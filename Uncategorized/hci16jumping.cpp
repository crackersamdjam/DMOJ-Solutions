#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2001;

int N, C;
ll dp[MM][MM];
bool a[MM][MM];
deque<int> q, add;

inline double thing(int j, int k, int col){
    return double(dp[col][j] - dp[col][k] + sq(j) - sq(k)) / double(2*(j-k));
}

int main(){
    
    memset(dp, 0x3f, sizeof dp);
    
    scan(N, C);
    
    for(int i = 0 ; i < C; i++){
        for(int j = 0; j < N; j++){
           a[j][i] = gc == '1';
           //swap
        }
        gc;
    }
    
    for(int i = 0; i < C; i++){
        if(a[0][i]){
            q.push_back(i);
            dp[0][i] = 0;
            //printf("start %d\n", i);
        }
    }
    
    for(int k = 1; k < N; k++){
        for(int i = 0; i < C; i++){
            if(!a[k][i])
                continue;
            
            while(q.size() > 1 && thing(q[0], q[1], k-1) <= i)
                q.pop_front();
    
            dp[k][i] = dp[k-1][q[0]] + sq(i-q[0]);
            
            while(add.size() > 1 && thing(add[add.size()-2], add.back(), k) > thing(add.back(), i, k))
                add.pop_back();
            
            add.push_back(i);
        }
        q = add;
        add.clear();
    }
    
    ll ans = LLONG_MAX;
    
    for(int i = 0; i < C; i++)
        ans = min(ans, dp[N-1][i]);
    
    print(ans);
    
    return 0;
}
/*
 * j < k
 * dp[j] + (i-j)^2 <= dp[k] + (i-k)^2
 * dp[j] - 2ij + j^2 <= dp[k] -2ik + k^2
 * dp[j] - dp[k] + j^2 - k^2 <= 2i(j - k)
 * (dp[j] - dp[k] + j^2 - k^2) / 2(j-k) <= i
 *
 * fun(a, b) > fun(b, i)
 * will never use b
 */