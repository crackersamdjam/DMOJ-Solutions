#include <bits/stdc++.h>
using namespace std;



int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if((a < -40) + (b >= 15) + (c > 50) > 1)
        puts("YES");
    else
        puts("NO");
    
    return 0;
}