#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main(){
    
    scanf("%d", &n);
    
    while(n > 1){
        int a = n-1;
        while(n%a) a--;
        //largest possible a
        int b = n/a;
        ans += b-1;
        n -= a;
    }
    
    printf("%d\n", ans);
    
    return 0;
}
/*
 * highest a, lowest b --> greedy
 *
 * n = 15
 * a = 5, b = 3
 * n --> 10     cost += (3-1) = 2
 * a = 5, b = 2
 * n --> 5      cost += (2-1) = 1
 * a = 1, b = 5
 * n --> 4      cost += (5-1) = 4
 * a = 2, b = 2
 * n --> 2      cost += (2-1) = 1
 * a = 1, b = 2
 * n --> a      cost += (2-1) = 1
 *
 * total cost of 9
 */