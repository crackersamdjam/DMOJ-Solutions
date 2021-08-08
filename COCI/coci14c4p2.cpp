#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5+1;

int cnt[MM], N, turn;

deque<pii> evan;

int main(){
    
    scanf("%d", &N);
    
    for(int i = 0,n; i < N; i++){
        scanf("%d", &n);
        cnt[n]++;
        assert(n >= 0);
    }
    
    for(int i = 0; i < MM; i++){
        if(cnt[i]){
            evan.push_back({i, cnt[i]});
        }
    }
    
    if(evan.size() < 3){
        puts("Slavko");
        printf("%d %d\n", evan.front().first, evan.back().first);
        return 0;
    }
    
    while(1){
        
        if(evan.size() == 2){
            puts("Slavko");
            printf("%d %d\n", evan.front().first, evan.back().first);
            return 0;
        }
        
        if(evan.size() == 3){
            
            if(evan.front().second < evan.back().second){
                puts("Mirko");
                evan.pop_front();
            }
            else{
    
                puts("Slavko");
                evan.pop_back();
            }
            printf("%d %d\n", evan.front().first, evan.back().first);
            return 0;
        }
    
        pii low = evan.front(), high = evan.back();
        evan.pop_front(); evan.pop_back();
        
        int rm = min(low.second, high.second);
        
        low.second -= rm;
        high.second -= rm;
        evan.front().second += rm;
        evan.back().second += rm;
        
        if(low.second)
            evan.push_front(low);
        else
            evan.push_back(high);
        
        //turn stays same
    }
    
    return 0;
}