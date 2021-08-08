//got aqt to make problem (harder) but data's still shit
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+1;

int N, Q;

struct st{
    int l, r, v, id;
    bool operator <(const st &o) const{
        if(l ^ o.l)
            return l < o.l;
        return r > o.r;
    }
} a[MM], id[MM];

struct node{
    int l, r, min, id;
    map<pair<int, int>, node*> ch;
    void ls(){
        print(l, r, min);
        for(auto c: ch)
            c.second->ls();
    }
    void ree(){
        for(auto c: ch){
            c.second->min = std::min(c.second->min, min);
            c.second->ree();
        }
    }
};

stack<node*> ed;

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        scan(a[i].l, a[i].r, a[i].v);
        a[i].id = i+1;
        id[i] = a[i];
    }
    
    sort(a, a+N);
    
    node *rt = new node({0, INT_MAX, INT_MAX});
    
    ed.push(rt);
    
    for(int i = 0; i < N; i++){
        while(a[i].r > ed.top()->r)
            ed.pop();
    
        node* temp = new node({a[i].l, a[i].r, a[i].v, a[i].id});
        ed.top()->ch[{a[i].l, a[i].r}] = temp;
        ed.push(temp);
    }
    
    scan(Q);
    
    for(int t = 0,b,c; t < Q; t++){
        scan(b, c);
        b--, c--;
        set<pair<int, int>> ans;
        
        int l = min(id[b].l, id[c].l), r = max(id[b].r, id[c].r);
        
        node* p = rt;
        while(1){
            ans.insert({p->min, p->id});
            if((p->ch.lower_bound({l+1, 0})) != p->ch.begin()){
                auto it = --p->ch.lower_bound({l+1, 0});
                if(it->first.first <= l && it->first.second >= r)
                    p = it->second;
                else break;
            }
            else break;
        }
        
        while(ans.begin()->first == id[b].v || ans.begin()->first == id[c].v)
            ans.erase(ans.begin());
        
        if(ans.begin()->first == INT_MAX)
            puts("-1");
        else
            print(ans.begin()->second);
    }
    
    
    return 0;
}