#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 1e5 + 5, MM = 2e7+1;
ll N, M;
int ret = 0;
vector<ll> primes;

bool p[MN], q[MM];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M;
    memset(p, false, sizeof p);
    memset(q, false, sizeof q);
    for (ll i = 2; i * i < M; i++) {
        if (!p[i]) {
            primes.push_back(i);
            for (ll j = i; j * j < M; j += i)
                p[j] = true;
        }
    }
    for (ll i : primes) {
        ll temp = ((ll) (N / i)) * i;
        if (temp < N)
            temp += i;
        if (temp == i)
            temp += i;
        for (ll j = temp; j < M; j += i)
            q[j - N] = true;
    }
    for (ll i = max(N, 2LL); i < M; i++)
        if (!q[i - N]) ret++;
    cout << ret << '\n';
    return 0;
}