#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

string a[] = {"o.","o.","oo","oo","o.","oo","oo","o.",".o",".o","o.","o.","oo","oo","o.","oo","oo","o.",".o",".o","o.","o.",".o","oo","oo","o.",".."};
string b[] = {"..","o.","..",".o",".o","o.","oo","oo","o.","oo","..","o.","..",".o",".o","o.","oo","oo","o.","oo","..","o.","oo","..",".o",".o",".."};
string c[27];

int main(){
    
    for(int i = 0; i < 10; i++)
        c[i] = "..";
    for(int i = 10; i < 20; i++)
        c[i] = "o.";
    for(int i = 20; i < 26; i++)
        c[i] = "oo";
    c['W'-'A'] = ".o";
    c[26] = "..";
    
    string str, d[3];
    getline(cin, str);
    
    for(char i: str){
        if(i == ' ')
            i = 'Z'+1;
        i -= 'A';
        d[0] += a[i];
        d[1] += b[i];
        d[2] += c[i];
    }
    
    for(int i = 0; i < 3; i++)
        cout << d[i] << '\n';
    
    return 0;
}