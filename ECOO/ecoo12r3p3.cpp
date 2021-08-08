#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;



int main(){
    
    int tc = 10;
    while(tc--){
    
        string str, s;
        getline(cin, str);
        for(int i = 1; i < str.size(); i++)
            if(str[i] == '(' or str[i] == ')')
                str[i] = ' ';
    
        str = str.substr(1);
    
        reverse(str.begin(), str.end());
    
        stringstream ss(str);
    
        stack<int> st;
    
        while(ss.rdbuf()->in_avail()){
            ss >> s;
            if(s == "*"){
                int v = st.top();
                st.pop();
                v *= st.top();
                st.pop();
                st.push(v);
            }
            else if(s == "+"){
                int v = st.top();
                st.pop();
                v += st.top();
                st.pop();
                st.push(v);
            }
            else if(s == "-"){
                int v = st.top();
                st.pop();
                v -= st.top();
                st.pop();
                st.push(v);
            }
            else if(s == "q"){
                int v = st.top();
                st.pop();
                v /= st.top();
                st.pop();
                st.push(v);
            }
            else if(s == "r"){
                int v = st.top();
                st.pop();
                v %= st.top();
                st.pop();
                st.push(v);
            }
            else{
                reverse(s.begin(), s.end());
                st.push(stoi(s));
            }
        }
    
        cout << st.top() << '\n';
        
    }
    
    return 0;
}