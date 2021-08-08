#include <bits/stdc++.h>
#define MM 100002
using namespace std;

map<string, int> m;
int parent[MM];

int find(int cur){
    if (parent[cur] != cur) parent[cur] = find(parent[cur]);
    return parent[cur];
}

string a,b,c;
int main(){
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    for (int aa = 0,n; aa < 5; aa++){
        cin >> n;
        m.clear();
        int cnt = 1;
        for (int i = 1; i < MM; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++){
            cin >> c >> a >> b;
            if(!m[a])
                m[a] = cnt++;
            if(!m[b])
                m[b] = cnt++;
            if (c == "p"){
                if (find(m[a]) != find(m[b]))
                parent[find(m[a])] = find(m[b]);
            }else
                cout << (find(m[a]) == find(m[b]) ? "connected\n" : "not connected\n");
        }
    }
    return 0;
}