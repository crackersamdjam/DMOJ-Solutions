#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define nl '\n'
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define flood(x) memset(x, 0x3f3f3f3f, sizeof x)
#define drain(x) memset(x, 0, sizeof x)
#define dcit cin.sync_with_stdio(0);cin.tie(0);
#define frp(x, y) freopen(x, "r", stdin);freopen(y, "w", stdout);
typedef pair<int, int> pii;
typedef long long ll;

int N, Q, BIT[8195][8195], val[8195];

void update(int row, int col, int val){
    while(row <= 8194){
        int col1 = col;
        while(col1 <= 8194){
            BIT[row][col1] += val;
            col1 += (col1 & -col1);
        }
        row += (row & -row);
    }
}
int sum(int row, int col){
    if(row <= 0 || col <= 0)
        return 0;
    int val = 0;
    while(row > 0){
        int col1 = col;
        while(col1 > 0){
            val += BIT[row][col1];
            col1 -= (col1 & -col1);
        }
        row -= (row & -row);
    }
    return val;

}
int sum(int c1, int r1, int c2, int r2) {
    return sum(c2, r2)-sum(c1-1, r2)-sum(c2, r1-1)+sum(c1-1, r1-1);
}
int main(){
    scanf("%d", &N);
    for (int i = 1, h; i <= N; i++) {
        scanf("%d", &h); h++;update(i, h, 1);
        val[i] = h;
    }
    scanf("%d", &Q);
    while(Q--){
        int instr; scanf("%d", &instr);
        if(instr==1){
            int i, j, a, b; scanf("%d %d %d %d", &i, &j, &a, &b);a++;b++; i++;j++;
            printf("%d\n", sum(i, a, j, b));
        } else if (instr==2){
            int i, h; scanf("%d %d", &i, &h);h++;i++;
            update(i, val[i], -1); update(i, h, 1); val[i] = h;
        }
    }
    return 0;
}