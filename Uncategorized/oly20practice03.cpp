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
const int MM = 19;

int n, m, r, c, a[MM][MM], id[MM];
ll sum[MM];

bool test(int l){
    //printf("test %d\n", l);
    for(int i = 0; i < (1<<(n-1)); i++){
        if(__builtin_popcount(i) != r)
            continue;
        id[0] = 0;
        for(int j = 1; j < n; j++){
            if(i&(1<<(j-1)))
                id[j] = id[j-1]+1;
            else
                id[j] = id[j-1];
        }
        memset(sum, 0, sizeof sum);
        int cnt = 0;
        for(int j = 0; j < m; j++){
            bool re = 0;
            for(int k = 0; k < n; k++){
                sum[id[k]] += a[k][j];
                if(sum[id[k]] > l)
                    re = 1;
            }
            if(re){
                //printf("re %d\n", j);
                if(j == 0 || ++cnt > c){
                    cnt = 1e9;
                    break;
                }
                memset(sum, 0, sizeof sum);
                for(int k = 0; k < n; k++){
                    sum[id[k]] += a[k][j];
                    if(sum[id[k]] > l)
                        cnt = 1e9;
                }
            }
        }
        /*
        print(i, cnt);
        for(int k = 0; k < n; k++)
            printf("%d ", id[k]);
        pc(10);
         */
        if(cnt <= c){
            //puts("YES");
            //print(sum[0], sum[1], sum[2]);
            return 1;
        }
    }
    return 0;
}

int main(){
    
    int maxx = 0;
    scan(n, m, r, c);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scan(a[i][j]);
            maxx = max(maxx, a[i][j]);
        }
    }
    
    ll lo = maxx, mid, hi = n*m*2e6+1;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(test(mid))
            hi = mid-1;
        else
            lo = mid+1;
    }
    
    print(lo);
    
    return 0;
}