#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 21, NN = 1e5+2;

vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};
int n, cnt[1<<MM], ans[NN];

int main(){
    
    scan(n);
    for(int i = 0,v; i < n; i++){
        scan(v);
        int m = 0;
        for(int j = 0; j < MM; j++){
            if(v%p[j] == 0)
                m |= (1<<j);
        }
        cnt[m]++;
    }
    
    memset(ans, 0x3f, sizeof ans);
    
    for(int i = 0; i < MM; i++){
        for(int m = 0; m < (1<<MM); m++){
            if(m&(1<<i))
                cnt[m] += cnt[m^(1<<i)];
            ans[cnt[m]] = min(ans[cnt[m]], __builtin_popcount(m));
        }
    }
    
    for(int i = n-1; i; i--)
        ans[i] = min(ans[i], ans[i+1]);
    
    for(int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    
    return 0;
}