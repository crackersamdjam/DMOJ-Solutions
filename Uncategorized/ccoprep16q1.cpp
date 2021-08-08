#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1002;

int T, R, S, b[MM][MM], ps[MM], ans;
char str[MM];
stack<pii> st;

int main(){
    
    scanf("%d", &T);
    
    while(T--){
        
        memset(b, 0, sizeof b);
        memset(ps, 0, sizeof ps);
        while(!st.empty())
            st.pop();
        ans = 0;
        
        scanf(" %d %d", &R, &S);
    
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= S; j++){
                char c;
                scanf(" %c", &c);
                //printf("%c", c);
                b[i][j] = c == 'F';
            }
            //puts("");
        }
    
        for(int i = 1; i <= R; i++){
        
            for(int j = 1; j <= S+1; j++){ //use S+1 for last itr
                if(!b[i][j])
                    ps[j] = 0;
                else
                    ps[j] += b[i][j];
            
                while(!st.empty() && ps[j] <= st.top().first){
                    pii last = st.top();
                    st.pop();
                    int loc = st.empty() ? 1 : (st.top().second + 1);
                    ans = max(ans, (j - 1 - loc + 1) * last.first);
                    //add one for extra row
                }
            
                st.push({ps[j], j});
            }
            st.pop();
            //rm last element
        }
        printf("%d\n", ans*3);
    }
    
    return 0;
}