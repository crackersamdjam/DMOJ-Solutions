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

string s[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G" ,"G#", "A", "A#", "B"};

int val(string ss){
    for(int i = 0; i < 30; i++){
        if(s[i] == ss)
            return i;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string a[5];
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        a[4] = a[0];
        
        int aa = 0, bb = 0, rot = 0;
        for(int i = 0; i < 4; i++){
            int va = val(a[i]), vb = val(a[i+1])+12;
            int d = (vb-va)%12;
            
            if(d == 3)
                aa++;
            else if(d == 4){
                rot = i;
                bb++;
            }
        }
        
        if(aa < 2 or bb < 1){
            puts("invalid");
        }
        else{
            
            if(rot == 0)
                puts("root");
            if(rot == 3)
                puts("first");
            if(rot == 2)
                puts("second");
            if(rot == 1)
                puts("third");
        }
    }
    
    return 0;
}