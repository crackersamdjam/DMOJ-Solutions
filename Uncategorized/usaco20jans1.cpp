#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1002;

int n, k, a[MM];
long long v,ans;

int main(){
    scan(n, k);
    for(int i = 0; i < n; i++)
        scan(a[i]);
    for(int l = 1; l <= 1000; l++){
        map<int, int, greater<int>> cnt;
        for(int i = 0; i < n; i++){
            int sub = a[i]/l;
            cnt[l] += sub;
            cnt[a[i]-sub*l]++;
        }
        int f = k/2, s = f;v = 0;
        for(auto x: cnt){
            if(f){
                int sub = min(f, x.second);
                f -= sub;
                x.second -= sub;
            }
            if(!f){
                int sub = min(s, x.second);
                s -= sub;
                x.second-= sub;
                v += sub*x.first;
            }
        }
        ans = max(ans, v);
    }
    print(ans);
    
    return 0;
}