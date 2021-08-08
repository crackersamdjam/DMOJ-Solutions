#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
const int MM = 500002;

int N;
ll M, a[MM];
int main(){
    sc(N); sc(M);
    for(int i = 0; i < N; i++)
        sc(a[i]);
    
    int l = 0, r = 0, ans = INT_MAX;
    ll sum = a[0];
    while(r < N){
        if(sum >= M){
            ans = min(ans, (r-l+1));
            sum -= a[l++];
        }else{
            sum += a[++r];
        }
    }
    printf("%d\n", ans == INT_MAX? -1: ans);
    return 0;
}