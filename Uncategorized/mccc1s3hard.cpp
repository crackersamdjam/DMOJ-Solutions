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
const int MM = 4e5+5;

struct node{
    int dis;
    map<char, node*> ch;
    node(int t = 69){
        dis = t;
    }
    int query(string &s, int i){
        if(i == s.size())
            return dis;
        if(!ch.count(s[i]))
            return dis;
        return ch[s[i]]->query(s, i+1);
    }
};

string s;
int q, nx;
node* ptr[MM];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s>>q;
    
    ptr[1] = new node(-1);
    node* cur = ptr[1];
    for(int i = 0; i < s.size(); i++){
        cur = cur->ch[s[i]] = new node(1);
    }
    swap(cur, ptr[1]);
    nx = 2;
    
    while(q--){
        int i;
        char op, c;
        cin>>op;
        if(op == 'C'){
            cin>>i>>c;
            if(!ptr[i]->ch.count(c))
                ptr[i]->ch[c] = new node(nx);
            ptr[nx] = ptr[i]->ch[c];
            nx++;
        }
        else{
            cin>>s;
            cout<<cur->query(s, 0)<<'\n';
        }
    }
    
    return 0;
}