#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+5;

char s[MM];
int n, a, b;
ll cnt[200], cnt2[200], best = 1e12;

ll sq(ll x){
    return x*x;
}

bool test(int m){
    //if possible to get all under m
    int sub = 0;
    for(int i = 0; i < 30; i++){
        if(cnt[i] > m)
            sub += cnt[i]-m;
    }
    //can rm
    return sub <= a;
}

int main(){
    
    scanf("%s", s);
    scanf("%d%d", &b, &a);
    //reeeeeeeeeeeeeeeeeeeee
    n = strlen(s);
    
    if(a+b >= n){
        print(0);
        return 0;
    }
    
    for(int i = b; i < n; i++){
        cnt[s[i]-'a']++;
    }
    
    for(int i = b-1; i < n; i++){
        
        if(i != b-1){
            cnt[s[i-b]-'a']++;
            cnt[s[i]-'a']--;
        }
        
        int l = 0, m, r = 1e5+1;
        while(l <= r){
            m = (l+r)/2;
            if(test(m))
                r = m-1;
            else
                l = m+1;
        }
        //first one possible is l
        //first subtract all > l, then with remaining, -1 if == l
        
        if(l < 0)
            l = 0;
        //?
        
        int rem = a;
        ll val = 0;
        for(int j = 0; j < 30; j++){
            cnt2[j] = cnt[j];
            if(cnt2[j] > l){
                rem -= cnt2[j]-l;
                cnt2[j] = l;
            }
        }
        assert(rem >= 0);
        for(int j = 0; j < 30; j++){
            if(rem > 0 && cnt2[j] == l){
                rem--;
                cnt2[j]--;
            }
            //val += sq(cnt2[j]);
        }
        //idk??
        for(int j = 0; j < 30; j++){
            if(rem > 0 && cnt2[j] == l-1){
                rem--;
                cnt2[j]--;
            }
            val += sq(cnt2[j]);
        }
        
        best = min(best, val);
    }
    
    print(best);
    
    return 0;
}