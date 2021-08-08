#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename T> void printmn(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}
template<typename First, typename ... Ints>
void printm(First arg, Ints... rest) {printmn(arg);pc(32);printmn(rest...);pc(10);}

using namespace std;

int N, ans;

struct point{
    double x, y;
} arr[35];

struct line{
    double a, b, c, d;
} l;

bool intersect(line a, line b){
    double ma = (a.c == a.a)?1e5:((a.d-a.b)/(a.c-a.a));
    double mb = (b.c == b.a)?1e5:((b.d-b.b)/(b.c-b.a));
    double ba = -ma*a.a + a.b;
    double bb = -mb*b.a + b.b;
    //cout << "ma " << ma << " mb " << mb << "\n";
    if(abs(ma - mb) < 0.001){
        //same slope
        if(abs(ba - bb) < 0.001){
            //same x-int
            return ((b.c - a.a >= -0.001) && (a.c - b.a >= -0.001));
        }
        return 0;
    }
    double x = (bb - ba)/(ma - mb);
    double y = ma*x + ba;
    
    //test whether x is in range of each line
    //test y as well
    
    if((x - a.a >= -0.001) && (a.c - x >= -0.001) && (y - a.b >= -0.001) && (a.d-y >= -0.001)){
        if((x - b.a >= -0.001) && (b.c - x >= -0.001) && (y - b.b >= -0.001) && (b.d-y >= -0.001)){
            return 1;
        }
    }
    
    return 0;
}

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> l.a >> l.b >> l.c >> l.d;
    if(l.a > l.c)
        swap(l.a, l.c);
    if(l.b > l.d)
        swap(l.b, l.d);
    
    cin >> N;
    
    for(int i = 0,n; i < N; i++){
        cin >> n;
        for(int j = 0; j < n; j++)
            cin >> arr[j].x >> arr[j].y;
        
        arr[n] = arr[0];
        
        for(int j = 0; j < n; j++){
            line ln = {arr[j].x, arr[j].y, arr[j+1].x, arr[j+1].y};
            
            if(ln.a > ln.c)
                swap(ln.a, ln.c);
            
            if(ln.b > ln.d)
                swap(ln.b, ln.d);
            
            if(intersect(l, ln)){
                ans++;
                break;
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}