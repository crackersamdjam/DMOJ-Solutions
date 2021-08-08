using ll = long long;

ll g(ll n){
    ll r = 0;
    while(n){
        r += (n % 10) * (n % 10);
        n /= 10;
    }
    return r;
}

bool f(int n0){
    ll n = n0, m = n;
    do{
        n = g(n), m = g(g(m));
    } while(m^n);
    return n == 1;
}