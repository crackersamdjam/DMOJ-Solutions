#include <bits/stdc++.h>
using namespace std;
const int MM = 5005*4;

struct node{
    int len = 0, dp = 0;
    node *par;
    map<char, node*> ch;
} *rt, *last;

void extend(char c){
    node *cur = new node();
    cur->len = last->len+1;
    node *t = last;
    while(t and !t->ch.count(c)){
        t->ch[c] = cur;
        t = t->par;
    }
    if(!t){
        cur->par = rt;
    }
    else{
        node *o = t->ch[c];
        if(t->len+1 == o->len){
            cur->par = o;
        }
        else{
            node *ac = new node(); //clone
            ac->ch = o->ch;
            ac->par = o->par;
            ac->len = t->len+1;
            while(t and t->ch[c] == o){
                //redirect all these to clone
                t->ch[c] = ac;
                t = t->par;
            }
            cur->par = o->par = ac;
        }
    }
    last = cur;
}

int dfs(node *cur){
    if(cur->dp)
        return cur->dp;
    for(auto i: cur->ch)
        cur->dp += dfs(i.second);
    return ++cur->dp;
}

int main(){
    int t;
    string s;
    cin>>t;
    while(t--){
        
        rt = new node();
        last = rt;
        
        cin>>s;
        for(char c: s)
            extend(c);
        
        cout << dfs(rt) << '\n';
    }
}