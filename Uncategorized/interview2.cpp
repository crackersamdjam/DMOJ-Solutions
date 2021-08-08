#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 5002;

int n, a[MM];
long long ans;
set<int> done;

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++)
        scan(a[i]);
    
    sort(a, a+n);
    
    for(int i = 0; i < n; i++){
        if(i && a[i] == a[i-1]){
            if(!done.count(i)){
                done.insert(i);
                ans += binary_search(a, a+n, a[i]*2);
            }
            continue;
        }
        for(int j = i+1; j < n; j++){
            if(j && a[j] == a[j-1])
                continue;
            ans += binary_search(a, a+n, a[i]+a[j]);
        }
    }
    if(!ans)
        ans = -1;
    print(ans);
    
    return 0;
}