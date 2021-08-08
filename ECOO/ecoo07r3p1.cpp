#include <bits/stdc++.h>
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 1e7+2;

bool np[MM];
int tc = 5, n;
vector<int> primes;
int main(){
    
    for(int i = 2; i < MM; i++){
        if(np[i])
            continue;
        primes.push_back(i);
        for(int j = i*2; j < MM; j += i)
            np[j] = 1;
    }
    while(tc--){
        scan(n);
        
        if(!np[n]){
            printf("%d = %d\n", n, n);
        }
        else if(n&1){
            int a, b, c;
            for(int i = upper_bound(primes.begin(), primes.end(), n/3)-primes.begin()-1; i >= 0; i--){
                c = primes[i];
                int rem = n-c;
                for(int j = upper_bound(primes.begin(), primes.end(), rem/2)-primes.begin()-1; j >= 0; j--){
                    b = primes[j];
                    if(!np[rem-b]){
                        a = rem-b;
                        break;
                    }
                }
                if(c <= b)
                    break;
            }
            int arr[] = {a,b,c};
            sort(arr, arr+3);
            printf("%d = %d + %d + %d\n", n, arr[0], arr[1], arr[2]);
        }
        else{
            int a, b;
            for(int i = upper_bound(primes.begin(), primes.end(), n/2)-primes.begin()-1; i >= 0; i--){
                b = primes[i];
                a = n-b;
                if(!np[a])
                    break;
            }
            printf("%d = %d + %d\n", n, b, a);
        }
    }
    return 0;
}