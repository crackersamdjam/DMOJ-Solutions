#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 1001
bool row[MM],col[MM];
int r,c,q,x,y;
int main() {
    scan(r); scan(c);
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(getchar() == 'X'){
                row[i] = true;
                col[j] = true;
            }
        }
        getchar();
    }
    scan(q);
    while(q--){
        scan(x); scan(y);
        printf(row[y] || col[x] ? "Y\n": "N\n");
    }
    return 0;
}