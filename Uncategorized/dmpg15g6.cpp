#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 2e5+1;

int N, M, Q, a[MM];
vector<int> cnt[MM];
unordered_set<int> done;

int main(){
    
    srand(time(0));
    
    scan(N, M);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        cnt[a[i]].push_back(i);
    }
    
    scan(Q);
    
    for(int t = 0,l,r,res = 0; t < Q; t++, res = 0, done.clear()){
        scan(l, r);
        int len = r-l+1;
        double lim = (double)len/3;
        
        for(int k = 0; k < 31; k++){
            int at = a[rand()%len + l];
            
            if(done.count(at))
                continue;
            
            done.insert(at);
            
            int num = (upper_bound(cnt[at].begin(), cnt[at].end(), r) - lower_bound(cnt[at].begin(), cnt[at].end(), l));
            
            res += num/lim;
            
            if(res >= 2){
                pc('Y'), pc('E'), pc('S'), pc(10);
                break;
            }
        }
        
        if(res < 2)
            pc('N'), pc('O'), pc(10);
        
    }
    
    return 0;
}