#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> id;
string name[21];

int N, M, cnt[21];
bool no[21];

queue<int> votes[10001];

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        assert(str != "evan");
        id[str] = i;
        name[i] = str;
    }
    
    for(int i = 0,x; i < M; i++){
        cin >> x;
        for(int j = 0; j < x; j++){
            string str;
            cin >> str;
            votes[i].push(id[str]);
            if(j == 0)
                cnt[id[str]]++;
        }
    }
    
    int in = N;
    while(in > 1){
        
        int low = 1e9, at = -1;
        for(int i = 0; i < N; i++){
            
            if(cnt[i] >= (M+1)/2){
                cout << name[i] << endl;
                return 0;
            }
            
            if(!no[i] && cnt[i] < low){
                low = cnt[i];
                at = i;
            }
        }
        
        no[at] = 1;
        in--;
        
        for(int i = 0; i < M; i++){
            if(!votes[i].empty() && votes[i].front() == at){
                votes[i].pop();
                
                while(!votes[i].empty() && no[votes[i].front()])
                    votes[i].pop();
                
                if(!votes[i].empty()){
                    cnt[votes[i].front()]++;
                }
            }
        }
    }
    
    int win = -1;
    for(int i = 0; i < N; i++){
        if(!no[i]){
            win = i;
            break;
        }
    }
    
    cout << name[win] << '\n';
    
    return 0;
}