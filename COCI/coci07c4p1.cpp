#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int p,m,g;
    scanf("%d%d%d",&p,&m,&g);
    int ans = 0;
    int sum = a+b, newp = p;
    //while(newp - sum > 0) newp-=sum;
    newp = p%sum;
    if(newp != 0 &&newp <= a) ans++;
    int sum2 = c+d;
    //while(p - sum2 > 0) p-=sum2;
    p = p%sum2;
    if(p != 0 &&p <= c) ans++;
    switch(ans){
        case 0: printf("none\n");
        break;
        case 1: printf("one\n");
        break;
        case 2: printf("both\n");
    }
    ans = 0;
    sum = a+b;
    int newm = m;
    newm = m%sum;
    if(newm != 0 &&newm <= a) ans++;
    sum2 = c+d;
    m = m%sum2;
    if(m != 0 &&m <= c) ans++;
    switch(ans){
        case 0: printf("none\n");
            break;
        case 1: printf("one\n");
            break;
        case 2: printf("both\n");
    }
    ans = 0;
    sum = a+b;
    int newg = g;
    newg = g%sum;
    if(newg != 0 && newg <= a) ans++;
    sum2 = c+d;
    g = g%sum2;
    if(g!=0&&g <= c) ans++;
    switch(ans){
        case 0: printf("none\n");
            break;
        case 1: printf("one\n");
            break;
        case 2: printf("both\n");
    }
    return 0;
}
/*
2 2 3 3
3 3 3
 */