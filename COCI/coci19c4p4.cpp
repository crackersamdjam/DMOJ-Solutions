#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5;

int n, a[MM], b[MM], id[MM], nx = 1;
string op[MM];
int in[MM], out[MM], val[MM], t;
vector<pair<int, int>> adj[MM];

struct node{
	node(int d){
		dep = d;
	}
	int dep;
	node *ch[2];
	set<int> st;
};

void dfs(int cur){
	in[cur] = ++t;
	for(auto e: adj[cur]){
		int u = e.first;
		val[u] = val[cur]^e.second;
		dfs(u);
	}
	out[cur] = t;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>op[i]>>a[i]>>b[i];
		if(op[i] == "Add"){
			id[i] = ++nx;
			adj[a[i]].emplace_back(nx, b[i]);
		}
	}
	op[0] = "Add";
	a[0] = 1;
	b[0] = 0;
	id[0] = 1;
	
	dfs(1);
	node *rt = new node(31);
	for(int i = 0; i <= n; i++){
		node *cur = rt;
		if(op[i] == "Add"){
			int def = val[id[i]];
			while(1){
				cur->st.insert(in[id[i]]);
				if(cur->dep < 0)
					break;
				int v = (def>>cur->dep)&1; //has or not
				if(!cur->ch[v])
					cur->ch[v] = new node(cur->dep-1);
				cur = cur->ch[v];
			}
		}
		else{
			int ans = val[a[i]];
			int lo = in[b[i]], hi = out[b[i]];
			
			while(1){
				int v = (ans>>cur->dep)&1^1; //want the opposite
				
				int can = cur->ch[v] != nullptr;
				if(can){
					auto it = cur->ch[v]->st.lower_bound(lo);
					if(it != cur->ch[v]->st.end() and *it <= hi){
						//good
					}
					else{
						//bad
						can = 0;
					}
				}
				if(!can) //can not do wanted
					v ^= 1;

				if(v)
					ans ^= (1<<cur->dep);

				if(cur->dep == 0)
					break;
				cur = cur->ch[v];
			}

			cout<<ans<<'\n';
		}
	}
}