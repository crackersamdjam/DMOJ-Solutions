//smh
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;

class BigInteger {
private:
    string integer;
public:
    BigInteger(unsigned int integer);
    BigInteger(string integer);
    void setInteger(unsigned int integer);
    void setInteger(string integer);
    unsigned int getIntValue() const;
    string toString() const;
    BigInteger addInteger(const BigInteger& integer_to_add) const;
    BigInteger addInteger(const string& integer_to_add) const;
    BigInteger multiplyInteger(const BigInteger& integer_to_multiply) const;
    BigInteger multiplyInteger(const string& integer_to_multiply) const;
    static size_t getTrimIndex(const string& integer);
    bool operator==(const BigInteger& integer) const;
    BigInteger operator+(const BigInteger& integer) const;
    BigInteger operator*(const BigInteger& integer) const;
    friend ostream& operator<<(ostream& in, BigInteger& integer);
};

vector<BigInteger> f;

int main(){
    
    f.push_back(BigInteger("0"));
    f.push_back(BigInteger("1"));
    for(int i = 2; i <= 200; i++){
        BigInteger c = f[i-1] + f[i-2];
        f.push_back(c);
    }
    
    while(1){
        int n;
        scan(n);
        if(!n)
            break;
        cout << f[n] << '\n';
    }
    
    // INSERT YOUR CODE HERE
    
    /* This is a sample code that demonstrates how to use the
     * Big Integer arithmetic library.
     *
     * BigInteger a("35742549198872617291353508656626642567");
     * BigInteger b("1298074214633706835075030044377087");
     *
     * BigInteger c = a + b;
     * BigInteger d = a * b;
     *
     * cout << a << " + " << b << " = " << c << endl;
     * cout << a << " * " << b << " = " << d << endl;
     */
    
    return 0;
}

BigInteger::BigInteger(unsigned int integer) {
    setInteger(integer);
}

BigInteger::BigInteger(string integer) {
    for (int i = 0; i < (int)integer.size() && integer[i] >= '0' && integer[i] <= '9'; i++) {
        this->integer += integer[i];
    }
    
    if (this->integer.size() == 0) {
        this->integer = "0";
    } else {
        this->integer = integer.substr(getTrimIndex(integer));
    }
}

void BigInteger::setInteger(unsigned int integer) {
    if (integer == 0) this->integer = "0";
    
    while (integer) {
        this->integer = (char)((integer % 10) + '0') + this->integer;
        integer /= 10;
    }
}

void BigInteger::setInteger(string integer) {
    this->integer = integer;
}

unsigned int BigInteger::getIntValue() const {
    unsigned int ret = 0;
    unsigned int biggest = 0xFFFFFFFF;
    for (int i = 0; i < (int)integer.size(); i++) {
        int unit = integer[i] - '0';
        if (ret > (biggest - unit) / 10.0) return 0;
        ret = ret * 10 + unit;
    }
    return ret;
}

string BigInteger::toString() const {
    return integer;
}

BigInteger BigInteger::addInteger(const BigInteger& integer_to_add) const {
    int a_n = max((int)(integer_to_add.toString().size() - toString().size()), 0);
    int b_n = max((int)(toString().size() - integer_to_add.toString().size()), 0);
    string a = string(a_n, '0') + toString();
    string b = string(b_n, '0') + integer_to_add.toString();
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string result; int carry = 0;
    
    for (int i = 0; i < (int)a.size(); i++) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result += ((char)(sum % 10 + '0'));
        carry = sum / 10;
    }
    
    if (carry != 0) result += ((char)(carry + '0'));
    
    reverse(result.begin(), result.end());
    
    return BigInteger(result.substr(getTrimIndex(result)));
}

BigInteger BigInteger::addInteger(const string& integer_to_add) const {
    return addInteger(BigInteger(integer_to_add));
}

BigInteger BigInteger::multiplyInteger(const BigInteger& integer_to_multiply) const {
    string a = integer_to_multiply.toString();
    string b = toString();
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    BigInteger ret("0");
    
    for (int i = 0; i < (int)a.size(); i++) {
        int carry = 0; string tmp = string(i, '0');
        
        for (int j = 0; j < (int)b.size(); j++) {
            int mul = (a[i] - '0') * (b[j] - '0') + carry;
            tmp += ((char)(mul % 10 + '0'));
            carry = mul / 10;
        }
        
        if (carry != 0) tmp += (carry + '0');
        
        reverse(tmp.begin(), tmp.end());
        
        ret = ret.addInteger(tmp.substr(getTrimIndex(tmp)));
    }
    
    return ret;
}

BigInteger BigInteger::multiplyInteger(const string& integer_to_multiply) const {
    return multiplyInteger(BigInteger(integer_to_multiply));
}

size_t BigInteger::getTrimIndex(const string& integer) {
    size_t index = 0;
    while (integer[index] == '0' && index < integer.size() - 1) index++;
    return index;
}

bool BigInteger::operator==(const BigInteger& integer) const {
    return this->integer == integer.toString();
}

BigInteger BigInteger::operator+(const BigInteger& integer) const {
    return addInteger(integer);
}

BigInteger BigInteger::operator*(const BigInteger& integer) const {
    return multiplyInteger(integer);
}

ostream& operator<<(ostream& in, BigInteger& integer) {
    in << integer.toString();
    
    return in;
}