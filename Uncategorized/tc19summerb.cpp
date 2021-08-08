#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
//camera
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<double, int> tp;
const int MM = 5e5+1;

int N;
vector<double> v[MM];
double rem[MM], ans;

priority_queue<tp> q;
/*
 * value gained up subtracting
 * room id
 */

int main(){
    
    scanf("%d", &N);
    
    for(int i = 0,n; i < N; i++){
        scanf("%d", &n);
        double d;
        while(n--){
            scanf("%lf", &d);
            v[i].push_back(d);
        }
    }
    
    for(int i = 0; i < N; i++){
        sort(v[i].begin(), v[i].end());
        if(!v[i].empty()){
            q.push({v[i].back(), i});
        }
    }
    
    while(!q.empty()){
        auto cur = q.top(); q.pop();
        
        //cout << "pop " << cur.first << " " << cur.second << '\n';
        
        ans += cur.first;
        
        v[cur.second].pop_back();
        
        rem[cur.second] += cur.first;
        //rem[cur.second] = rem[cur.second] + cam - cam*rem[cur.second];
        
        if(!v[cur.second].empty()){
            double nx = v[cur.second].back();
            q.push({nx - nx*rem[cur.second], cur.second});
        }
        printf("%.8lf\n", ans);
    }
    
    return 0;
}