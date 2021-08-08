#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5+1;

int N, K, dp[MM];

struct task{
    
    int l, r;
    task(){};
    task(int ll, int rr): l(ll), r(rr){}
    friend bool operator<(const task &x, const task &y){
        if(x.l == y.l)
            return x.r < y.r;
        return x.l < y.l;
    }
}
tasks[MM];

vector<task> init;

int main(){
    
    scan(N, K);
    
    for(int i = 0; i < N; i++){
        scan(tasks[i].l, tasks[i].r);
    }
    
    sort(tasks, tasks+N);
    
    init.push_back(tasks[0]);
    
    for(int i = 1; i < N; i++){
        if(tasks[i].l > init.back().r)
            init.push_back(tasks[i]);
    }
    
    for(int i = 0,l,r; i < init.size(); i++){
        
        //printf("i %d\n", i);
        if(i == 0 && init.size() == 1)
            l = -1, r = INT_MAX;
        else if(i == 0)
            l = -1, r = init[i+1].l;
        else if(i == init.size()-1)
            l = init[i-1].r + 1, r = INT_MAX;
        else
            l = init[i-1].r + 1, r = init[i+1].l;
    
        auto st = lower_bound(tasks, tasks+N, task(l,l));
        
        //printf("st %d\n", st - tasks);
        //printf("%d %d\n", st->l, st->r);
        //printf("l r %d %d\n", l, r);
        
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(int j = st-tasks; j < N; j++){
            //printf("push %d %d\n", tasks[j].l, tasks[j].r);
            if(tasks[j].l >= r){
                //puts("br");
                break;
            }
            if(tasks[j].r >= r){
                //puts("cont");
                continue;
            }
            q.push({tasks[j].r, tasks[j].l});
        }
        
        while(!q.empty()){
            int sl = q.top().second, sr = q.top().first; q.pop();
            if(sl >= l && sr < r){
                //printf("add %d %d\n", sl, sr);
                dp[i]++;
                l = sr+1;
            }
        }
        
        /*
        auto nx = lower_bound(tasks, tasks+N, task(l,l));
        while(nx->r < r){
            
            dp[i]++;
            l = nx->r + 1;
            if(nx-tasks == N-1)
                break;
            
            nx = lower_bound(tasks, tasks+N, task(l,l));
        }
        */
        dp[i]--;
        //removed one
    }
    
    if(K == 1){
        int ans = 0;
        for(int i = 0; i < init.size(); i++)
            ans = max(ans, dp[i]);
        
        print(ans + init.size());
        
        return 0;
    }
    
    //puts("fuck k = 2");
    
    int fst = 0, sec = 0;
    for(int i = 0; i < init.size(); i++){
        if(dp[i] > fst){
            sec = fst;
            fst = dp[i];
        }
        else if(dp[i] > sec)
            sec = dp[i];
    }
    
    int ans = fst + sec;
    
    //now try contiguous
    
    for(int i = 0,l,r; i < init.size()-1; i++){
        dp[i] = 0;
    
        if(i == 0 && init.size() == 2)
            l = -1, r = INT_MAX;
        else if(i == 0)
            l = -1, r = init[i+2].l;
        else if(i == init.size()-2)
            l = init[i-1].r + 1, r = INT_MAX;
        else
            l = init[i-1].r + 1, r = init[i+2].l;
    
        auto st = lower_bound(tasks, tasks+N, task(l,l));
    
        //printf("st %d\n", st - tasks);
        //printf("%d %d\n", st->l, st->r);
        //printf("l r %d %d\n", l, r);
    
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(int j = st-tasks; j < N; j++){
            //printf("push %d %d\n", tasks[j].l, tasks[j].r);
            if(tasks[j].l >= r){
                //puts("br");
                break;
            }
            if(tasks[j].r >= r){
                //puts("cont");
                continue;
            }
            q.push({tasks[j].r, tasks[j].l});
        }
    
        while(!q.empty()){
            int sl = q.top().second, sr = q.top().first; q.pop();
            if(sl >= l && sr < r){
                //printf("add %d %d\n", sl, sr);
                dp[i]++;
                l = sr+1;
            }
        }
        
        /*
        auto nx = lower_bound(tasks, tasks+N, task(l,l));
        while(nx->r < r){
            
            //printf("nx %d %d %d\n", nx-tasks, nx->l, nx->r);
            
            dp[i]++;
            l = nx->r + 1;
            if(nx-tasks == N-1)
                break;
            
            nx = lower_bound(tasks, tasks+N, task(l,l));
        }
         */
        
        dp[i] -= 2;
        //removed two
        //printf("dp %d %d\n", i, dp[i]);
    }
    
    for(int i = 0; i < init.size()-1; i++)
        ans = max(ans, dp[i]);
    
    print(ans + init.size());
    
    return 0;
}
/*
 * select start and end by bs
 * sort by ending
 *
 * or just loop through
 */