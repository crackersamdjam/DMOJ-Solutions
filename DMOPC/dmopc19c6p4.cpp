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
const int MM = 5e5+5;

int n, q, a[MM];
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> bbst;
bbst b[MM<<1];

int main(){
    scan(n, q);
    for(int i = 1; i <= n; i++){
        a[i] = MM;
        b[MM].insert(i);
    }
    
    for(int i = 0,op,l,r,c; i < q; i++){
        scan(op, l);
        
        if(op == 1){
            b[a[l]].erase(l);
            a[l]++;
            b[a[l]].insert(l);
        }
        else if(op == 2){
            b[a[l]].erase(l);
            a[l]--;
            b[a[l]].insert(l);
        }
        else{
            scan(r, c);
            c += MM;
            int cnt = b[c].order_of_key(r+1) - b[c].order_of_key(l);
//            print(b[c].order_of_key(r+1), b[c].order_of_key(l));
            print(cnt);
        }
    }
    
    
    return 0;
}