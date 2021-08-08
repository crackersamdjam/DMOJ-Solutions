#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

int N, tc = 5;
char in[23][23], ans[23][23];

void out(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            pc(ans[i][j]);
        }
        pc(10);
    }
}

int rem(int r, int c){
    int cnt = 0;
    for(int i = max(1, r-1); i <= min(N, r+1); i++){
        for(int j = max(1, c-1); j <= min(N, c+1); j++){
            cnt += ans[i][j] == 0;
        }
    }
    return cnt;
}

void update(int r, int c){
    for(int i = max(1, r-1); i <= min(N, r+1); i++){
        for(int j = max(1, c-1); j <= min(N, c+1); j++){
            if(in[i][j] != '-'){
                in[i][j]--;
                assert(in[i][j] >= '0' and in[i][j] <= '9');
            }
        }
    }
}

void fill(int r, int c, char v){
    for(int i = max(1, r-1); i <= min(N, r+1); i++){
        for(int j = max(1, c-1); j <= min(N, c+1); j++){
            if(ans[i][j] == 0){
                ans[i][j] = v;
                if(v == 'M')
                    update(i, j);
            }
        }
    }
}

bool go(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            
            if(!rem(i, j))
                continue;
            
            if(rem(i, j) == in[i][j]-'0'){
                //fill with yes
                fill(i, j, 'M');
                return 1;
            }
            else if(in[i][j] == '0' and rem(i, j)){
                //fill with empty
                fill(i, j, '.');
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    
    while(tc--){
        
        memset(in, 0, sizeof in);
        memset(ans, 0, sizeof ans);
    
        scanf("%s", in[1] + 1);
        N = strlen(in[1] + 1);
        for(int i = 2; i <= N; i++)
            scanf("%s", in[i] + 1);
    
        while(go());
    
        out();
    
    }
    
    return 0;
}