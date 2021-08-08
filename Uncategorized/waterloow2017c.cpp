#include <bits/stdc++.h>
using namespace std;
const int MM = 101;

int N, K, a[MM], num;

int main(){
    
    scanf("%d%d", &N, &K);
    
    //1 to 1+K, 1+K to 1+2*K
    if(K*2+1 <= N){
        puts("0");
        return 0;
    }
    
    for(int i = 1; i <= K; i++){
        if(i+K <= N)
            a[i+K] = ++num;
        a[i] = ++num;
    }
    
    for(int i = 1; i <= N; i++)
        printf("%d ", a[i]);
    
    return 0;
}
/*
 * K >= N/2
 * otherwise
 * a[0] > a[k], a[k] > a[2k], a[0] < a[2k]
 * not possible
 *
6 3
2 4 6 1 3 5

7 3
2 4 6 1 3 5 7

7 5
 
 */