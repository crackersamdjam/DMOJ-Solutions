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

vector<int> va, vb;
string a, b;

int main(){
    cin>>a>>b;
    for(auto c: a){
        if(c == '1')
            va.emplace_back(0);
        if(c == '2')
            va.emplace_back(1);
        if(c == 'U'){
            int rm = va.back(); va.pop_back();
            va.back() += floor(rm/2.0);
        }
        if(c == 'L')
            va.back()--;
        if(c == 'R')
            va.back()++;
    }
    for(int i = va.size()-1; i > 0; i--){
        int mv = floor(va[i]/2.0);
        va[i] -= mv*2;
        va[i-1] += mv;
    }
    assert(va[0] == 0 or va[0] == 1);
//    for(int i = 0; i < va.size(); i++)
//        printf("%d ", va[i]);
//    pc(10);
    
    swap(a, b);
    swap(va, vb);
    for(auto c: a){
        if(c == '1')
            va.emplace_back(0);
        if(c == '2')
            va.emplace_back(1);
        if(c == 'U'){
            int rm = va.back(); va.pop_back();
            va.back() += floor(rm/2.0);
        }
        if(c == 'L')
            va.back()--;
        if(c == 'R')
            va.back()++;
    }
    for(int i = va.size()-1; i > 0; i--){
        int mv = floor(va[i]/2.0);
        va[i] -= mv*2;
        va[i-1] += mv;
    }
    assert(va[0] == 0 or va[0] == 1);
//    for(int i = 0; i < va.size(); i++)
//        printf("%d ", va[i]);
//    pc(10);
    
    int sum = 0, dif = 0, best = va.size()+vb.size();
    
    if(va.size() < vb.size())
        swap(va, vb);
    
    while(va.size() > vb.size())
        va.pop_back(), sum++;
    
    if(va > vb)
        swap(va, vb);
    
    for(int i = 0; i < va.size() and dif < 3e5; i++){
        dif = dif*2 + vb[i]-va[i];
        best = min(best, dif+sum + (int)(va.size()-1-i)*2);
    }
    
    print(best);
    
    
    return 0;
}