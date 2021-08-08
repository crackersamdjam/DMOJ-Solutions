#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int maxn = 2e5+2, maxm = 2002;

int N, dp[maxm];
string dict[maxn];

int main(){
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> dict[i];
    }
    sort(dict, dict+N);
    
    for(int tc = 0; tc < 10; tc++){
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        
        string str;
        cin >> str;
        int strlen = str.size();
        
        for(int i = 0; i < strlen; i++){
            int st = upper_bound(dict, dict+N, str.substr(i)) - dict -1;
            //go backwards, bc current string is lexographically greatest
            //cout << "i " << i << endl;
            for(int j = st; j >= 0; j--){
                int len = dict[j].size();
                //only check first letter
                if(str[i] != dict[j][0])
                    break;
                //the
                //their
                //thequick
                //can not break at their
                
                if(str.substr(i, len) != dict[j])
                    continue;
                //cout << dict[j] << endl;
                dp[i+len] = min(dp[i+len], dp[i]+1);
            }
        }
        
        cout << dp[strlen]-1 << '\n';
    }
    
    return 0;
}
/*
 * alpha-order
 * loop from begin to end
 * bs for words
 */