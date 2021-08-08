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

ll bi[50][50];

ll cat(int a){
    if(a == 0)
        return 1;
    return bi[2*a][a] - bi[2*a][a-1];
}

string recur(int n, ll k){
    if(n == 0)
        return "";
    if(n == 1)
        return "RD";
    for(int i = 1; i < n; i++){
        ll val = cat(i-1)*cat(n-i);
        if(k < val){
            ll sec = k%cat(n-i);
            ll fir = (k-sec)/cat(n-i);
            return "R" + recur(i-1, fir) + "D" + recur(n-i, sec);
        }
        k -= val;
    }
    return "R" + recur(n-1, k) + "D";
}

int main(){
    
    int n, k;
    
    bi[0][0] = 1;
    for(ll i = 1; i <= 42; i++){
        bi[i][0] = 1;
        for(ll j = 1; j <= 42; j++)
            bi[i][j] = bi[i-1][j] + bi[i-1][j-1];
    }
    
    scan(n, k);
    n--, k--;
    
    if(k >= cat(n)){
        puts("ERROR");
        return 0;
    }
    
    k = cat(n)-k-1;
    
    cout << recur(n, k) << '\n';
    
    return 0;
}