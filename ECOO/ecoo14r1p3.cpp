#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;

int R, C, M, tc = 5;
char arr[100][100];
bool done[100][100];
string str, down, rs, dia, dia2;

int main(){
    
    while(tc--){
        
        memset(arr, '.', sizeof arr);
        memset(done, 0, sizeof done);
        
        scan(R, C);
        
        for(int i = 0; i < R; i++)
            scanf("%s", arr[i]);
        
        scan(M);
        for(int t = 0; t < M; t++){
            getline(cin, str);
            str.erase(remove_if(str.begin(), str.end(), [](char c) { return !isalpha(c); } ), str.end());
            
            for(int i = 0; i < R; i++){
                for(int j = 0; j < C; j++){
                    
                    down = "";
                    rs = "";
                    dia = "";
                    dia2 = "";
                    
                    for(int k = 0; k < str.size(); k++){
                        down += arr[i+k][j];
                        rs += arr[i][j+k];
                        dia += arr[i+k][j+k];
                        dia2 += arr[i+str.size()-1-k][j+k];
                    }
                    
                    string rev = down;
                    reverse(rev.begin(), rev.end());
                    if(down == str || rev == str){
                        for(int k = 0; k < str.size(); k++)
                            done[i+k][j] = 1;
                    }
                    
                    rev = rs;
                    reverse(rev.begin(), rev.end());
                    if(rs == str || rev == str){
                        for(int k = 0; k < str.size(); k++)
                            done[i][j+k] = 1;
                    }
                    
                    rev = dia;
                    reverse(rev.begin(), rev.end());
                    if(dia == str || rev == str){
                        for(int k = 0; k < str.size(); k++)
                            done[i+k][j+k] = 1;
                    }
    
                    rev = dia2;
                    reverse(rev.begin(), rev.end());
                    if(dia2 == str || rev == str){
                        for(int k = 0; k < str.size(); k++)
                            done[i+str.size()-1-k][j+k] = 1;
                    }
                }
            }
        }
        string out = "";
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(!done[i][j])
                    out += arr[i][j];
            }
        }
        cout << out << '\n';
    }
    
    return 0;
}