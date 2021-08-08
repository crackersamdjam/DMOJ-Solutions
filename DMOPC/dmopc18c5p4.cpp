//fuck the cheese
#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+1;

int N, a[MM], b[MM];
char stra[MM], strb[MM];

int main(){
    
    scanf("%d %s %s", &N, stra, strb);
    
    if(strcmp(stra, strb) == 0){
        puts("YES");
        return 0;
    }
    
    for(int i = 0; i < N; i++){
        if(stra[i] != stra[i-1])
            break;
        if(i == N-1){
            puts("NO");
            break;
        }
    }
    
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        cnt ^= (stra[i] == 'F')^(strb[i] == 'F');
    }
    
    puts(cnt? "NO": "YES");
    
    return 0;
}