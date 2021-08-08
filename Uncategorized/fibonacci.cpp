#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define max 1000000007;
void mul(ll m[2][2], ll fib[2][2]){
    ll temp[2][2];
    /*for(int i = 0; i <= 1; i++)
        for(int j = 0; j <= 1; j++)
            for(int k = 0; k <= 1; k++)
                temp[i][j] = (temp[i][j] + m[i][k] * fib[k][j]) % max;
    */
    temp[0][0] =  (m[0][0] * fib[0][0] + m[0][1] * fib[1][0]) % max;
    temp[0][1] =  (m[0][0] * fib[0][1] + m[0][1] * fib[1][1]) % max;
    temp[1][0] =  (m[1][0] * fib[0][0] + m[1][1] * fib[1][0]) % max;
    temp[1][1] =  (m[1][0] * fib[0][1] + m[1][1] * fib[1][1]) % max;
    m[0][0] = temp[0][0];
    m[0][1] = temp[0][1];
    m[1][0] = temp[1][0];
    m[1][1] = temp[1][1];
    return;
}
void pow(ll m[2][2], ll n){
    if(n == 1 || n == 0) return;
    ll fib[2][2] = {{1,1},{1,0}};
    pow(m, n/2);
    mul(m, m);
    if(n % 2){
        mul(m, fib);
    }
    return;
}
int main() {
    ll n;
    scanf("%llu", &n);
    ll m[2][2] = {{1,1},{1,0}};
    pow(m, n-1);
    printf("%llu\n", m[0][0]);
    return 0;
}