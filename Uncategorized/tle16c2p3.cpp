#include <bits/stdc++.h>
#define MM 1000002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
bool np[MM];
//not prime
int N,C;
unordered_set<int> factors;
inline void go(int c){
    //prime factor c and push into factors
    if(!np[c])
        factors.insert(c);
    for(int i = 2; i*i <= c; i++){
        if(c % i != 0)
            continue;
        int j = c/i;
        if(!np[i])
            factors.insert(i);
        if(j != i){
            if(!np[j])
                factors.insert(j);
        }
    }
}
inline bool find(int n){
    if(!np[n])
        return (factors.find(n) != factors.end());
    for(int i = 2; i*i <= n; i++){
        if(n % i != 0)
            continue;
        int j = n/i;
        if(!np[i]){
            if(factors.find(i) == factors.end()){
                return 0;
            }
        }
        if(j != i){
            if(!np[j]){
                if(factors.find(j) == factors.end()){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main(){
    for(int i = 2; i < MM; i++){
        if(np[i])
            continue;
        for(int j = i*2; j < MM; j+=i)
            np[j] = 1;
    }
    sc(N); sc(C);
    for(int i = 0,c; i < C; i++){
        sc(c);
        go(c);
    }
    bool can = 1;
    for(int i = 0,n; i < N; i++){
        sc(n);
        if(!find(n)){
            can = 0;
            break;
        }
    }
    putchar_unlocked(can? 'Y': 'N');
    return 0;
}