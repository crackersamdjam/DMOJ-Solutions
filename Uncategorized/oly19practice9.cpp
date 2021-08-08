#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef pair<int, int> pii;

int N, ans, a, b;
vector<pii> vec;

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        
        stack<char> st;
        for(int j = 0; j < str.size(); j++){
            if(str[j] == ')' and !st.empty() and st.top() == '('){
                st.pop();
                ans += 2;
            }else
                st.push(str[j]);
        }
        
        int c = 0, d = 0;
        
        while(!st.empty()){
            if(st.top() == '(')
                c++;
            else
                d++;
            st.pop();
        }
        
        if(c == 0)
            b += d;
        else if(d == 0)
            a += c;
        else
            vec.push_back({c, d});
    }
    
    if(a)
        vec.push_back({a, 0});
    if(b)
        vec.push_back({0, b});
    
    sort(vec.begin(), vec.end(), [](pii x, pii y){
        if(x.second == 0)
            return true;
        if(x.first == 0)
            return false;
        return (min(x.first, y.second) > min(x.second, y.first));
    });
    
    int cnt = 0;
    
    for(pii p: vec){
    
        //printf("%d %d\n", p.first, p.second);
        
        int sub = min(cnt, p.second);
        cnt -= sub, p.second -= sub;
        ans += sub*2;
        
        cnt += p.first;
    }
    
    print(ans);
    
    return 0;
}
/*
 * greedy
 * inside string, remove pairs and add to answer
 *
 * only 3 types remainding
 *
 * (((
 * )))
 * ))((
 *
 *
 * )))(((
 * R_1, L_1
 * min(L2, R1) to sort
 *
 * )))))((
 * min(L1, R2) sort to find who comes first
 *
 * this way, more get paired
 */
/*

4
((()
()))
)((((((
)))((

 */