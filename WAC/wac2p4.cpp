#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ld = long double;
using pdd = pair<ld, ld>;
const ld eps = 1e-9;
vector<pdd> vec, temp;

ld sign(ld p1x, ld p1y, ld p2x, ld p2y, ld p3x, ld p3y){
    return (p1x-p3x) * (p2y-p3y) - (p2x-p3x) * (p1y-p3y);
}

bool inside(ld p1x, ld p1y, ld p2x, ld p2y, ld p3x, ld p3y, ld x, ld y){
    ld d1, d2, d3;
    bool has_neg, has_pos;
    
    d1 = sign(x,y,p1x,p1y,p2x,p2y);
    d2 = sign(x,y,p2x,p2y,p3x,p3y);
    d3 = sign(x,y,p3x,p3y,p1x,p1y);
    
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    
    return !(has_neg && has_pos);
}

bool valid(pdd PA, pdd PB, ld x, ld y){
    return min(PA.first, PB.first) <= x + eps && x <= max(PA.first, PB.first) + eps
           && min(PA.second, PB.second) <= y + eps && y <= max(PA.second, PB.second) + eps;
}

void check(pdd PA, pdd PB, pdd C, pdd D){
    ld a1 = PB.second - PA.second, b1 = PA.first - PB.first;
    ld c1 = a1*(PA.first) + b1*(PA.second);
    
    ld a2 = D.second - C.second, b2 = C.first - D.first;
    ld c2 = a2*(C.first)+ b2*(C.second);
    
    ld determinant = a1*b2 - a2*b1;
    
    if(determinant == 0)
        return;
    
    ld x = (b2*c1 - b1*c2)/determinant;
    ld y = (a1*c2 - a2*c1)/determinant;
    
    if(valid(PA, PB, x, y) && valid(C, D, x, y))
        temp.push_back({x, y});
}

ld shoelace(){
    int n = vec.size();
    
    ld ret = 0;
    int j = n-1;
    for(int i = 0; i < n; i++){
        ret += (vec[j].first + vec[i].first)*(vec[j].second - vec[i].second);
        j = i;
    }
    return abs(ret/2.0);
}

ld F(ld a, ld b, ld c){
    ld s = (a+b+c)/2.0;
    return sqrtl(s*(s-a)*(s-b)*(s-c));
}

ld LA[3], LB[3], INA[3], INB[3], ans;
pdd A[3], B[3];

ld run(ld xoff){
    
    bool flag = 0;
    
    B[0].first += xoff;
    B[1].first += xoff;
    B[2].first += xoff;
    
    //bc won't find B[1]
    if(inside(A[0].first, A[0].second, A[1].first, A[1].second, A[2].first, A[2].second, B[1].first, B[1].second)){
        flag = 1;
        swap(A, B);
    }
    
    vec.clear();
    //now add all intersections into vec
    
    //go one by one and sort
    check(A[2], A[1], B[0], B[2]);
    check(A[2], A[1], B[2], B[1]);
    check(A[2], A[1], B[1], B[0]);
    
    //do direction as well
    if(A[1].first > A[2].first)
        sort(temp.begin(), temp.end());
    else sort(temp.begin(), temp.end(), greater<pdd>());
    
    vec.insert(vec.end(), temp.begin(), temp.end());
    temp.clear();
    
    if(inside(B[0].first, B[0].second, B[1].first, B[1].second, B[2].first, B[2].second, A[1].first, A[1].second))
        vec.push_back(A[1]);
    
    check(A[1], A[0], B[2], B[1]);
    check(A[1], A[0], B[1], B[0]);
    check(A[1], A[0], B[0], B[2]);
    
    if(A[0].first > A[1].first)
        sort(temp.begin(), temp.end());
    else sort(temp.begin(), temp.end(), greater<pdd>());
    vec.insert(vec.end(), temp.begin(), temp.end());
    temp.clear();
    
    check(A[0], A[2], B[1], B[0]);
    check(A[0], A[2], B[0], B[2]);
    check(A[0], A[2], B[2], B[1]);
    
    sort(temp.begin(), temp.end());
    vec.insert(vec.end(), temp.begin(), temp.end());
    temp.clear();
    
    ld v = shoelace();
    ans = max(ans, v);
    
    if(flag)
        swap(A, B);
    
    B[0].first -= xoff;
    B[1].first -= xoff;
    B[2].first -= xoff;
    
    return v;
}

int main(){

    for(int i = 0; i < 3; i++)
        cin >> LA[i];
    for(int i = 0; i < 3; i++)
        cin >> LB[i];
    
    sort(LA, LA+3);
    sort(LB, LB+3);
    
    for(int i = 0; i < 3; i++)
        INA[i] = LA[i], INB[i] = LB[i];
    
    do{
        do{
            A[0] = {0, 0};
            A[2] = {LA[2], 0};
            ld theta = (LA[2]*LA[2] + LA[1]*LA[1] - LA[0]*LA[0])/(2.0*LA[2]*LA[1]);
            ld h = LA[1]*sqrtl(1-theta*theta);
            ld x = LA[1]*theta;
            A[1] = {x, h};
            
            B[0] = {0, 0};
            B[2] = {LB[2], 0};
            theta = (LB[2]*LB[2] + LB[1]*LB[1] - LB[0]*LB[0])/(2.0*LB[2]*LB[1]);
            h = LB[1]*sqrtl(1-theta*theta);
            x = LB[1]*theta;
            B[1] = {x, h};
            
            ld l = -B[2].first, r = A[2].first;
            while(r-l > eps){
                ld m1 = l+(r-l)/3, m2 = r-(r-l)/3;
                ld f1 = run(m1), f2 = run(m2);
                if(f1 < f2)
                    l = m1;
                else
                    r = m2;
            }
            
        } while(next_permutation(LB, LB+3));
    } while(next_permutation(LA, LA+3));
    
    printf("%.10Lf\n", F(LA[0], LA[1], LA[2]) + F(LB[0], LB[1], LB[2]) - ans);
    
    return 0;
}