#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
deque<char> q;
int main(){
    char c;
    while(1){
        c = getchar_unlocked();
        if(c == '\n')
            break;
        if(!q.empty() && q.back() == '(' && c == ')')
            q.pop_back();
        else
            q.push_back(c);
    }
    while(q.size() > 1 && q.front() == '(' && q.back() == ')'){
        q.pop_front();
        q.pop_back();
    }
    if(q.size() == 0 || q.size() == 2)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}