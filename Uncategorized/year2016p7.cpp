#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 2e5+5;

int n, k, q, a[MM], leftend[MM], rightend[MM];
deque<pii> minq, maxq;
pii sp[20][MM];

pii query(int l, int r){
    int k = 31-__builtin_clz(r-l+1);
    return max(sp[k][l], sp[k][r-(1<<k)+1]);
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    
    scan(n, k);

    for(int i = 1; i <= n; i++){
    	scan(a[i]);
    	leftend[i] = 1;
    	rightend[i] = n;
    }
    
    int l = 1, r = 1;
    for(; r <= n; r++){
    	while(!maxq.empty() && a[r] > maxq.back().second)
                maxq.pop_back();
        while(!minq.empty() && a[r] < minq.back().second)
            minq.pop_back();

		maxq.push_back({r, a[r]});
        minq.push_back({r, a[r]});

        while(l < r && maxq.front().second - minq.front().second > k){
        	rightend[l] = r-1;
        	l++;
        	while(!maxq.empty() && maxq.front().first < l)
                maxq.pop_front();
            while(!minq.empty() && minq.front().first < l)
                minq.pop_front();
        }

        leftend[r] = l;
    }

    for(int i = 1; i <= n; i++)
    	sp[0][i] = {rightend[i]-i+1, -rightend[i]};

	for(int i = 1; i < 20; i++){
        for(int j = 1; j+(1<<i) <= n+2; j++){
            sp[i][j] = max(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
        }
    }

    scan(q);

    for(int i = 0,l,r; i < q; i++){
    	scan(l, r);
    	int k = leftend[r];
    	if(k <= l){
    		print(l, r);
    		continue;
    	}
    	pii ans = max(query(l, k-1), {r-k+1, -r});
    	print(-ans.second-ans.first+1, -ans.second);
    }

    return 0;
}