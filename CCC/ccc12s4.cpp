#define DEBUG
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = (1<<21);

int n, dis[MM];

queue<int> q;

inline void peek(int mask){
    /*
    for(int j = 0; j < n; j++){
        printf("%d", (mask >> (3*j)) & 7);
    }
    printf("\n");
     */
}

int main(){
    
    while(1){
        memset(dis, 0x3f, sizeof(dis));
    
        scan(n);
        if(n == 0)
            break;
        int start = 0;
    
        for(int i = 0, m; i < n; i++){
            scan(m);
            m--;
            start |= (i << (m*3));
            //three bits each n
        }
        
        peek(start);
        
        dis[start] = 0;
        q.push(start);
        while(!q.empty()){
            int mask = q.front();
            q.pop();
            
            /*
            printf("%d at ", dis[mask]);
            peek(mask);
            */
            
            for(int i = 0; i < n; i++){
                //which coin to move
                int loc = (mask>>(3*i))&7;
                
                // at location, make sure there is no lower val coin (than i) at same loc
                // can not move this coin underneath
                bool can = 1;
                for(int j = 0; j < i; j++){
                    if(((mask >> (j*3))&7) == loc){
                        can = 0;
                        /*
                        if(dis[mask] == 5 && i == 2){
                            printf("fail at %d\n", j);
                        }
                         */
                    }
                }
                
                /*
                if(dis[mask] == 5 && i == 2){
                    printf("loc %d\n", loc);
                    printf("can %d\n", can);
                    printf("mask ");
                    peek(mask);
                }
                */
                
                if(!can)
                    continue;
                
                if(loc + 1 < n){
                    int nx = (mask^(loc<<(3*i))) | ((loc+1)<<(3*i));
                    // rm old loc first
                
                    bool flag = 1;
                    // check for lower coin val
                    for(int j = 0; j < i; j++){
                        if(((mask >> (j*3))&7) == (loc+1)){
                            flag = 0;
                            break;
                        }
                    }
                    
                    if(dis[mask] + 1 < dis[nx] && flag){
                        dis[nx] = dis[mask] + 1;
                        q.push(nx);
                    }
                }
            
                if(loc - 1 >= 0){
                    int nx = (mask^(loc<<(3*i))) | ((loc-1)<<(3*i));
                
                    bool flag = 1;
                    // check for lower coin val
                    for(int j = 0; j < i; j++){
                        if(((mask >> (j*3))&7) == (loc-1)){
                            flag = 0;
                            break;
                        }
                    }
                
                    if(dis[mask] + 1 < dis[nx] && flag){
                        dis[nx] = dis[mask] + 1;
                        q.push(nx);
                    }
                }
            }
        }
        int end = 0;
        for(int i = 0; i < n; i++){
            end |= (i << (i*3));
        }
        
        peek(end);
    
        if(dis[end] == 0x3f3f3f3f)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", dis[end]);

        /*
        for(int i = 0; i < MM; i++){
            if(dis[i] == 1){
                printf("one ");
                peek(i);
            }
        }
        break;
        */
    
    }
    return 0;
}