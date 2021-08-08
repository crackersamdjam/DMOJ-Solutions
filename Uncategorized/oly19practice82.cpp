#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}
const int MM = 1e6+1;
int n, m;
bool pre[MM], cur[MM];

void run(long long k){
    for(int i = 0; i < n; i++){
        pre[i] = cur[i];
        //printn(pre[i]);
    }
    //pc(10);
    for(int i = 0; i < n; i++){
        //print(i, (i+k)%n, pre[i], pre[(i+k)%m]);
        cur[i] = pre[i]^pre[(i+k)%n];
    }
}

int main(){
    init();
    scan(n, m);
    for(int i = 0; i < n; i++){
        cur[i] = gc-'0'; gc;
        //print(i, cur[i]);
    }

    for(int i = 0; i < 32; i++){
        if(m&(1LL<<i))
            run(1LL<<i);
    }

    for(int i = 0; i < n; i++)
        print(cur[i]);
    
    return 0;
}