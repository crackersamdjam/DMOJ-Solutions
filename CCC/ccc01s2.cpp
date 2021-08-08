#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

map<int, deque<int>> mp;

int main(){
    
    int a, b, v = 1;
    scan(a, b);
    
    mp[0].push_back(a++);
    
    int r = 0, n = 1;
    
    while(a <= b){
        for(int j = 0; j < n; j++){
            if(v == -1){
                r--;
                mp[r].push_back(a++);
            }
            else{
                r++;
                mp[r].push_front(a++);
            }
            if(a > b)
                break;
        }
        if(a > b)
            break;
        if(v == -1){
            for(int j = 0; j < n; j++){
                mp[r].push_front(a++);
                if(a > b)
                    break;
            }
        }
        else{
            for(int j = 0; j < n; j++){
                mp[r].push_back(a++);
                if(a > b)
                    break;
            }
        }
        v *= -1;
        n++;
    }
    int sm = 0;
    for(auto i: mp)
        sm = max(sm, (int)i.second.size());
    
    for(auto i: mp){
        if(i.second.empty())
            continue;
        int dif = sm - i.second.size();
        while(dif--)
            printf("  ");
        for(auto j: i.second)
            printf("%d ", j);
        pc(10);
    }
    
    return 0;
}