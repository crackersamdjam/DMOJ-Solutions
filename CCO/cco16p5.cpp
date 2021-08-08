#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 4002;

map<int,int> cx, cy;
vector<int> rx, ry, inx, iny;
int N, M, K, Q;
unsigned short arr[MM][MM];

inline ll area(int q){
    if(q < 0)
        return 0;
    
    memset(arr,0,sizeof(arr));
    cx.clear(); cy.clear();
    rx.clear(); ry.clear();
    
    for(int i = 0; i < K; i++){
        cx[max(1, inx[i]-q)] = cx[min(inx[i]+q+1, N+1)] = 0;
        cy[max(1, iny[i]-q)] = cy[min(iny[i]+q+1, M+1)] = 0;
    }
    
    int cntx = 1, cnty = 1;
    
    for(auto &it: cx){
        it.second = cntx++;
        rx.push_back(it.first);
    }
    for(auto &it: cy){
        it.second = cnty++;
        ry.push_back(it.first);
    }
    
    for(int i = 0,a,b,c,d; i < K; i++){
        a = cx[max(1, inx[i]-q)], b = cy[max(1, iny[i]-q)];
        c = cx[min(inx[i]+q+1, N+1)], d = cy[min(iny[i]+q+1, M+1)];
        arr[a][b]++;
        arr[c][b]--;
        arr[a][d]--;
        arr[c][d]++;
    }
    ll sum = 0;
    for(int i = 1; i < cntx; i++){
        for(int j = 1; j < cnty; j++){
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            if(arr[i][j] > 0){
                sum += (ll)(rx[i] - rx[i-1])*(ry[j] - ry[j-1]);
            }
        }
    }
    return sum;
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i = 0,a,b; i < K; i++){
        scanf("%d%d",&a,&b);
        inx.push_back(a);
        iny.push_back(b);
    }
    scanf("%d", &Q);
    printf("%lld\n", area(Q) - area(Q-1));
    return 0;
}