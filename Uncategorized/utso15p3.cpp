#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll a[4],b[4],c1[4],c2[4],d[4],f[4],N,M;
int main(){
    scanf("%lld%lld",&N,&M);
    switch(M){
        case 1:
            printf("1\n");
            break;
        case 2:
            if(N <= 0)
                printf("0\n");
            else if(N==1)
                printf("1\n");
            else{
                f[0] = 0, f[1] = 1, f[2] = 1, f[3] = 1;
                for(ll i = 3; i <= N; i++){
                    f[3] = (f[2] + f[0])%mod;
                    for(int j = 0; j < 3; j++)
                        f[j] = f[j+1];
                }
                printf("%lld\n",f[3]);
            }
            break;
        case 3:
            a[3] = d[3] = 1;
            for(ll i = 2; i <= N; i++){
                for(int j = 0; j < 3; j++)
                    a[j] = a[j+1], b[j] = b[j+1], c1[j] = c1[j+1],
                            c2[j] = c2[j+1], d[j] = d[j+1];
                a[3] = (a[2]+b[1]+c1[0])%mod;
                b[3] = (a[1]+c2[0]+d[2]+d[0])%mod;
                c2[3] = (a[2]+a[1]+c2[0]+d[2]+d[0])%mod;
                c1[3] = (a[1]+c2[3])%mod;
                d[3] = (a[3]+b[2])%mod;
            }
            printf("%lld\n",a[3]);
            break;
    }
    return 0;
}