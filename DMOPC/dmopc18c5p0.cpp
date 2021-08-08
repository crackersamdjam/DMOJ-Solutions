#include <bits/stdc++.h>
using namespace std;



int main(){
    
    string str;
    
    cin >> str;
    
    double a, b, c, aa, bb, cc;
    cin >> a >> b >> c >> aa >> bb >> cc;
    
    if(str == "Multiply"){
        printf("%.6lf %.6lf %.6lf\n", a*aa, b*bb, c*cc);
    }
    else if(str == "Screen"){
        printf("%.6lf %.6lf %.6lf\n", 1-(1-a)*(1-aa), 1-(1-b)*(1-bb), 1-(1-c)*(1-cc));
    }
    else{
        printf("%.6lf ", a < 0.5? 2*a*aa: 1-2*(1-a)*(1-aa));
        printf("%.6lf ", b < 0.5? 2*b*bb: 1-2*(1-b)*(1-bb));
        printf("%.6lf ", c < 0.5? 2*c*cc: 1-2*(1-c)*(1-cc));
    }
    
    return 0;
}