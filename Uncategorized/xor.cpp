#include <bits/stdc++.h>
using namespace std;
int XOR(int n){
    switch(n&3){
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
}
int main() {
    int t; scanf("%d",&t);
    for(int i = 0,s,f; i < t; i++){
        scanf("%d%d",&s,&f);
        printf("%d\n",XOR(s-1)^XOR(f));
    }
    return 0;
}