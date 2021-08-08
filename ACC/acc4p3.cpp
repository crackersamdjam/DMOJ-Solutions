#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
using namespace std;

bool f(int n){
    
    int sq = sqrt(n);
    
    return sq*sq == n; 
    
    /*
    for(int i = 1; i*i < n; i++){
        int rem = n-i*i;
        int sq = sqrt(rem);
        if(sq*sq == rem)
            return 1;
    }
    return 0;
     */
}