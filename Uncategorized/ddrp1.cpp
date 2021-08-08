#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    if(m==n) printf("Switch\n");
    else if(m==p) printf("Switch\n");
    else printf("Stay\n");
    return 0;
}