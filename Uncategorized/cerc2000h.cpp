#include <bits/stdc++.h>
using namespace std;

bool contradict = 0;
struct st{
    string subject, verb, object;
    bool neg;
};
vector<st> all;

void split(vector<string> &s, const string &str, char sep){
    stringstream ss(str);
    string sp;
    while(getline(ss, sp, sep)){
        if(sp != "")
            s.push_back(sp);
    }
}

void infin(string subject, string &verb){
    if(subject != "I" && subject != "you"){
        assert(verb.back() == 's');
        verb.pop_back();
    }
}

void conj(string subject, string &verb){
    if(subject != "I" && subject != "you")
        verb.push_back('s');
}

string opposite(string subject){
    if(subject == "I")
        return "you";
    if(subject == "you")
        return "I";
    return subject;
}

void statement(vector<string> s){
    
    bool neg = 0;
    string subject = s[0], verb, object = "";
    
    if(s[1] == "don't" or s[1] == "doesn't"){
        neg = 1;
        s.erase(s.begin()+1);
        verb = s[1];
    }
    else{
        verb = s[1];
        infin(subject, verb);
    }
    
    //subject [-] predicate [object]
    while(s.size() > 3){
        s[2] += " " + s[3];
        s.erase(s.begin()+3);
    }
    
    if(s.size() > 2)
        object = s[2];
    
    if(subject == "nobody"){
        subject = "everybody";
        neg ^= 1;
    }
    
    for(int i = 0; i < all.size(); i++){
        
        auto st = all[i];
        
        if(st.verb != verb || st.object != object)
            continue;
        
        if((subject == "everybody" || st.subject == "everybody") && (neg != st.neg)){
            contradict = 1;
            return;
        }
        
        if(subject == st.subject && neg != st.neg){
            contradict = 1;
            return;
        }
        
        if(st.subject == "everybody"){
            //no need to add
            return;
        }
        
        if(subject == "everybody"){
            //remove existing one
            all.erase(all.begin()+i);
            i--;
        }
    }
    
    all.push_back({subject, verb, object, neg});

}

string getneg(string subject){
    if(subject == "I" || subject == "you")
        return "don't";
    else
        return "doesn't";
}

void qdoes(vector<string> &s){
    
    assert(s[2] != "don't" && s[2] != "doesn't");
    
    string subject = s[1], verb = s[2], object = "";
    
    while(s.size() > 4){ // does subject predicate [object]
        s[3] += " " + s[4];
        s.erase(s.begin()+4);
    }
    if(s.size() > 3)
        object = s[3];
    
    
    for(auto st: all){
        
        if((st.subject == subject || st.subject == "everybody") && st.verb == verb && st.object == object){
            
            if(!st.neg){
                conj(subject, verb);
                cout << "yes, " << opposite(subject) << " " << verb;
                if(object != "")
                    cout << " " << object;
                cout << ".\n";
            }
            else{
                //no need to conjugate
                cout << "no, " << opposite(subject) << " " << getneg(subject) << " " << verb;
                if(object != "")
                    cout << " " << object;
                cout << ".\n";
            }
            return;
        }
    }
    
    printf("maybe.\n");
}


void qwho(vector<string> &s){
    
    assert(s[1] != "don't" && s[1] != "doesn't");
    
    vector<string> ans;
    string verb = s[1], object = "";
    infin("who", verb);
    
    while(s.size() > 3){ // who predicates [object]
        s[2] += " " + s[3];
        s.erase(s.begin()+3);
    }
    if(s.size() > 2)
        object = s[2];
    
    
    for(auto st: all){
        
        if(st.verb == verb && st.object == object){
            
            if(st.subject == "everybody"){
                
                if(!st.neg){
                    conj("everybody", verb);
                    cout << "everybody " << verb;
                    if(object != "")
                        cout << " " << object;
                    cout << ".\n";
                    return;
                }
                
                //negative
                conj("nobody", verb);
                cout << "nobody " << verb;
                if(object != "")
                    cout << " " << object;
                cout << ".\n";
                return;
            }
            if(!st.neg)
                ans.push_back(opposite(st.subject));
        }
    }
    
    if(ans.empty()){
        printf("I don't know.\n");
        return;
    }
    
    if(ans.size() == 1){
        conj(ans[0], verb);
        cout << ans[0] << " " << verb;
        if(object != "")
            cout << " " << object;
        cout << ".\n";
        return;
    }
    
    conj("I", verb); //without 's'
    cout << ans[0];
    for(int i = 1; i < ans.size()-1; i++)
        cout << ", " << ans[i];
    cout << " and " << ans.back() << " " << verb;
    if(object != "")
        cout << " " << object;
    cout << ".\n";
}

void qwhat(vector<string> &s){
    
    vector<st> ans;
    string subject = s[2];
    
    for(auto st: all){
        if(st.subject == "everybody" || st.subject == subject)
            ans.push_back(st);
    }
    
    if(ans.empty()){
        printf("I don't know.\n");
        return;
    }
    
    cout << opposite(subject) << " ";
    
    for(int i = 0; i < ans.size()-1; i++){
        auto st = ans[i];
        
        if(!st.neg){
            string verb = st.verb;
            conj(subject, verb);
            cout << verb;
            if(st.object != "")
                cout << " " << st.object;
            cout << ", ";
        }
        else{
            cout << getneg(subject) << " " << st.verb;
            if(st.object != "")
                cout << " " << st.object;
            cout << ", ";
        }
    }
    
    auto st = ans.back();
    
    if(ans.size() > 1)
        cout << "and ";
    if(!st.neg){
        string verb = st.verb;
        conj(subject, verb);
        cout << verb;
        if(st.object != "")
            cout << " " << st.object;
        cout << ".\n";
    }
    else{
        cout << getneg(subject) << " " << st.verb;
        if(st.object != "")
            cout << " " << st.object;
        cout << ".\n";
    }
}

void go(){
    
    all.clear();
    contradict = 0;
    string str;
    vector<string> s;
    
    while(1){
        
        getline(cin, str);
        s.clear();
        split(s, str, ' ');
        s.back().pop_back();  // .?!
        
        if(str.back() == '.'){
            statement(s);
        }
        else if(str.back() == '?'){
            
            cout << str << '\n';
            
            if(contradict){
                printf("I am abroad.\n\n");
                continue;
            }
            
            if(s[0] == "does" || s[0] == "do")
                qdoes(s);
            else if(s[0] == "who")
                qwho(s);
            else
                qwhat(s);
            
            printf("\n");
        }
        else break;
    }
    cout << str << "\n\n";
}

int main(){
    
    string s;
    getline(cin, s);
    int T = stoi(s);
    
    for(int dn = 1; dn <= T; dn++){
        printf("Dialogue #%d:\n", dn);
        go();
    }
    
    return 0;
}