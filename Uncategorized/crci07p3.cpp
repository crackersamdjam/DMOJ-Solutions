#include <bits/stdc++.h>
#define MM 101
using namespace std;
typedef long long ll;
int N, M;
struct{
    int x,y,sm,pm,sv,pv;
}a[MM];
int da,db;
inline bool go(int m){
    int sum = 0;
    for(int i = 0; i < N; i++){
        int best = INT_MAX;
        for(int j = 0; (max(0,j-1))*a[i].pv <= M; j++){
            ll dif = (ll)a[i].x*m - a[i].y - (ll)j*a[i].sv;
            int add = max(0, (int)ceil((double)dif/a[i].sm));
            if((int)ceil((double)dif/a[i].sm) < best){
                da = add, db = j;
            }
            best = min(best, add*a[i].pm + j*a[i].pv);
        }
        //if(m == 44282)
          //  printf("%d*%d %d*%d %d\n",da,a[i].pm,db,a[i].pv,best+a[i].y);
        sum += best;
    }
    return (sum <= M);
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; i++)
        scanf("%d%d%d%d%d%d",&a[i].x,&a[i].y,&a[i].sm,&a[i].pm,&a[i].sv,&a[i].pv);
    int l = 0, m, r = 100000;
    while(l <= r){
        m = (l+r)/2;
        if(go(m))
            l = m+1;
        else
            r = m-1;
    }
    printf("%d\n",r);
    return 0;
}