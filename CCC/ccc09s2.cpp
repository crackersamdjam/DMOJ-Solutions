#include <bits/stdc++.h>
using namespace std;
int r,l,a[31],m;
unordered_set<int> mask;
int main(){
    scanf("%d%d",&r,&l);
    for(int i = 1; i <= r; i++){
        for(int j = 0,c; j < l; j++){
            scanf("%d",&c);
            a[i] |= c<<j;
        }
    }
    for(int st = 1; st <= r; st++){
        m = a[st];
        for(int i = st+1; i <= r; i++){
            m ^= a[i];
        }
        mask.insert(m);
    }
    printf("%d\n", mask.size());
    return 0;
}
/*
 xor does not matter which order
 pushing a button pushes result down to new row, otherwise, use only new row
 loop through starting positions [r, 1)
 xor all the way down (back to 1), push into set
 */