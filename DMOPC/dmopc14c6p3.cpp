#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int N, add = 132, add2 = 251;
vector<int> bus, bus2;

int main(){
    
    scan(N);
        
    for(int i = 0,n,p; i < N; i++){
        scan(n ,p);
        int m = n;
        for(auto &cnt: bus){
            int del = cnt*p/100;
            cnt -= del;
            int pl = min(m, add-cnt);
            cnt += pl;
            m -= pl;
        }
        while(m > 0){
            bus.push_back(min(m, add));
            m -= add;
        }
        
        m = n;
        for(auto &cnt: bus2){
            int del = cnt*p/100;
            cnt -= del;
            int pl = min(m, add2-cnt);
            cnt += pl;
            m -= pl;
        }
        while(m > 0){
            bus2.push_back(min(m, add2));
            m -= add2;
        }
    }
    
    print(bus.size() - bus2.size());
    
    return 0;
}