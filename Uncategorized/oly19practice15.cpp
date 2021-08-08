#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;



int main(){
    
    string str;
    getline(cin, str);
    
    int last = 1;
    
    int n = str.size();
    
    for(int i = 0; i < n; i++){
        if(str[i] == ' ')
            continue;
        if(str[i] == '.'){
            last = 1;
            continue;
        }
        if(!last){
            if(str[i] >= 'A' and str[i] <= 'Z')
                str[i] = str[i] + 'a' - 'A';
        }
        last = 0;
        
        if(str[i] == 'i' and i > 0 and str[i-1] == ' ' and (str[i+1] == ' ' or str[i+1] == '.'))
            str[i] = 'I';
    }
    
    cout << str;
    
    return 0;
}