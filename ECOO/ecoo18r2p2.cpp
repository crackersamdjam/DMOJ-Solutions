#include <bits/stdc++.h>

using namespace std;

int N;
int parent[1000001];
vector<pair<double, int>> work;

int find(int n) {
    while (n != parent[n]) {
        n = parent[n];
        parent[n] = parent[parent[n]];
    }
    return n;
}

int main() {
    int _=10;
    while (_--) {
        for (int i=0; i<1000001; i++) {
            parent[i] = i;
        }
        
        while (!work.empty()) {
            work.pop_back();
        }
        
        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            int due;
            double weight;
            scanf("%d %lf", &due, &weight);
            work.push_back(make_pair(weight, due));
        }
        
        sort(work.begin(), work.end());
        reverse(work.begin(), work.end());
        
        double weight = 0;
        for (int i=0; i<work.size(); i++) {
            pair<double, int> assign = work[i];
            if (find(assign.second) != 0) {
                parent[find(assign.second)] = find(assign.second)-1;
                weight += assign.first;
            }
        }
        
        printf("%.4lf\n", weight);
        
    }
    return 0;
}