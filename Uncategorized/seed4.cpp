#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll, ll>, pair<ll, int>> st;
const int MM = 1e5;

int N, ans;
ll xk, yk, zk;
st a[MM];

inline ll clang(ll a, ll b){
    return a? clang(b%a, a): b;
}

int main(){
    
    scanf("%lld%lld%lld", &xk, &yk, &zk);
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        ll x, y, z, gcd;
        scanf("%lld%lld%lld", &x, &y, &z);
        x -= xk, y -= yk, z -= zk;
        gcd = clang(clang(x, y), z);
        int dir = 4*(x >= 0) + 2*(y >= 0) + (z >= 0);
        a[i] = {{x/gcd, y/gcd}, {z/gcd, dir}};
    }
    
    sort(a, a+N);
    
    for(int i = 1; i < N; i++){
        if(a[i] != a[i-1])
            ans++;
    }
    
    printf("%d\n", ans+1);
    
    return 0;
}