#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+2;

int N, a[MM], suf[MM];
ll ans;

int main(){
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        suf[i] = max(suf[i], a[i]);
    }
    
    for(int i = N; i; i--)
        suf[i] = max(suf[i], suf[i+1]-1);
    
    for(int i = 1; i <= N; i++){
        suf[i] = max(suf[i], suf[i-1]);
        //printf("%d ", suf[i]);
        ans += max(0, suf[i] - a[i]);
    }
    
    print(ans);
    
    return 0;
}
/*
 * max array from suffix
 * loop through, -1 every day
 * ans is what mark needs to be at day 1
 * then just find cnt[i] - a[i] - 1
 */