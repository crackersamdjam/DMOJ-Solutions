#include <bits/stdc++.h>
using namespace std;
const int MM = 513;

int N, psa[MM][MM];
char in[MM];
bool a[MM][MM], out[MM][MM];
struct square{
    int u, d, l, r, v, rec, id;
    friend bool operator<(square x, square y){
        return x.id < y.id;
    }
};

inline int area(square sq){
    return psa[sq.d][sq.r] - psa[sq.u-1][sq.r] - psa[sq.d][sq.l-1] + psa[sq.u-1][sq.l-1];
}

inline void fill(square sq, int c){
    for(int i = sq.u; i <= sq.d; i++){
        for(int j = sq.l; j <= sq.r; j++)
            out[i][j] = c;
    }
}

int go(int u, int d, int l, int r){
    if(u == d){
        out[u][l] = a[u][l];
        return 0;
    }
    
    int mx = (u+d)/2, my = (l+r)/2;
    int all = (d-u+1)*(d-u+1)/4, best = INT_MAX;
    
    square test[4], w, b;
    test[0] = {u, mx, l, my, 0, go(u, mx, l, my), 0};
    test[1] = {mx+1, d, l, my, 0, go(mx+1, d, l, my), 1};
    test[2] = {u, mx, my+1, r, 0, go(u, mx, my+1, r), 2};
    test[3] = {mx+1, d, my+1, r, 0, go(mx+1, d, my+1, r), 3};
    for(int i = 0; i < 4; i++)
        test[i].v = area(test[i]);
    
    do{
        int v = (all - test[0].v) + test[1].v + test[2].rec + test[3].rec;
        if(v < best){
            best = v;
            w = test[0], b = test[1];
        }
    } while(next_permutation(test, test+4));
    
    fill(w, 1);
    fill(b, 0);
    
    return best;
}


int main(){
    
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++){
        scanf("%s", in);
        for(int j = 1; j <= N; j++){
            a[i][j] = in[j-1] == '1';
            psa[i][j] = a[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    
    int ans = go(1, N, 1, N);
    
    printf("%d\n", ans);
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            putchar_unlocked(out[i][j]? '1': '0');
        
        putchar_unlocked(10);
    }
    
    return 0;
}
/*
 * just call it recusion
 * split into 4 squares every time
 * psa find val of sqs, match white and black with closest vals
 * recur for the other two
 *
 * every time sq side len /= 2 but processes inc by *= 2
 * geometric series
 * (1-2^log2n)/(1-2)
 * = (1-n)/-1
 * = n-1
 * linear time
 *
 * I can't choose based on number, gives wrong ans
 * depends on how they are spaced
 *
 * instead, try splitting every sq and then choosing best ans combo
 * (1-4^log2n)/1-2
 * = n^2 - 1
 */