#include <bits/stdc++.h>
using namespace std;
int N,carry,neg1,neg2,negans;
string str,str1,str2;
void addPos(){
    if(str1.length() > str2.length())
        swap(str1, str2);
    int n = str1.length(), m = str2.length();
    int dif = n-m;
    for(int i = n-1; i >= 0; i--){
        int temp = str1[i]-'0' + str2[i-dif]-'0' + carry;
        str.push_back(temp%10+'0');
        carry = temp/10;
    }
    for(int i = m-n-1; i >= 0; i--){
        int temp = str2[i]-'0' + carry;
        str.push_back(temp%10 + '0');
        carry = temp/10;
    }
    if(carry)
        str.push_back(carry+'0');
    for(int i = str.length()-1; i >= 0; i--)
        cout << str[i];
    cout << '\n';
}
void addNeg(){
    if(str1.length() > str2.length())
        swap(str1, str2);
    int n = str1.length(), m = str2.length();
    int dif = n-m;
    for(int i = n-1; i > 0; i--){
        int temp = str1[i]-'0' + str2[i-dif]-'0' + carry;
        str.push_back(temp%10+'0');
        carry = temp/10;
    }
    for(int i = m-n; i > 0; i--){
        int temp = str2[i]-'0' + carry;
        str.push_back(temp%10 + '0');
        carry = temp/10;
    }
    if(carry)
        str.push_back(carry+'0');
    cout << '-';
    for(int i = str.length()-1; i >= 0; i--)
        cout << str[i];
    cout << '\n';
}
bool func(){ //true if str1 is smaller
    int n1 = str1.length(), n2 = str2.length();
    if(n1 < n2)
        return 1;
    if(n2 < n1)
        return 0;
    for(int i=0; i<n1; i++)
        if(str1[i] < str2[i])
            return 1;
        else if(str1[i] > str2[i])
            return 0;
    return 0;
}
void sub(){
    int n = str1.length(), m = str2.length();
    int dif = n-m;
    for(int i = m-1; i >= 0; i--){
        int temp = (int)(str1[i+dif]-'0') - (int)(str2[i]-'0') - carry;
        if(temp < 0){
            temp += 10;
            carry = 1;
        }else
            carry = 0;
        str.push_back(temp+'0');
    }
    for(int i = n-m-1; i >= 0; i--){
        if(str1[i] == '0' && carry){
            str.push_back('9');
            continue;
        }
        int temp = str1[i]-'0' - carry;
        if(i > 0 || temp > 0)
            str.push_back(temp+'0');
        carry = 0;
    }

    int pt = str.length()-1;
    for(int i = str.length()-1; i >= 0; i--){
        if(str[i] == '0')
            pt = i-1;
        else
            break;
    }
    if(pt == -1){
        cout << "0\n";
        return;
    }

    if(negans)
        cout << '-';

    for(int i = pt; i>=0; i--)
        cout<<str[i];
    cout<<'\n';
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--){
        carry = 0, neg1 = neg2 = 1, negans = 0, str = "";
        cin >> str1 >> str2;
        if(str1[0] == '-')
            neg1 = -1;
        if(str2[0] == '-')
            neg2 = -1;
        if(neg1 == 1 && neg2 == 1)
            addPos();
        else if(neg1 == -1 && neg2 == -1)
            addNeg();
        else if(neg1 == 1 && neg2 == -1){
            str2 = str2.substr(1,str2.length());
            if(func()){ //str1 is smaller (neg ans)
                swap(str1, str2);
                negans = 1;
            }
            sub();
        }else{
            str1 = str1.substr(1,str1.length());
            if(func()) //str1 is smaller (pos ans)
                swap(str1, str2);
            else
                negans = 1;
            sub();
        }
    }
    return 0;
}