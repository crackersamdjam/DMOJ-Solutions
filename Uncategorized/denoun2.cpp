#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;



int main(){
    
    int N;
    cin >> N;
    string str;
    getline(cin, str);
    
    while(N--){
        getline(cin, str);
        stringstream ss(str);
        while(ss){
            string s;
            ss >> s;
            if(s.back() == '.' or s.back() == '!' or s.back() == '?' or s.back() == ',')
                s.pop_back();
            
            if((s[0] >= 'A' and s[0] <= 'Z') or (s.substr(0,2) == "Ä") or (s.substr(0,2) == "Ö") or (s.substr(0,2) == "Ü"))
                cout << s << '\n';
        }
    }
    
    return 0;
}