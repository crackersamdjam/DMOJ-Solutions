#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int mod = 1e9+7;

int N;

struct node{
    int n, max = 0;
    map<int, node*> ch;
    node(int nn):n(nn){}
    int sum(){
        int ret = max;
        for(auto i: ch){
            ret += i.second->sum();
            ret %= mod;
        }
        return ret;
    }
    ~node(){
        for(auto i: ch)
            delete i.second;
    }
};

int main(){
    
    for(int tc = 10; tc--;){
        node *rt = new node(0);
        scan(N);
        for(int t = 0; t < N; t++){
            string str,s;
            cin >> str;
            for(char &c: str)
                if(c == '.')
                    c = ' ';
            stringstream ss(str);
            ss >> s;
            node *last = rt;
            while(ss.rdbuf()->in_avail()){
                ss >> s;
                int n = stoi(s);
                if(last->ch.find(n) == last->ch.end()){
                    last->ch[n] = new node(n);
                    last->max = max(last->max, n);
                }
                last = last->ch[n];
            }
        }
        print(rt->sum()+1);
        delete rt;
    }
    
    return 0;
}