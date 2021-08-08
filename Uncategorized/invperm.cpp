#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+2;

int n, k, b, temp;
vector<int> a;
bool vis[MM];

int main(){
    
    scan(n, k);
    
    assert(k < n);
    
    for(int i = 0; i <= n; i++)
        a.push_back(i);
    
    int flip = n/2;
    for(int i = 1; i <= flip; i++){
        if(k == 0)
            goto done;
        k--;
        
        swap(a[i], a[n-i+1]);
    }
    
    if(k == 0)
        goto done;
    
    b = n-k;
    temp = a[b];
    a.erase(a.begin()+b);
    a.push_back(temp);
    
    done:;
    for(int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    
    return 0;
}
/*
 * k < n guaranteed
 * first swap front and back (n/2 times)
 * then make cycle of length of k-n/2+1 starting from back
 * let the index be b = n-(k-n/2)
 * send b to back
 */
/*
swaps 0
1 2 3 4 5
swaps 1
5 2 3 4 1
swaps 2
5 4 3 2 1
swaps 3
5 4 3 1 2
swaps 4
5 4 2 1 3
 */