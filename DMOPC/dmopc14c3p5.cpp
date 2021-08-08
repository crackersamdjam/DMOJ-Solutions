#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int N, M, ans;
int a[52], dp[1<<20], pre[1<<20], tc[1<<20];
int main(){
    memset(dp,0x3f,sizeof dp);
    sc(N); sc(M);
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= M; j++){
            if(getchar_unlocked() == 'X'){
                a[j] |= (1<<i);
                ans |= (1<<i);
            }
        }
        getchar_unlocked();
    }
    dp[0] = 0;
    pre[0] = -1;
    tc[0] = -1;
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < (1<<N); j++){
            int nx = j | a[i];
            if(dp[j] + 1 < dp[nx]){
                dp[nx] = dp[j] + 1;
                pre[nx] = j;
                tc[nx] = i;
            }
        }
    }
    if(dp[ans] == 0){
        printf("1\n1\n");
        return 0;
    }
    printf("%d\n", dp[ans]);
    vector<int> vec;
    while(1){
        vec.push_back(tc[ans]);
        ans = pre[ans];
        if(pre[ans] == -1)
            break;
    }
    for(int i: vec)
        printf("%d ", i);
    return 0;
}