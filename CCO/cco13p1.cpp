#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int X;
    scanf("%d", &X);
    
    int sq = sqrt(X);
    
    for(int base = 2; base <= sq; base++){
        vector<int> vec;
        int n = X;
        while(n){
            //can not store > base_10
            vec.push_back(n%base);
            n /= base;
        }
        bool flag = 1;
        int sz = vec.size();
        for(int i = 0; i < sz/2; i++){
            if(vec[i] != vec[sz-1-i]){
                flag = 0;
                break;
            }
        }
        if(flag)
            printf("%d\n", base);
    }
    
    for(int a = sq; a; a--){
        if(X%a == 0 && X/a-1 > max(1, sq))
            printf("%d\n", X/a-1);
    }
    //a is both digits
    
    return 0;
}
/*
 * 1 <= a <= 9
 * x = a*b + a
 * x = a*(b+1)
 * b = x/a - 1
 */