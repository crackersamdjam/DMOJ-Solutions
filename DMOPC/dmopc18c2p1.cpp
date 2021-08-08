#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,a,b,c,d,x,y;
int main(){
    a = c = INT_MAX;
    scanf("%lld",&N);
    for(int i = 0; i < N; i++){
        scanf("%lld%lld",&x,&y);
        a = min(a,x);
        b = max(b,x);
        c = min(c,y);
        d = max(d,y);
    }
    printf("%lld\n",2*(b-a)+2*(d-c));
    return 0;
}