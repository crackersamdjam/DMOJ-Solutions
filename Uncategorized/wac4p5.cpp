#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int MM = 1e5+5;

template <class T> struct persistent_heap{
    struct node {
        T x, delta;
        node *l, *r;
    } *root;
    persistent_heap(): root(0){}
    
    node *copy(node *a, T v){
        node *b = new node({a->x, a->delta + v, a->l, a->r});
        return b;
    }
    void propagate(node *a){
        a->x += a->delta;
        if(a->l) a->l = copy(a->l, a->delta);
        if(a->r) a->r = copy(a->r, a->delta);
        a->delta = 0;
    }
    node *merge(node *a, node *b) {
        if (!a || !b) return a ? a : b;
        a = copy(a, 0);
        b = copy(b, 0);
        propagate(a); propagate(b);
        if (a->x < b->x) swap(a, b);
        if (rand() % 2) return new node({a->x, a->delta, merge(a->l, b), a->r});
        else            return new node({a->x, a->delta, a->l, merge(a->r, b)});
    }
    node *merge(persistent_heap b){
        root = merge(root, b.root);
        return root;
    }
    void push(T x) {
        root = merge(root, new node({x}));
    }
    bool empty() {
        return !root;
    }
    void pop(){
        root = copy(root, 0);
        propagate(root);
        root = merge(root->l, root->r);
    }
    T top(){
        root = copy(root, 0);
        propagate(root);
        return root->x;
    }
    void add(ll delta){
        if(root)
            root = copy(root, delta);
    }
};

template <class T> struct persistent_array{
    struct node{
        int k;
        T x;
        node *l, *r;
    } *root;
    persistent_array(int n, T x = T()){
        function<node* (int, int)> r = [&](int i, int j){
            if (i  > j) return (node *)0;
            if (i == j) return new node({i, x});
            int m = (i + j) / 2;
            return new node({m, x, r(i,m-1), r(m+1,j)});
        };
        root = r(0, n-1);
    }
    T& get(int k){
        for (node *t = root; ;){
            if      (t->k < k) t = t->r;
            else if (t->k > k) t = t->l;
            else return t->x;
        }
    }
    const T& set(int k, const T &x){
        function<node* (node*)> r = [&](node *t){
            if (!t || t->k == k) return new node({k, x, t->l, t->r});
            if (t->k < k) return new node({t->k, t->x, t->l, r(t->r)});
            else          return new node({t->k, t->x, r(t->l), t->r});
        };
        root = r(root);
        return x;
    }
    
    pii find(int x){
        if(x == get(x).first)
            return get(x);
        set(x, find(get(x).first));
        return get(x);
    }
};

vector<persistent_array<pii>> ptr;
vector<persistent_heap<ll>> all;

int n, q, nx;
ll in[MM], last;

int main(){
    scan(n, q);
    
    ptr.emplace_back(n+1);
    
    for(int i = 1; i <= n; i++){
        scan(in[i]);
        all.emplace_back();
        all[nx].push(in[i]);
        ptr[0].set(i, {i, nx++});
    }
    
    for(int i = 1,op; i <= q; i++){
        ll j, a, b;
        scan(op, j, a);
        j ^= last, a ^= last;
        ptr.push_back(ptr[j]);
        
        if(op == 1){
            scan(b);
            b ^= last;
            pii pa = ptr[i].find(a), pb = ptr[i].find(b);
            a = pa.first, b = pb.first;
            if(a != b){
                ptr[i].set(pb.first, pa);
                
                auto tmp = all[pa.second], tmp2 = all[pb.second];
                tmp.merge(tmp2);
                all.emplace_back(tmp);
                ptr[i].set(a, {a, nx});
                nx++;
            }
        }
        if(op == 2){
            pii pa = ptr[i].find(a);
            a = pa.first;
            
            if(all[pa.second].empty()){
                last = 0;
                print(0);
                continue;
            }
            last = all[pa.second].top();
    
            auto tmp = all[pa.second];
            tmp.pop();
            tmp.push(0);
            print(last);
            all.emplace_back(tmp);
            ptr[i].set(a, {a, nx});
            nx++;
        }
        if(op == 3){
            scan(b);
            b ^= last;
            pii pa = ptr[i].find(a);
            a = pa.first;
            auto tmp = all[pa.second];
            tmp.add(b);
            all.emplace_back(tmp);
            ptr[i].set(a, {a, nx});
            nx++;
        }
    }
    
    
    return 0;
}