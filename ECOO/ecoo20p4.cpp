#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using T = ll;

const ll mod = 1e9+7;
ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

struct matrix{
    int n, m;
    vector<vector<T>> a;
    matrix(int _n = 0, int _m = 0){
        n = _n, m = _m;
        a.resize(n);
        for(int i = 0; i < n; i++)
            a[i].resize(m);
    }
};
matrix mul(matrix ma, matrix mb){
    matrix c(ma.n, mb.m);
    for(int i = 0; i < ma.n; i++){
        for(int j = 0; j < mb.m; j++){
            T t = 0;
            for(int k = 0; k < ma.m; k++){
                t = (t + ma.a[i][k] * mb.a[k][j]%mod) % mod;
                if(t < 0)
                    t += mod;
            }
            c.a[i][j] = t;
        }
    }
    return c;
}

ll add(ll &a, ll b){
    a += b;
    a %= mod;
    if(a >= mod)
        a -= mod;
    if(a < 0)
        a += mod;
    return a;
}
ll mul(ll &a, ll b){
    a = (a*b)%mod;
    if(a < 0)
        a += mod;
    return a;
}

const int MM = 1e5+5;

matrix a[MM];

int t, n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>t;
    while(t--){
        for(int i = 0; i < MM; i++){
            a[i] = matrix(2, 2);
            a[i].a[0][0] = 1;
            a[i].a[1][1] = 1;
        }
        map<string, int> id;
        cin>>n;
        
        int ptr = 0;
        stack<int> st;
        st.push(0);
        int at = 0;
        a[at].a[0][0] = 1;
        string cur;
        
        while(n--){
            string s;
            cin>>s;
            ll v;
//            print(at);
            if(s == "ADD"){
                cin>>v;
                add(a[at].a[0][1], v);
            }
            else if(s == "SUB"){
                cin>>v;
                add(a[at].a[0][1], -v);
            }
            else if(s == "MULT"){
                cin>>v;
                mul(a[at].a[0][0], v);
                mul(a[at].a[0][1], v);
            }
            else if(s == "FUN"){
                cin>>cur;
                at = id[cur] = ++ptr;
                st.push(at);
            }
            else if(s == "END"){
                int last = at;
                st.pop();
                at = st.top();
            }
            else if(s == "CALL"){
                cin>>cur;
                a[at] = mul(a[id[cur]], a[at]);
            }
//            print(a[at].a[0][0], a[at].a[0][1]);
//            print(a[at].a[1][0], a[at].a[1][1]);
        }
        cout<<(a[0].a[0][1])<<'\n';
    }
    
    
    return 0;
}
/*
1
10
FUN F1
ADD 2
MULT 3
END
FUN F2
CALL F1
CALL F1
END
ADD 1
CALL F2
 
 */