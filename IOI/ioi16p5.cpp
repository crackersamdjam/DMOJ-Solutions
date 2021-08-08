#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

#ifndef ONLINE_JUDGE
set<string> st;
int mp[] = {2, 1, 3, 0};
void add_element(string s){
    string ss = s;
    for(int i = 0; i < s.size(); i++)
        ss[i] = s[mp[i]];
    st.insert(ss);
    cout<<"add "<<s<<"<<"<<ss<<'\n';
}
void compile_set(){}
bool check_element(string s){
    cout<<s<<' '<<st.count(s)<<'\n';
    return st.count(s);
}
#endif

void make(int l, int r, int n){
    if(l == r)
        return;
    int m = (l+r)/2;
    string s;
    for(int i = 0; i < n; i++)
        s.push_back('1');
    for(int i = l; i <= r; i++)
        s[i] = '0';
    for(int i = l; i <= m; i++){
        s[i] = '1';
        add_element(s);
        s[i] = '0';
    }
    make(l, m, n);
    make(m+1, r, n);
}

void go(int l, int r, vector<int> &v, int n, int *p){
    if(l == r){
        p[v[0]] = l;
        return;
    }
    int m = (l+r)/2;
    vector<int> vl, vr;
    string s;
    for(int i = 0; i < n; i++)
        s.push_back('1');
    for(int i: v)
        s[i] = '0';
    
    for(int i: v){
        s[i] = '1';
        if(check_element(s))
            vl.emplace_back(i);
        else
            vr.emplace_back(i);
        s[i] = '0';
    }
    go(l, m, vl, n, p);
    go(m+1, r, vr, n, p);
}

int* restore_permutation(int n, int w, int r){
    int *p = new int[n];
    make(0, n-1, n);
    compile_set();
    vector<int> v;
    for(int i = 0; i < n; i++)
        v.emplace_back(i);
    go(0, n-1, v, n, p);
    return p;
}

#ifndef ONLINE_JUDGE
int main(){
    int n = 4;
    int *r = restore_permutation(n, n*7, n*7);
    for(int i = 0; i < n; i++)
        printf("%d ", *(r+i));
    
    return 0;
}
#endif