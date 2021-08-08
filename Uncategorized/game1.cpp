#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, a[1001], v;

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        v ^= a[i];
    }
    if(!v){
        cout<<"1 0"<<endl;
        int i, j;
        cin>>i>>j;
        v ^= a[i];
        a[i] -= j;
        v ^= a[i];
        
        if(i*j == 0)
            return 0;
    }
    
    while(1){
        for(int i = 1; i <= n; i++){
            int nx = a[i]^v;
            if(a[i] and (nx < a[i])){
                cout<<i<<' '<<a[i]-nx<<endl;
                a[i] = nx;
                v = 0;
                break;
            }
        }
        int i, j;
        cin>>i>>j;
        if(i*j == 0)
            return 0;
        
        v ^= a[i];
        a[i] -= j;
        v ^= a[i];
    }
    
    return 0;
}