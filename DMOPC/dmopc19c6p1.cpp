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

long double ax, ay, bx, by, cx, cy, dx, dy, eps = 1e-8;


int main(){
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
    cout<<fixed<<setprecision(10);
    
    if(cx == dx){
        swap(ax, cx);
        swap(ay, cy);
        swap(bx, dx);
        swap(by, dy);
    }
    if(ax == bx){
        if(cx == dx){
            if(ax == cx)
                cout<<"coincident\n";
            else
                cout<<"parallel\n";
        }
        else{
            long double m2 = (dy-cy)/(dx-cx), b2 = cy-m2*cx;;
            long double inx = ax, iny = ax*m2 + b2;
            cout<<inx<<' '<<iny<<'\n';
        }
        return 0;
    }
    
    long double m1 = (by - ay)/(bx - ax), m2 = (dy-cy)/(dx-cx);
    long double b1 = ay-m1*ax, b2 = cy-m2*cx;
//    cout<<m1<<' '<<m2<<' '<<b1<<' '<<b2<<'\n';
    if(abs(m1-m2) > eps){
        long double inx = (b2 - b1)/(m1 - m2);
        long double iny = m1*inx + b1;
        cout<<inx<<' '<<iny<<'\n';
    }
    else{
        if(abs(b1-b2) < eps)
            cout<<"coincident\n";
        else
            cout<<"parallel\n";
    }
    
    return 0;
}
/*
0 0 1 1
3 3 4 0
 */