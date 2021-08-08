#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, ans, cnt[20];
string s[20];

void go(int m){
    fill(cnt, cnt+20, 0);
    for(int i = 0; i < 20; i++){
        if(m&(1<<i)){
            for(int j = 0; j < s[i].size(); j++)
                cnt[j] += s[i][j]-'0';
        }
    }
    for(int i = 0; i < 20; i++){
        if(cnt[i] > 9)
            return;
    }
    ans = max(ans, __builtin_popcount(m));
}

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
    }
    
    for(int i = 1; i < (1<<n); i++){
        go(i);
    }
    
    print(ans);
    
    return 0;
}