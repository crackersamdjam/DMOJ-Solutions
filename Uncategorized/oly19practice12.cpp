#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 2e4+2;

int N, K, a[MM], psa[MM], pos, contig, psum, ans;
int t, id[MM], dp[402][MM], best[MM], sl[MM], sr[MM];

inline int rsum(int l, int r){
    return psa[r] - psa[l-1];
}

int main(){
    
    //memset(dp, -0x3f, sizeof dp);
    //memset(best, -0x3f, sizeof best);
    
    scan(N, K);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        psa[i] = psa[i-1] + a[i];
        if(a[i] >= 0){
            pos++;
            psum += a[i];
            
        }
        if(i > 0 and a[i-1] >= 0 and a[i] < 0)
            contig++;
    }
    
    if(a[N] < 0)
        contig--;
    //last one doesn't split
    
    if(K > pos){
        
        sort(a+1, a+1+N);
        for(int i = N; i > N-K; i--)
            ans += a[i];
        
        print(ans);
        return 0;
    }
    
    if(K >= contig){
        print(psum);
        return 0;
    }
    
    //now make contigs dp
    
    int st = 1;
    while(a[st] < 0)
        st++;
    
    id[st] = ++t;
    sl[1] = st;
    
    for(int i = st+1; i <= N; i++){
        if(a[i] >= 0){
            if(id[i-1])
                id[i] = id[i-1];
            else{
                id[i] = ++t;
                sl[t] = i;
            }
        }
        else if(a[i-1] >= 0){
            sr[t] = i-1;
        }
    }
    
    if(!sr[t])
        sr[t] = N;
    
    dp[1][1] = rsum(sl[1], sr[1]);
    best[1] = dp[1][1];
    
    for(int i = 2; i <= t; i++){
        for(int j = 1; j <= t; j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j] + rsum(sr[i-1]+1, sr[i]));
        }
        //from last end +1  -- right end
        for(int j = 1; j <= t; j++)
            dp[i][j] = max(dp[i][j], best[j-1] + rsum(sl[i], sr[i]));
        
        //jumping
        for(int j = 1; j <= t; j++)
            best[j] = max(best[j], dp[i][j]);
    }
    
    int out = 0;
    
    for(int i = 1; i <= t; i++)
        out = max(out, dp[i][K]);
    
    print(out);
    
    /*
    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= t; j++){
            printf("%d ", dp[i][j]);
        }
        pc(10);
    }
     */
    
    return 0;
}
/*
 * N^3 50%
 *
 *
 * make contigs, and find which best to merge
 *      dp[seg#] = dp[seg#-1] + sum between segs
 * num of contig
 *      between here, take sum of positive
 * num of pos #
 *      if K >, then take least negatives
 */
/*
20 2
-30201 30988 6740 7896 -17115 3036 -27550 -17496 -8062 13252 31818 -29201 -16936 -28210 29239 8667 -16498 12937 -23768 -9154 95913
 */