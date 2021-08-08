#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1005;

int n, h, a, b;
char c[MM]; int v[MM];
char c2[MM]; int v2[MM];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>h;
    a = b = h;
    for(int i = 1; i <= n; i++){
        cin>>c[i]>>v[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>c2[i]>>v2[i];
    }
    for(int i = 1; i <= n; i++){
        //cout<<a<<' '<<b<<' '<<c[i]<<' '<<v[i]<<' '<<c2[i]<<' '<<v2[i]<<'\n';
        
        //process first move
        if(c[i] == 'A'){
            if(c2[i-1] != 'D'){
                b -= v[i];
                if(b <= 0) return cout<<"VICTORY\n", 0;
            }
            else{
                //nothing
            }
        }
        else{
            //c[i] == 'D'
            if(c2[i-1] == 'D'){
                b -= v2[i-1];
                if(b <= 0) return cout<<"VICTORY\n", 0;
            }
        }
        
        //process second move
        if(c2[i] == 'A'){
            if(c[i] != 'D'){
                a -= v2[i];
                if(a <= 0) return cout<<"DEFEAT\n", 0;
            }
        }
        else{
            //c2[i] == 'D'
            if(c[i] == 'D'){
                a -= v[i];
                if(a <= 0) return cout<<"DEFEAT\n", 0;
            }
        }
    }
    
    //last move
    if(c2[n] == 'D'){
        b -= v2[n];
        if(b <= 0) return cout<<"VICTORY\n", 0;
    }
    
    puts("TIE");
    return 0;
}