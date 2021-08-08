#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;

int tc = 5, N, M, a[22][22], mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};
bool ok, vis[22][22];

void dfs(int i, int j, int v){
    
    if(vis[i][j])
        return;
    
    vis[i][j] = 1;
    
    if(i < 2 or j < 2 or i >= N or j >= M){
        ok = 0;
        return;
    }
    
    for(int k = 0; k < 4; k++)
        if(a[i+mx[k]][j+my[k]] < v)
            dfs(i+mx[k], j+my[k], v);
}

int main(){
    
    while(tc--){
        
        scan(N, M);
        
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= M; j++)
                scan(a[i][j]);
        
        int ans = 0;
        
        for(int i = 2; i < N; i++){
            for(int j = 2; j < M; j++){
                
                for(int k = 1; a[i][j] + k <= 50; k++){
                    ok = 1;
                    memset(vis, 0, sizeof vis);
                    dfs(i, j, a[i][j] + k);
    
                    if(!ok)
                        break;
    
                    ans++;
                    //printf("%d %d\n", i, j);
                }
            }
        }
        
        print(ans);
    }
    
    return 0;
}
/*
 * try every height to see if dfs leaves map
*/