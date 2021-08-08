#include <bits/stdc++.h>
using namespace std;

#define forall for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

int ina[3][3], inb[3][3], a[3][3], b[3][3], cnt, cntr[3], cntc[3];

void run(){
    again:;
    bool f = 0;
    for(int i = 0; i < 3; i++){
        if(b[i][0] && b[i][1] && !b[i][2]){
            a[i][2] = a[i][1]*2 - a[i][0];
            b[i][2] = 1;
            f = 1;
        }
        if(!b[i][0] && b[i][1] && b[i][2]){
            a[i][0] = a[i][1]*2 - a[i][2];
            b[i][0] = 1;
            f = 1;
        }
        if(b[i][0] && !b[i][1] && b[i][2]){
            a[i][1] = (a[i][0] + a[i][2])/2;
            b[i][1] = 1;
            f = 1;
        }

        if(b[0][i] && b[1][i] && !b[2][i]){
            a[2][i] = a[1][i]*2 - a[0][i];
            b[2][i] = 1;
            f = 1;
        }
        if(!b[0][i] && b[1][i] && b[2][i]){
            a[0][i] = a[1][i]*2 - a[2][i];
            b[0][i] = 1;
            f = 1;
        }
        if(b[0][i] && !b[1][i] && b[2][i]){
            a[1][i] = (a[0][i] + a[2][i])/2;
            b[1][i] = 1;
            f = 1;
        }
    }

    if(f) goto again;
}

bool check(){
    for(int i = 0; i < 3; i++){
        if(a[i][0] + a[i][2] != a[i][1]*2 || a[0][i] + a[2][i] != a[1][i]*2)
            return 0;
    }
    return 1;
}

void reset(){
    forall
        a[i][j] = ina[i][j], b[i][j] = inb[i][j];
}

void out(){
    //assert(check());
    for(int i = 0; i < 3; i++)
        cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << '\n';
}

int main(){
    init();

    forall{
        string  s;
        cin >> s;
        if(s != "X"){
            a[i][j] = stoi(s);
            b[i][j] = 1;
        }
    }

    run();

    forall{
        cnt += b[i][j];
        ina[i][j] = a[i][j];
        inb[i][j] = b[i][j];
    }

    if(cnt == 0){
        return out(), 0;
    }
    else if(cnt == 1){
        int v = -1;
        forall
            if(b[i][j])
                v = a[i][j];
        forall
            a[i][j] = v;
        return out(), 0;
    }
    else if(cnt < 5){
        forall
            if(b[i][j])
                cntr[i]++, cntc[j]++;

        //do row
        for(int i = 0; i < 3; i++){
            int v, f = 0;
            for(int j = 0; j < 3; j++)
                if(b[i][j])
                    v = a[i][j], f = 1;
            if(f)
                for(int j = 0; j < 3; j++)
                    a[i][j] = v, b[i][j] = 1;
        }
        run();
        if(check())
            return out(), 0;

        reset();
        
        //do col
         for(int j = 0; j < 3; j++){
            int v, f = 0;
            for(int i = 0; i < 3; i++)
                if(b[i][j])
                    v = a[i][j], f = 1;
            if(f)
                for(int i = 0; i < 3; i++)
                    a[i][j] = v, b[i][j] = 1;
        }
        
        run();
        if(check())
            return out(), 0;
        reset();
    }
    if(cnt < 9){
        int x = -1, y;
        forall
            if(!b[i][j])
                x = i, y = j;

        assert(~x);

        for(int v = -4e6; v <= 4e6; v++){
            reset();
            a[x][y] = v;
            b[x][y] = 1;
            run();
            if(check())
                return out(), 0;
        }
    }
    else{
        //all done
        out();
    }
    
    return 0;
}