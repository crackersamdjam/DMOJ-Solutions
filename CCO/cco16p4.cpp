#include <bits/stdc++.h>

using namespace std;

int N, G, ans;
bool a[10][10];
char c[10][10];
map<int, int> mp;

int main(){
    
    scanf("%d%d", &N, &G);
    
    for(int t = 0; t < G; t++){
        for(int i = 0; i < N; i++){
            scanf("%s", c[i]);
            for(int j = 0; j < N; j++){
                a[i][j] = c[i][j] == 'R';
            }
        }
        for(int i = 0; i < N-1; i++){
            for(int j = i; j < N-1; j++){
                if(a[i][j]){
                    a[i][j] ^= 1;
                    a[i][j+1] ^= 1;
                    a[i+1][j] ^= 1;
                    a[i+1][j+1] ^= 1;
                }
                swap(i, j);
                if(a[i][j]){
                    a[i][j] ^= 1;
                    a[i][j+1] ^= 1;
                    a[i+1][j] ^= 1;
                    a[i+1][j+1] ^= 1;
                }
                swap(i, j);
            }
        }
        int mask = a[N-1][N-1];
        for(int i = 0; i < N-1; i++){
            mask = (mask<<2) | (a[i][N-1]<<1) | a[N-1][i];
        }
        ans += mp[mask]++;
    }
    printf("%d\n", ans);
    
    return 0;
}