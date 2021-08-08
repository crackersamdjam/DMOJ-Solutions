#include <bits/stdc++.h>
using namespace std;
const int MM = 500, MN = 25001;

int N, a[MM], dp[MM][MN];

int main(){
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        scanf("%d", a+i);
    
    sort(a, a+N, greater<>());
    dp[1][0] = 1;
    //always bounded by first piller
    
    for(int i = 2; i < N; i++){
        for(int j = 1; j < i; j++){
            
            if(j != 1 && a[j] == a[j-1])
                continue;
            //same dif
            
            int dif = a[j] - a[i];
            //water collected (bounded by large pillar
            for(int k = 0; k + dif < MN; k++){
                if(dp[i-1][k]){
                    dp[i][k] = 1;
                    //propagate (add left of fst pillar)
                    dp[i][k+dif] = 1;
                    //add another possibility
                }
            }
        }
    }
    
    for(int i = 0; i < MN; i++){
        if(dp[N-1][i])
            printf("%d ", i);
    }
    
    return 0;
}
/*
 * only 50 possible heights
 *
 */