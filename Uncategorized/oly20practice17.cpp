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
const int MM = (1<<20)+5;

int k, n, q, sum[2][MM];

char s[MM], t[MM];

int main(){
    scan(k, q);
    scanf("%s", s);
    n = (1<<k);
    
    for(int i = 0; i < n; ++i){
        sum[0][i] = sum[1][(~i)&(n-1)] = s[i]-'0';
    }
    
    for(int i = 0; i < k; i++)
        for(int mask = 0; mask < n; mask++){
            if(mask&(1<<i)){
                sum[0][mask] += sum[0][mask^(1<<i)];
                sum[1][mask] += sum[1][mask^(1<<i)];
            }
        }
        
    while(q--){
        scanf("%s", t);
        reverse(t, t+k);
        int c0 = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < k; i++){
            if(t[i] == '0')
                c0++;
            else if(t[i] == '1')
                c1++;
            else
                c2++;
        }
        int all = 0;
        vector<int> op;
    
        if(c0 < 7){
            for(int i = 0; i < k; i++){
                if(t[i] == '?')
                    all |= 1<<i;
                else if(t[i] == '0')
                    op.emplace_back(1<<i);
            }
            int ans = 0;
            for(int i = 0; i < (1<<op.size()); i++){
                int v = 1, mask = all;
                if(__builtin_popcount(i) % 2 != op.size() % 2)
                    v = -1;
        
                for(int j = 0; j < op.size(); j++){
                    if(i&(1<<j))
                        mask |= op[j];
                }
        
                ans += sum[1][mask]*v;
            }
            print(ans);
        }
        else if(c1 < 7){
            for(int i = 0; i < k; i++){
                if(t[i] == '?')
                    all |= 1<<i;
                else if(t[i] == '1')
                    op.emplace_back(1<<i);
            }
            int ans = 0;
            for(int i = 0; i < (1<<op.size()); i++){
                int v = 1, mask = all;
                if(__builtin_popcount(i) % 2 != op.size() % 2)
                    v = -1;
    
                for(int j = 0; j < op.size(); j++){
                    if(i&(1<<j))
                        mask |= op[j];
                }
    
                ans += sum[0][mask]*v;
            }
            print(ans);
        }
        else{
            int ans = 0;
            for(int i = 0; i < k; i++){
                if(t[i] == '1')
                    all |= 1<<i;
                else if(t[i] == '?')
                    op.emplace_back(1<<i);
            }
            for(int i = 0; i < (1<<op.size()); i++){
                int mask = all;
                for(int j = 0; j < op.size(); j++){
                    if(i&(1<<j))
                        mask |= op[j];
                }
                ans += s[mask]-'0';
            }
            print(ans);
        }
    }
    
    return 0;
}