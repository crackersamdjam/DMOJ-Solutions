#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

int n;
ll a[11];

bool run(){
    for(int i = 2; i < 10; i++){
        if(a[i] + a[i-2] != a[i-1]*2)
            return 0;
    }
    return 1;
}

bool geo(){
    for(int i = 2; i < 10; i++){
        if(a[i] * a[i-2] != a[i-1]*a[i-1])
            return 0;
    }
    return 1;
}

int main(){
    
    cin >> n;
    while(n--){
        for(int i = 0; i < 10; i++)
            cin >> a[i];
        if(run()){
            if(geo())
                puts("both");
            else
                puts("arithmetic");
        }
        else{
            if(geo())
                puts("geometric");
            else
                puts("neither");
        }
    }
    
    return 0;
}