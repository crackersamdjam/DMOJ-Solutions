#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n;
vector<int> vec;
vector<set<int>> ans;

int main(){
    
    scan(n);
    
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            vec.push_back(i);
            if(n/i != i)
                vec.push_back(n/i);
        }
    }
    
    sort(vec.begin(), vec.end());
    ans.resize(vec.size());
    
    for(int i = 0; i < vec.size(); i++){
        ans[i].insert(vec[i]-1);
        int v = vec[i];
        
        for(int j = 2; j*j <= v; j++){
            
            if(v%j == 0){
                auto ptr = lower_bound(vec.begin(), vec.end(), j);
                if(*ptr == j){
                    for(int x: ans[ptr-vec.begin()])
                        ans[i].insert(x + v/j - 1);
                }
                int k = v/j;
                if(k != j){
                    ptr = lower_bound(vec.begin(), vec.end(), k);
                    if(*ptr == k){
                        for(int x: ans[ptr-vec.begin()])
                            ans[i].insert(x + v/k - 1);
                    }
                }
            }
        }
    }
    
    print(ans.back().size());
    
    for(int i: ans.back())
        printn(i), pc(32);
    
    return 0;
}