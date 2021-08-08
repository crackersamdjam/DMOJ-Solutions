#include <bits/stdc++.h>
#define MM 1000001
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef pair<int,int> pii;
pii a[MM];
int N, dp[MM];
int main(){
    sc(N);
    for(int i = 0; i < N; i++){
        sc(a[i].f);
        sc(a[i].s);
    }
    sort(a, a+N, [](pii &x, pii &y){return x.s < y.s;});
    int ptr = 0;
    for(int i = 0; i < MM; i++){
        while(a[ptr].s == i){
            pii &l = a[ptr];
            dp[l.s] = max(dp[l.s], dp[l.f]+1);
            ptr++;
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    printf("%d\n", dp[MM-1]);
    return 0;
}