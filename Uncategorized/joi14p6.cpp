#ifdef ONLINE_JUDGE
#include "secret.h"
#endif
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 1001;

int ans[MM][MM];

#ifndef ONLINE_JUDGE
int Secret(int a, int b){
    return a+b;
}
#endif

int Query(int a, int b){
    if(a == b)
        return ans[a][a];
    for(int i = a; i < b; i++){
        if(ans[a][i] != -1 and ans[i+1][b] != -1)
            return Secret(ans[a][i], ans[i+1][b]);
    }
}

void make(int l, int r){
    if(l == r)
        return;
    
    int m = (l+r)/2;
    
    for(int i = m-1; i >= l; i--)
        ans[i][m] = Secret(ans[i][i], ans[i+1][m]);
    for(int i = m+2; i <= r; i++)
        ans[m+1][i] = Secret(ans[m+1][i-1], ans[i][i]);
    make(l, m);
    make(m+1, r);
}

void Init(int n, int a[]){
    memset(ans, -1, sizeof ans);
    for(int i = 0; i < n; i++)
        ans[i][i] = a[i];
    make(0, n-1);
}

#ifndef ONLINE_JUDGE
int main(){
    
    int ina[] = {1,2,3,4,5};
    Init(5, ina);
    
    print(Query(0, 1));
    print(Query(1, 2));
    print(Query(0, 2));
    
    return 0;
}
#endif