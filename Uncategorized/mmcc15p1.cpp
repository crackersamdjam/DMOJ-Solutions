//#include "inaho.h"
#include <bits/stdc++.h>
using namespace std;
const int MM = 500002;

int par[MM], sz[MM];
struct st{
    int u, v, t;
};
stack<st> last;


void Init(int N){
    for(int i = 1; i <= N; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

inline int find(int x){
    while(x != par[x]){
        x = par[x];
        //can not coord-comp
    }
    return x;
}

void AddEdge(int U, int V){
    
    int u = find(U), v = find(V);
    
    if(u != v){
        
        if(sz[u] > sz[v]){
            par[v] = u;
            sz[u] += sz[v];
            last.push({u, v, 1});
        }
        else{
            par[u] = v;
            sz[v] += sz[u];
            last.push({u, v, 0});
        }
    }
    else{
        last.push({-1, -1, -1});
    }
}

void RemoveLastEdge(){
    
    st rm = last.top(); last.pop();
    
    if(rm.t == -1)
        return;
    
    if(rm.t){
        par[rm.v] = rm.v;
        sz[rm.u] -= sz[rm.v];
    }
    else{
        par[rm.u] = rm.u;
        sz[rm.v] -= sz[rm.u];
    }
}

int GetSize(int U){
    return sz[find(U)];
}