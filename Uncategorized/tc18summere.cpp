#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> pii;
#define f v[i].first
#define s v[i].second
inline bool cmp(pii a, pii b){
    return a.first < b.first;
}
vector<pii> v;

int main(){
    int n, c; scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++){
        int d, x, y; scanf("%d %d %d", &d, &x, &y);
        v.emplace_back(sqrt(x*x+y*y), d);
    }
    sort(v.begin(), v.end(), cmp);
    double ans = 0, temp = 0;
    for (int i = 0; i < n; i++){
        temp += s;

        if (temp-c*f*f > ans) ans = temp-c*f*f;
    }
    printf("%.0lf\n", ans);
    return 0;
}