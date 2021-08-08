#include <bits/stdc++.h>

#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx2")

typedef long long T;
typedef long long ll;
constexpr int MM = 405;
constexpr ll mod = 998244353;
int SZ;

struct matrix{
	ll a[MM][MM];
	matrix(){
		memset(a, 0, sizeof a);
	}
};
struct vect{
	ll a[MM];
	vect(){
		memset(a, 0, sizeof a);
	}
};

int n, e, kk;
char s[50][50];

inline matrix mul(const matrix &ma, const matrix &mb){
	matrix c;	
	for(int i = 0; i < SZ; i++){
		int l = i-i%n;
		for(int j = l; j < SZ; j++){ //(cnt_j >= cnt_i)
			int r = j-j%n+n;
			for(int k = l; k < r; k++){ //(cnt_i <= cnt_k <= cnt_j)
				c.a[i][j] += ma.a[i][k]*mb.a[k][j]%mod;
			}
			c.a[i][j] %= mod;
		}
	}
	return c;
}

inline vect mul(const vect &va, const matrix &mb){
	vect vc;
	for(int i = 0; i < SZ; i++){
		for(int j = 0; j < SZ; j++){
			vc.a[i] += va.a[j]*mb.a[j][i]%mod;
		}
		vc.a[i] %= mod;
	}
	return vc;
}

inline vect fpow(matrix base, int exp){
	vect res;
	res.a[0] = 1;
    while(1){
        if(exp&1)
            res = mul(res, base);
        exp /= 2;
        if(!exp) break;
        base = mul(base, base);
    }
    return res;
}

inline matrix init(int nob, int noc){
	matrix a;
	for(int cnt = 0; cnt < 9; cnt++){
		for(int i = 0; i < n; i++){ //from
			int id = i+cnt*n;
			for(int j = 0; j < n; j++){ //to (and do)
				if(s[i][j] != '1') continue;
				if(nob and j == 1) continue;
				if(noc and j == 2) continue;
				int nx = j+cnt*n;
				if(j == 3){
					if(cnt < 8)
						a.a[id][nx+n] = 1;
				}
				else
					a.a[id][nx] = 1;
			}
		}
	}
	return a;
}

int main(){
	scanf("%d %d %d", &n, &e, &kk);
	SZ = n*kk+n;
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);

	int tar = kk*n + n-1;
	vect res = fpow(init(0, 0), e-1);
	ll ans = res.a[tar];
	
	res = fpow(init(1, 0), e-1);
	ans -= res.a[tar];

	res = fpow(init(0, 1), e-1);
	ans -= res.a[tar];

	res = fpow(init(1, 1), e-1);
	ans += res.a[tar];
	ans = (ans%mod+mod)%mod;

	printf("%lld\n", ans);
}