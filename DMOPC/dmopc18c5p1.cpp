#include <bits/stdc++.h>
using namespace std;



int main(){
    
    int N, M, K, ans = 0;
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        ans += ((N&(1<<i))^(M&(1<<i))) > 0;
    }
    
    printf("%d %d\n", ans, K-ans);
    
    return 0;
}