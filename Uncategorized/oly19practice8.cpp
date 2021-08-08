#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 2e5+1;

struct st{
    int l, r;
};

int N, M, rs[MM], a[MM];
deque<st> q;
set<int> nums;

int main(){
    
    scan(N, M);
    
    for(int i = 0,l,r; i < M; i++){
        scan(l, r);
        rs[l] = max(rs[l], r);
    }
    
    for(int i = 1; i <= N; i++){
        if(rs[i])
            q.push_back({i, rs[i]});
    }
    
    int l = 1;
    a[1] = 1;
    
    for(int i = 2; i <= N+5; i++)
        nums.insert(i);
    
    
    for(int i = 2; i <= N; i++){
        
        while(!q.empty() and q.front().r < i)
            q.pop_front();
        
        if(q.empty())
            break;
        
        while(l < q.front().l and l < i){
            nums.insert(a[l++]);
        }
        
        a[i] = *nums.begin();
        nums.erase(nums.begin());
    }
    
    for(int i = 1; i <= N; i++){
        if(!a[i])
            a[i] = 1;
    }
    
    for(int i = 1; i <= N; i++)
        printf("%d ", a[i]);
    
    
    return 0;
}
/*
 * set to check what lowest new num can be
 */