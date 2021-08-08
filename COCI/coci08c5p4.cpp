#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;

int n, a[20][20], cur;
ll h, ans, pre;
bool jp = 0;

map<int, pair<int, ll>> mp;

int main(){

    scan(n, h);
    h--;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = gc-'0';
            if(i == 0 && a[i][j]){
                pre++;
                cur |= (1<<j);
            }
        }
        gc;
    }
    
    mp[cur] = {0, 0};
    ll v = 0;
    
    int t = 1;
    for(; t <= h; t++){
        int nx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j]){
                    if((cur>>i)&1){
                        nx ^= (1<<j);
                        v++;
                    }
                    else
                        v += 2;
                }
            }
        }
        if(!jp && mp.count(nx)){
            auto p = mp[nx];
            ll dif = t-p.first;
            ll val = v-p.second;
            
            //print(t, p.first, v, p.second, dif, val);
            
            ans += p.second;
            //okay...
            
            ll div = (h-p.first)/dif;
            assert(div);
            jp = 1;
            //print(t, ans, div);
            ans += div*val;
            t = p.first + div*dif;
            //printf("br "); print(t, pre, ans);
            v = 0;
        }
        out:;
        mp[nx] = {t, v};
        cur = nx;
    }
    
    print(ans + v + pre);
    
    return 0;
}