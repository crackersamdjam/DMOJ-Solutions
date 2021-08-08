#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,a,R;
int main(){
    scanf("%lld%lld%lld",&N,&a,&R);
    printf("%lld\n",min(N,R/a));
    return 0;
}