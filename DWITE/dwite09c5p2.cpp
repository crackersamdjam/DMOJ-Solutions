#include <bits/stdc++.h>
using namespace std;
#define MM 28
int main() {
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107};
    for(int i = 0,n; i < 5; i++){
        scanf("%d",&n);
        int index;
        bool exact;
        for(int j = 0; j < MM; j++){
            if(primes[j] == n){
                exact = true;
                index = j;
                break;
            }else if(primes[j] > n){
                exact = false;
                index = j;
                break;
            }
        }
        if(exact){
            int low = primes[index-2], high = primes[index+2];
            //printf("%d %d %d\n",n,low,high);
            if(n - low < high - n) printf("%d\n", low);
            else printf("%d\n",high);
        }else{
            int low = primes[index-2], high = primes[index+1];
            //printf("%d %d %d\n",n,low,high);
            if(n - low < high - n) printf("%d\n", low);
            else printf("%d\n",high);
        }
    }
    return 0;
}