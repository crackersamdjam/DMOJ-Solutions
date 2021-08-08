// https://dmoj.ca/problem/hci16police
#include <bits/stdc++.h>
#define MX 200000
#define ll long long
#define ldb long double
using namespace std;

struct Line {
    ll m, b;
    Line (ll _m = 0, ll _b = 0) : m(_m), b(_b) {}
    ll eval(ll x) {
        return m * x + b;
    }
    // Intersection of X coordinates
    ldb intersect(Line l) {
        return (ldb) (b - l.b) / (l.m - m);
    }
};

int N;
ll H;
ll loc[MX + 1], dp[MX + 1];
deque<Line> dq;
ll ans = 0;

// dp[i] = loc[i]^2 + H + min(-2 * {loc[i]} * loc[j] + loc[j]^2 + dp[j - 1])
// slope: -2 * loc[j]

int main() {
    cin >> N >> H;

    for (int i = 1; i <= N; i++)
        cin >> loc[i];

    sort(loc + 1, loc + 1 + N);

    for (int i = 1; i <= N; i++) {
        ll curX = loc[i];

        Line cur = Line(-2 * loc[i], loc[i] * loc[i] + dp[i - 1]);

        while (dq.size() >= 2 && cur.intersect(dq[0]) <= dq[0].intersect(dq[1]))
            dq.pop_front();
        dq.push_front(cur);

        while (dq.size() >= 2 && dq.back().eval(curX) > dq[dq.size() - 2].eval(curX))
            dq.pop_back();
        
        dp[i] = dq.back().eval(curX) + loc[i] * loc[i] + H;
    }

    // for (int i = 1; i <= N; i++)   
    //     cout << dp[i] << " "; cout << endl;

    cout << dp[N] << "\n";
    return 0;
}