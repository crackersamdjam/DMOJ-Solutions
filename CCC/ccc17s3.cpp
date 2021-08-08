#include <bits/stdc++.h>
using namespace std;

int N, a[2001], b[4001];

int main(){
    
    scanf("%d", &N);
    
    for(int i = 0,n; i < N; i++){
        scanf("%d", &n);
        a[n]++;
    }
    
    for(int i = 1; i < 2001; i++){
        for(int j = 1; j < 2001; j++){
            if(i == j)
                b[i+i] += a[i];
            else
                b[i+j] += min(a[i], a[j]);
        }
    }
    
    int ans = 0, cnt = 0;
    for(int i = 1; i < 4001; i++){
        if(b[i] > ans){
            ans = b[i];
            cnt = 1;
        }
        else if(b[i] == ans)
            cnt++;
    }
    
    printf("%d %d\n", ans/2, cnt);
    
    return 0;
}