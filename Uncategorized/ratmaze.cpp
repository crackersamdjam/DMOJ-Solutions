#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 502;

int N, a[MM][MM], vis[MM][MM], mx[] = {0,0,1,-1}, my[] = {1,-1,0,0};

void dfs(int i, int j){
    if(vis[i][j])
        return;
    
    vis[i][j] = 1;
    
    for(int k = 0; k < 4; k++){
        int ni = i+mx[k], nj = j + my[k];
        if(a[ni][nj] == 0)
            dfs(ni, nj);
    }
}

int main(){
    
    memset(a, 0x3f, sizeof a);
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scan(a[i][j]);
        }
    }
    
    dfs(1, 1);
    
    puts(vis[N][N]? "yes" : "no");
    
    return 0;
}