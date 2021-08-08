#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
using pil = pair<int, ll>;
using pii = pair<int, int>;
constexpr int MM = 1e6+1;

struct dq{
	int f[MM*2]; ll s[MM*2]; int l = 0, r = -1;
	
	void clear(){
		l = 0, r = -1;
	}
	pil front(){
		return {f[l], s[l]};
	}
	pil back(){
		return {f[r], s[r]};
	}
	int size(){
		return r-l+1;
	}
	void emplace_back(int a, ll b){
		f[++r] = a;
		s[r] = b;
	}
	void pop_front(){
		l++;
	}
	void pop_back(){
		r--;
	}
} q;

int rs, m;
pii v[MM];

int n;
ll ans;
// ll dep[MM];
char vis[MM];
bitset<MM> on;
int w[MM];
int to[MM];
int adj[MM*2], last[MM*2], head[MM];

int J[MM];
#define j J[cur]

bool done;

void dfs1(int cur, int p){
	// pr("dfs", cur, p);
	if(!done) v[rs] = {cur, p};
	rs++;

	vis[cur] = 1;
	// for(int id: adj[cur]){
	for(j = head[cur]; j; j = last[j]){
		// int id = adj[j];
		#define id adj[j]
		// pr(cur, j, ",", id, to[id], w[id]);

		if(id == p) continue;
		// int u = id == cur ? to[id] : id;
		#define u ((id == cur) ? to[id] : id)

		if(vis[u] == 1){
			assert(!m);
			//found cycle
			int l;
			for(l = rs-1; v[l].first != u; l--){
				// v[m++] = ins[i];
				on[v[l].first] = 1;
			}
			// v.emplace_back(u, id);
			// v[m++] = {u, id};
			// l--;
			m = rs-l;
			for(int i = 0; i < m; i++){
				v[i] = v[i+l];
			}
			// pr(l, rs-1, m);
			assert(m);
			v[0] = {u, id};

			on[u] = 1;
			done = 1;
		}
		else if(!vis[u]){
			dfs1(u, id);
		}
	}
	j = head[cur]; //reset for next time
	rs--;
	vis[cur] = 2;
}

//get furthest
pair<ll, int> mx;
ll d;

void dfs2(int cur, int p){
	mx = max(mx, {d, cur});
	// for(int id: adj[cur]){
	for(j = head[cur]; j; j = last[j]){
		// int id = adj[j];
		#define id adj[j]

		// int u = id == cur ? to[id] : id;
		#define u ((id == cur) ? to[id] : id)

		if(id != p and !on[u]){
			d += w[id];
			dfs2(u, id);
			d -= w[id];
		}
	}
	j = head[cur]; //reset for next time
}
#undef id
#undef u

int main(){
	scan(n);
	int t = 0;
	for(int i = 1,a; i <= n; i++){
		t++;
		scan(a, w[i]);
		to[i] = a;

		last[t] = head[i];
		head[i] = t;
		adj[t] = i;

		t++;
		last[t] = head[a];
		head[a] = t;
		adj[t] = i;
		// print(i, a, w[i]);
	}

	for(int st = 1; st <= n; st++){
		if(!vis[st]){
			// pr("st", st);
			// v.clear();
			m = 0;
			done = 0;
			dfs1(st, 0);
			// reverse(all(v)); //inseted in reverse order
			// reverse(v, v+m);
			// v.insert(v.end(), all(v));
			ll val = 0; //current comp's best val

			// pr("m", m);

			if(m){
				for(int z = 0; z < 2; z++){
					q.clear();
					q.emplace_back(-1, LLONG_MIN/3);
					ll len = 0;
					// pr("--------");
					for(int i = 0; i < m*2; i++){
						auto [a, id] = v[i%m];
						// pr("a", a, id, w[id]);

						mx = {0, 0};
						dfs2(a, 0);
						ll dep = mx.first;

						if(!z){
							//completely within this subtree
							int ed = mx.second;
							// pr("ed", ed);
							on[a] = 0;
							mx = {0, 0};
							if(ed) dfs2(ed, 0);
							on[a] = 1;
							val = max(val, mx.first);
							// pr("in", mx.first, mx.second);
						}

						if(i){
							len += w[id];
						}
		
						//dep is depth of this subtree
						while(q.front().first <= i-m)
							q.pop_front();
						// ll cur = q.front().second + dep[a] + len;
						ll cur = q.front().second + dep + len;
						val = max(val, cur);
						// pr(i, a, ",", dep[a], len, "cur", cur, "ree", q.front().first, q.front().second);

						// cur = dep[a]-len;
						cur = dep-len;
						// pr("ins", a, cur);
						while(q.size() and q.back().second <= cur)
							q.pop_back();
						q.emplace_back(i, cur);
					}

					if(!z){
						int a0 = v[0].second;
						for(int i = 0; i < m; i++)
							v[i].second = v[i+1].second;
						// v.back().second = a0;
						// reverse(all(v));
						v[m-1].second = a0;
						reverse(v, v+m);
					}
				}
				// pr("val", val);
				ans += val;
			}
			else{
				mx = {0, 0};
				dfs2(st, 0);
				mx = {0, 0};
				dfs2(mx.second, 0);
				ans += mx.first;
			}
		}
	}

	print(ans);
}