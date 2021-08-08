#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a, ll b, ll p){
    ll ans = 1;
    a %= p;
    while(b > 0){
        if(b & 1)
            ans = (ans*a)%p;
        b >>= 1;
        a = (a*a)%p;
    }
    return ans;
}
bool test(ll d, ll n){
    ll a = rand() % (n-4) + 2;
    ll x = pow(a,d,n);
    if(x == 1 || x == n-1)
        return true;
    while(d != n-1){
        x = (x*x)%n;
        d *= 2;
        if(x == 1)
            return false;
        else if(x == n-1)
            return true;
    }
    return false;
}
bool prime(ll n){
    ll d = n-1;
    while(d%2 == 0){
        d/=2;
    }
    for(int i = 0; i < 1; i++){
        if(test(d, n) == false){
            return false;
        }
    }
    return true;
}
int main(){
    ll N; scanf("%lld",&N);
    if(N == 1 || N == 4){
        printf("%lld\n", N+1);
        return 0;
    }else if(N < 4){
        printf("%lld\n",N);
        return 0;
    }
    while(!prime(N))
        N++;
    printf("%lld\n",N);
    return 0;
}