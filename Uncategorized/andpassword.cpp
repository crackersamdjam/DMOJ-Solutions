#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
using namespace std;
const int MM = 2100;

mt19937 g(chrono::steady_clock::now().time_since_epoch().count());
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g);}

int n, k, v[MM], out[MM], hi[MM];
vector<int> val[MM];
int cache[MM][MM];

int ask(int a, int b, bool lim){
	
	if(a > b)
		swap(a, b);
	if(cache[a][b])
		return cache[a][b];
	
	cout<<"? "<<a<<' '<<b<<endl;
	int x;
	cin>>x;
	assert(~x);
	if(x > k)
		hi[a] = hi[b] = 1;
	return cache[a][b] = (lim ? (x&k) : x);
}

int main(){
	cin>>n;
	int l = __lg(n+1);
	k = (1<<l)-1;
	
	for(int i = 1; i <= n; i++)
		v[i] = i;
	shuffle(v+1, v+1+n, g);
	
	int a = v[1], b = v[2], z = 0, ab = ask(a, b, 1);
	
	for(int i = 3; i <= n; i++){
		int c = v[i];
		int bc = ask(b, c, 1);
		
		if(bc < ab){
			//does not have same bits
			continue;
		}
		else if(bc > ab){
			a = c;
			ab = bc;
			
			//now it is (z, c, b)
			//if z, check if keep or go
			if(z){
				int za = ask(z, a, 1);
				if(za > ab){
					ab = za;
					b = z;
					z = 0;
				}
				else
					z = 0;
			}
		}
		else{
			//has same bits
			int ac = ask(a, c, 1);
			if(ac > ab){
				b = c;
				ab = ac;
				//now it is (z, a, c)
				if(z){
					int zb = ask(z, b, 1);
					if(zb > ab){
						ab = zb;
						a = z;
						z = 0;
					}
					else
						z = 0;
				}
			}
			else{
				//now it is (z, a, b)
				//ac and bc same
				if(z){
					int zc = ask(z, c, 1);
					if(zc > ac){
						ab = zc;
						a = z;
						b = c;
						z = 0;
					}
					else
						z = 0;
				}
				else
					z = c;
			}
		}
	}
	
	int id = 0, kk = 0; // id is k (2^m-1), kk is k+1 (if exists)
	
	while(1){
		
		int c = v[randint(1, n)];
		if(c == z or c == a or c == b){
			continue;
		}
		
		int ac = ask(a, c, 1), bc = ask(b, c, 1), zc = 0;
		if(z){
			zc = ask(z, c, 1);
			if(zc > ac){
				ac = zc;
				a = z;
			}
			else if(zc > bc){
				bc = zc;
				b = z;
			}
		}
		
		if(ac == bc)
			continue;
		id = ac > bc ? a : b;
		break;
	}
	
	for(int i = 1; i <= n; i++){
		int c = v[i];
		if(c == id)
			out[c] = k;
		else
			out[c] = ask(c, id, 1);
		
		if(!out[c]){
			out[c] = k+1;
			kk = c;
		}
		val[out[c]].emplace_back(c);
	}
	
	if(kk){
		for(int i = 1; i <= k; i++){
			if(val[i].size() < 2)
				break;
			int c = val[i][0], cc = val[i][1];
			if(hi[c])
				out[c] |= (k+1);
			else if(hi[cc])
				out[cc] |= (k+1);
			else if(ask(kk, c, 0) > k)
				out[c] |= (k+1);
			else
				out[cc] |= (k+1);
		}
	}
	
	cout<<"!";
	for(int i = 1; i <= n; i++)
		cout<<' '<<out[i];
	cout<<endl;
}