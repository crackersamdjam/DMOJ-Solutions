#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;

int N, M, a[3001], b[101], dp[3001][101][101][2];
//n, m, can take or not

int go(int i, int l, int r, int take){
    
    int &ret = dp[i][l][r][take];
    if(ret)
        return ret;
    
    if(i == N){
    
        //just took last one, so filler j
        if(!take)
            l++;
    
        //add all odd js
        for(int k = r; k >= l; k -= 2)
            ret += b[k];
        
        return ret;
    }
    
    //don't take
    ret = max(ret, go(i+1, l, r, 1));
    
    //insert
    if(l <= r)
        ret = max(ret, go(i, l+1, r, 1));
    
    //take
    if(take)
        ret = max(ret, go(i+1, l, r, 0) + a[i]);
    
    //take sugar
    if(l <= r && take)
        ret = max(ret, go(i, l, r-1, 0) + b[r]);
    
    return ret;
}

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++)
        scan(a[i]);
    
    scan(M);
    
    for(int i = 0; i < M; i++)
        scan(b[i]);
    
    sort(b, b+M);
    
    int hmmm = go(0, 0, M-1, 1);
    
    print(hmmm);
    
    return 0;
}