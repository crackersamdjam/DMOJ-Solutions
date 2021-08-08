#include <bits/stdc++.h>
#define MM 131
using namespace std;
vector<int> adj[MM];
unordered_set<int> inset[MM];
int N;
char A,B;
char contains[13];
queue<int> q;
bool vis[MM];
vector<int> vec;
unordered_set<int> letterz;
vector<int> kms;
int main(){
    scanf("%d",&N);
    while(N--){
        cin >> A >> contains >> B;
        //cout << A << " " << contains << " " << B << "\n";
        letterz.insert(A);
        if(B > 'Z'){
            inset[A].insert(B);
        }else{
            adj[A].push_back(B);
            //cout << A <<" ps " << B << "\n";
        }
    }
    for(auto it = letterz.begin(); it != letterz.end(); ++it)
        kms.push_back(*it);

    sort(kms.begin(),kms.end());
    for(auto i: kms){
        memset(vis,0,sizeof(vis));
        q.push(i); vis[i] = 1;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto it = inset[cur].begin(); it != inset[cur].end(); ++it)
                inset[i].insert(*it);

            for(auto u: adj[cur]){
                if(!vis[u]){
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }
        for(int j: inset[i]){
            vec.push_back(j);
        }
        printf("%c = {", i);
        sort(vec.begin(),vec.end());
        if(!vec.empty()){
            printf("%c",vec[0]);
            for(int j = 1; j < vec.size(); j++){
                printf(",%c",vec[j]);
            }
        }
        printf("}\n");
        vec.clear();
    }
    return 0;
}