#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+2;

int n, q, r[MM], c[MM];
vector<int> rw[MM], cl[MM];

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif

    scan(n, q);

    for(int i = 1,t; i <= n; i++){
    	scan(r[i]);
        t = r[i];
        for(int j = 2; j*j <= t; j++){
            if(t % j == 0){
                cl[j].push_back(i);
                while(t % j == 0)
                    t /= j;
            }
        }
        if(t > 1) cl[t].push_back(i);
    }
    
    for(int i = 1,t; i <= n; i++){
    	scan(c[i]);
        t = c[i];
        for(int j = 2; j*j <= t; j++){
            if(t % j == 0){
                rw[j].push_back(i);
                while(t % j == 0)
                    t /= j;
            }
        }
        if(t > 1) rw[t].push_back(i);
    }

    for(int z = 0,sr,sc,er,ec,t; z < q; z++){
    	scan(sr, sc, er, ec);
        t = r[sr]*c[sc];
        //printf("t %d\n", t);
        vector<int> p;
        for(int j = 2; j*j <= t; j++){
            if(t % j == 0){
                p.push_back(j);
                while(t % j == 0)
                    t /= j;
            }
        }
        if(t > 1) p.push_back(t);

        assert(is_sorted(p.begin(), p.end()));
        reverse(p.begin(), p.end());
        for(int v: p){
            //right and down
            int cnt1 = upper_bound(rw[v].begin(), rw[v].end(), ec)-1
                -(lower_bound(rw[v].begin(), rw[v].end(), sc)-1);
            int cnt2 = upper_bound(cl[v].begin(), cl[v].end(), er)-1
                -(lower_bound(cl[v].begin(), cl[v].end(), sr)-1);
            //print(cnt1, ec-sc+1, cnt2, er-sr+1); 
            if((cnt1 == ec-sc+1 or r[sr] % v == 0) and (cnt2 == er-sr+1 or c[ec] % v == 0)){
                print(v);
                goto nx;
            }
            //down and right
            swap(cnt1, cnt2);
            if((cnt1 == er-sr+1 or c[sc] % v == 0) and (cnt2 == ec-sc+1 or r[er] % v == 0)){
                print(v);
                goto nx;
            }
            //right, down, right
            if(upper_bound(rw[v].begin(), rw[v].end(), sc) != upper_bound(rw[v].begin(), rw[v].end(),ec) and r[sr] % v == 0 and r[er] % v == 0){
                print(v);
                goto nx;
            }
            //down, right, down
            if(upper_bound(cl[v].begin(), cl[v].end(), sr) != upper_bound(cl[v].begin(), cl[v].end(), er) and c[sc] % v == 0 and c[ec] % v == 0){
                print(v);
                goto nx;
            }
        }
        puts("-1");
        nx:;
    }
    
    return 0;
}