#include <bits/stdc++.h>

using namespace std;

vector<string> sub;

struct dir{
    string name, pwd;
    dir *par;
    map<string, dir*> ch;
    dir(dir *p, string n, string wd){
        par = p;
        name = n;
        pwd = wd;
    }
    
    void ls(){
        for(auto x: ch){
            sub.push_back(x.first);
            x.second->ls();
        }
    }
};

void split(vector<string> &s, string str, char regex){
    stringstream ss(str);
    string sp;
    while(getline(ss, sp, regex)){
        if(sp != "")
            s.push_back(sp);
    }
}

int main(){
    
    int N;
    
    dir *rt = new dir(nullptr, "~", "~/");
    dir *pre = rt;
    int last = -1;
    
    cin >> N;
    
    for(int i = 0,n; i < N; i++){
        string str;
        cin >> n >> str;
        while(n <= last){
            pre = pre->par;
            last--;
        }
        pre->ch[str] = new dir(pre, str, pre->pwd+str+"/");
        pre = pre->ch[str];
        last = n;
    }
    
    string tw;
    getline(cin, tw);
    
    pre = rt;
    
    while(1){
        string str;
        getline(cin, str);
        
        vector<string> s;
        split(s, str, ' ');
        
        if(s[0] == "ls"){
            sub.clear();
            
            if(s.size() > 1 && s[1] == "-r"){
                pre->ls();
                assert(*(s.begin()+1) == "-r");
                s.erase(s.begin()+1);
            }
            else{
                for(auto x: pre->ch)
                    sub.push_back(x.first);
            }
            sort(sub.begin(), sub.end());
            bool done = 0;
            
            if(s.size() > 1){
                
                assert(s[1] == "|" && s[2] == "grep");
                
                if(s[3][0] != '^')
                    s[3] = ".*" + s[3];
                if(s[3].back() != '$')
                    s[3] += ".*";
                
                regex t(s[3]);
                
                for(string i: sub){
                    smatch m;
                    regex_search(i, m, t);
                    if(m.size()){
                        done = 1;
                        cout << i << '\n';
                    }
                }
                cout << '\n';
            }
            else{
                for(string i: sub){
                    cout << i << '\n';
                    done = 1;
                }
                cout << '\n';
            }
            if(!done)
                cout << '\n';
        }
        else if(s[0] == "cd"){
            
            if(s[1][0] == '~'){
                pre = rt;
                s[1] = s[1].substr(1);
            }
            
            vector<string> path;
            split(path, s[1], '/');
            
            for(int i = 0; i < path.size(); i++){
                assert(pre->ch.find(path[i]) != pre->ch.end());
                pre = pre->ch[path[i]];
            }
        }
        else if(s[0] == "mkdir"){
            pre->ch[s[1]] = new dir(pre, s[1], pre->pwd+s[1]+"/");
        }
        else if(s[0] == "touch"){
            pre->ch[s[1]] = new dir(pre, s[1], "error");
        }
        else if(s[0] == "pwd"){
            cout << pre->pwd << "\n\n";
        }
        else{
            assert(s[0] == "exit");
            break;
        }
    }
    
    return 0;
}