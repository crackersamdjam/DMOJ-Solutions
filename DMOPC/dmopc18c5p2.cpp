#include <bits/stdc++.h>
using namespace std;

vector<double> image;
double sum = 0, eps = 1e-8;

int main(){
    
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            double d;
            cin >> d;
            image.push_back(d);
            sum += d;
        }
    }
    
    sum /= 1.0*N*M;
    
    if(abs(sum-0.48) < 1e-5){
        puts("correctly exposed");
        return 0;
    }
    else if(sum > 0.48){
        puts("overexposed");
    }
    else{
        puts("underexposed");
    }
    
    double l = 0,m=-1, r = 10000;
    while(r - l >= eps){
        m = (l+r)/2;
        sum = 0;
        for(double d: image){
            sum += min(1.0, m*d);
        }
        sum /= 1.0*N*M;
        
        //printf("%lf %lf\n", m, sum);
        if(abs(sum-0.48) <= eps){
            printf("%.6lf\n", m);
            return 0;
        }
        else if(sum > 0.48)
            r = m - eps;
        else
            l = m + eps;
    }
    
    printf("%.6lf\n", m);
    
    return 0;
}