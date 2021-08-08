#include <bits/stdc++.h>
using namespace std;

int N, a[4], ans;

void go(int i, int val){
    if(i == 4){
        if(val <= 24)
            ans = max(ans, val);
        return;
    }
    go(i+1, val+a[i]);
    go(i+1, val-a[i]);
    go(i+1, val*a[i]);
    if(val % a[i] == 0)
        go(i+1, val/a[i]);
}

//also try multiplying first two with last two

void again(){
    int v[] = {a[0]+a[1], a[0]-a[1], a[0]*a[1], a[0]/a[1]};
    int w[] = {a[2]+a[3], a[2]-a[3], a[2]*a[3], a[2]/a[3]};
    for(int i = 0; i < 3 + (a[0] % a[1] == 0); i++){
        for(int j = 0; j < 3 + (a[2] % a[3] == 0); j++){
            if(v[i] * w[j] <= 24){
                ans = max(ans, v[i] * w[j]);
            }
            /*
            if(v[i] % w[j] == 0 && v[i] / w[j] <= 24){
                ans = max(ans, v[i] / w[j]);
            }
             */
            if(v[i] + w[j] <= 24){
                ans = max(ans, v[i] + w[j]);
            }
            if(v[i] - w[j] <= 24){
                ans = max(ans, v[i] - w[j]);
            }
        }
    }
}

int main(){
    
    scanf("%d", &N);
    
    while(N--){
        
        ans = 0;
        
        for(int i = 0; i < 4; i++)
            scanf("%d", a+i);
        
        sort(a, a+4);
        
        do{
            go(1, a[0]);
            again();
        }
        while(next_permutation(a, a+4));
        
        printf("%d\n", ans);
    }
    
    return 0;
}