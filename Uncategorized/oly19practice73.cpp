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
const int MM = 1002;
int n, t, ans;
pair<int, int> a[MM];
int v[MM];

int main(){
    init();
    scan(n, t);
    for(int i = 0; i < n; i++)
        scan(a[i].first, a[i].second);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v[j] = a[j].first/(1+(i==j)) + a[j].second;
        }
        sort(v, v+n);
        int cnt = 0, rem = t;
        for(int j = 0; j < n; j++){
            if(rem < v[j])
                break;
            rem -= v[j];
            cnt++;
        }
        ans = max(ans, cnt);
    }

    print(ans);
    
    return 0;
}