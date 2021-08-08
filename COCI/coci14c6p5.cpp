#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1001;

int R, S, a[MM][MM], b[MM][MM], ps[MM], ans;
stack<pii> st;

int main(){
    
    scanf("%d%d", &R, &S);
    
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= S; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i = 1; i < R; i++){
        for(int j = 1; j < S; j++){
            b[i][j] = (a[i][j] + a[i+1][j+1] <= a[i][j+1] + a[i+1][j]);
        }
    }
    
    for(int i = 1; i < R; i++){
        
        for(int j = 1; j <= S; j++){ //use S for last itr
            if(!b[i][j])
                ps[j] = 0;
            else
                ps[j] += b[i][j];
            
            while(!st.empty() && ps[j] <= st.top().first){
                pii last = st.top();
                st.pop();
                int loc = st.empty()? 1: (st.top().second+1);
                ans = max(ans, (j-1 - loc + 1 +1)*(last.first+1));
                //add one for extra row
            }
            
            st.push({ps[j], j});
        }
        st.pop();
        //rm last element
    }
    
    printf("%d\n", ans);
    
    return 0;
}
/*
 * if every 2x2 is cool, then entire block is cool
 * a+e <= b+d
 * b+f <= c+e
 * a+f <== c+d
 *
 * largest rectangle of cool matrices
 *
 * city game
 *
 * mono non-decreasing stack
 * when pop, find (prev, cur)*height_of_poped       cur --> (the new one)
 *
 * after done looping
 * pop, untill most right
 * last one in stack from most left to most right
 *
 * each row add to prefix sum
 * reset block when reaching 0
 * run stack algo
 *
 */