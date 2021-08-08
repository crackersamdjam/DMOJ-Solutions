#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

int a[10][20], cnt, n, k;

bool go(int f, int s){
    for(int i = 0; i < k; i++){
        if(a[i][f] >= a[i][s])
            return 0;
    }
    return 1;
}

int main(){
    init();
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        for(int j = 0,v; j < n; j++){
            cin >> v;
            a[i][v-1] = j;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cnt += go(i, j);
        }
    }
    
    printf("%d\n", cnt);
    
    return 0;
}