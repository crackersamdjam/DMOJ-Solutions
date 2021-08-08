#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5;

int N;
string a[MM];

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        deque<int> q, qq, minq;
        for(int j = 0,n; j < 6; j++){
            scan(n);
            q.push_back(n);
            qq.push_front(n);
        }
        minq = q;
        for(int j = 6; j--;){
            minq = min(minq, q);
            q.push_back(q.front());
            q.pop_front();
            minq = min(minq, qq);
            qq.push_back(qq.front());
            qq.pop_front();
        }
        //if(a.count(minq))
          //  return 0*puts("Twin snowflakes found.");
        //a.insert(minq);
        string str = "";
        for(int j = 0; j < 6; j++)
            str += to_string(minq[j]) + ' ';
        a[i] = str;
    }
    
    sort(a, a+N);
    for(int i = 1; i < N; i++)
        if(a[i] == a[i-1])
            return 0*puts("Twin snowflakes found.");
    
    puts("No two snowflakes are alike.");
    
    return 0;
}