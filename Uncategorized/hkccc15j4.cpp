#include <bits/stdc++.h>
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef pair<int,int> pii;
const int MM = 1e5+2;
pii a[MM];
int L,N;
int main(){
    sc(L); sc(N);
    for(int i = 0; i < N; i++){
        sc(a[i].f); sc(a[i].s);
    }
    sort(a, a+N);
    a[N] = {L, L};
    int pre = 0, ans = 0;
    for(int i = 0; i <= N; i++){
        if(pre < a[i].f)
            ans = max(ans, a[i].f - pre);
        pre = max(pre, a[i].s);
    }
    printf("%d\n", ans);
    return 0;
}