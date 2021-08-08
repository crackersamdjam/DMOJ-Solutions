#define ONLINE_JUDGE

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
const int MM = 1e5+5;

bool used[MM];
int n, x[MM], y[MM], v[MM], tx, ty;
long long ans;
map<int, int> mx, my;
map<int, pair<int, int>> sx[MM], sy[MM];

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        scan(x[i], y[i], v[i]);
        //swap(x[i], y[i]);
        mx[x[i]] = my[y[i]] = 0;
    }
    
    for(auto &i: mx)
        i.second = ++tx;
    for(auto &i: my)
        i.second = ++ty;
    
    for(int i = 0; i < n; i++){
        printerr("i", i);
        x[i] = mx[x[i]], y[i] = my[y[i]];
    
        sx[y[i]][x[i]] =  {0, v[i]};
        auto ptr = sx[y[i]].upper_bound(x[i]);
        int add = 0, newl = v[i], newr = v[i];
        
        if(ptr != sx[y[i]].end()){
            add = ptr->second.second;
            
            if(++ptr != sx[y[i]].end())
                newr = max(newr, ptr->second.second);
            ptr--;
            
            printerr("addr", newr-ptr->second.first);
            ans += newr-ptr->second.first;
            ptr->second.first = newr;
        }
        ptr--;
        if(ptr != sx[y[i]].begin()){
            ptr--;
            add = max(add, ptr->second.second);
            if(ptr != sx[y[i]].begin()){
                ptr--;
                newl = max(newl, ptr->second.second);
                ptr++;
            }
            printerr("addl", newl-ptr->second.first);
            ans += newl-ptr->second.first;
            ptr->second.first = newl;
        }
        
        sx[y[i]][x[i]] =  {add, v[i]};
        
        printerr("add", add);
        ans += add;
        
    
        sy[x[i]][y[i]] =  {0, v[i]};
        ptr = sy[x[i]].upper_bound(y[i]);
        add = 0, newl = v[i], newr = v[i];
    
        if(ptr != sy[x[i]].end()){
            add = ptr->second.second;
        
            if(++ptr != sy[x[i]].end())
                newr = max(newr, ptr->second.second);
            ptr--;
        
            printerr("addr", newr-ptr->second.first);
            ans += newr-ptr->second.first;
            ptr->second.first = newr;
        }
        ptr--;
        if(ptr != sy[x[i]].begin()){
            ptr--;
            add = max(add, ptr->second.second);
            if(ptr != sy[x[i]].begin()){
                ptr--;
                newl = max(newl, ptr->second.second);
                ptr++;
            }
            printerr("addl", newl-ptr->second.first);
            ans += newl-ptr->second.first;
            ptr->second.first = newl;
        }
    
        sy[x[i]][y[i]] =  {add, v[i]};
    
        printerr("add", add);
        ans += add;
        
        
        print(ans);
    }
    
    
    return 0;
}