#include <bits/stdc++.h>
using namespace std;

int n, a[10], b[10];

inline double test(double i, double j){
    double far = 0;
    for(int k = 0; k < n; k++)
        far = max(far, sqrt((a[k]-i)*(a[k]-i) + (b[k]-j)*(b[k]-j)));
    
    return far;
}

inline double testy(double x){
    double ret = 1e9, l = 0, m, r = 1e6;
    while(r - l >= 1e-3){
        m = (l+r)/2;
        
        double res = test(x, m);
        
        if(res < ret)
            ret = res;
        
        if(test(x, m - 1e-3) < res)
            r = m - 1e-3;
        else
            l = m + 1e-3;
    }
    return ret;
}

int main(){
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    double x = 0, best = 1e9, l = 0, m, r = 1e6;
    while(r - l >= 1e-3){
        m = (l+r)/2;
        
        double res = testy(m);
        
        if(res < best)
            best = res;
        
        if(testy(m - 1e-3) < res)
            r = m - 1e-3;
        else
            l = m + 1e-3;
    }
    
    printf("%.2lf\n", 2*best);
    
    return 0;
}