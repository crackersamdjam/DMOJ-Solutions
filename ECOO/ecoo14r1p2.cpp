#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;

int tc = 10;
string a, b;
vector<int> thing;

bool flip(int st){
    string cur = "";
    for(int i = st; i+7 < a.size(); i += 8){
        int num = ((thing[i]^1) << 7) + ((thing[i+1]^1) << 6) + ((thing[i+2]^1) << 5) + ((thing[i+3]^1) << 4)
                  + ((thing[i+4]^1) << 3) + ((thing[i+5]^1) << 2) + ((thing[i+6]^1) << 1) + (thing[i+7]^1);
        
        if(num != ' ' and (num < 'A' or num > 'Z'))
            return 0;
        
        cur += (char)num;
    }
    cout << cur << '\n';
    return 1;
}

bool valid(int st){
    
    if(flip(st))
        return 1;
    
    string cur = "";
    for(int i = st; i+7 < a.size(); i += 8){
        int num = (thing[i] << 7) + (thing[i+1] << 6) + (thing[i+2] << 5) + (thing[i+3] << 4)
        + (thing[i+4] << 3) + (thing[i+5] << 2) + (thing[i+6] << 1) + thing[i+7];
        
        //print(num);
        
        if(num != ' ' and (num < 'A' or num > 'Z'))
            return 0;
        
        cur += (char)num;
    }
    cout << cur << '\n';
    return 1;
}

int main(){
    
    while(tc--){
        cin >> a >> b;
        thing.clear();
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] == 'A' || a[i] == 'T')
                thing.push_back(1);
            else
                thing.push_back(0);
        }
        
        for(int st = 0; st < 8; st++){
            if(valid(st))
                break;
        }
    }
    
    return 0;
}