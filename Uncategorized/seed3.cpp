#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MM 100002
ll arr[MM];
int main() {
    ll I,N,J; scanf("%lld%lld%lld",&I,&N,&J);
    ll i,f,k;
    while(J--){
        scanf("%lld%lld%lld",&i,&f,&k);
        arr[i] += k;
        arr[f+1] -= k;
    }
    arr[0] = 0;
    ll cnt = 0;
    for(ll i = 1; i <= I; i++){
        arr[i] += arr[i-1];
        if(arr[i] < N)
            cnt++;
    }
    printf("%lld\n",cnt);
    return 0;
}