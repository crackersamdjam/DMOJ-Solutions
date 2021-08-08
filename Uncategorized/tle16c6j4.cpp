#include <bits/stdc++.h>
using namespace std;
deque <int> line1,line2,line3;
int s,k,I,a,b,c,total=0,second=30;
int temp1=0,temp2=0,temp3=0;
int main(){
  scanf("%d%d%d",&s,&k,&I);
  int length1=s,length2=k,length3=I;
  for (int i=0;i<s;i++){
    scanf("%d",&a);
    line1.push_back(a);
    temp1+=a;
  }
  for (int i=0;i<k;i++){
    scanf("%d",&b);
    line2.push_back(b);
    temp2+=b;
  }
  for (int i=0;i<I;i++){
    scanf("%d",&c);
    line3.push_back(c);
    temp3+=c;
  }
  while (temp1>30 || temp2>30 || temp3>30){
    while (length1>0){
      if (line1.front()<=second){
        temp1-=line1.front();
        second=second-line1.front();
        length1--;
        line1.pop_front();
      }
      else{
        line1.front()=line1.front()-second;
        temp1-=second;
        break;
      }
    }
    second=30;
    while (length2>0){
      if (line2.front()<=second){
        temp2-=line2.front();
        length2--;
        second=second-line2.front();
        line2.pop_front();
      }
      else{
        line2.front()=line2.front()-second;
        temp2-=second;
        break;
      }
    }
    second=30;
    while (length3>0){
      if (line3.front()<=second){
        temp3-=line3.front();
        length3--;
        second=second-line3.front();
        line3.pop_front();
      }
      else{
        line3.front()=line3.front()-second;
        temp3-=second;
        break;
      }
    }
    if (length1>0 || length2>0 || length3>0){
      if (length1>length2 && length1>length3 && length2!=length3){
        int hoang=line1.back();
        temp1-=hoang;
        length1--;
        line1.pop_back();
        
        if (length3>length2){
          line2.push_back(hoang);
          length2++;
          temp2+=hoang;
        }
        else{
          line3.push_back(hoang);
          length3++;
          temp3+=hoang;
        }
      }
      else if (length2>length1 && length2>length3 && length1!=length3){
        int hoang=line2.back();
        temp2-=hoang;
        length2--;
        line2.pop_back();
        if (length3>length1){
          line1.push_back(hoang);
          length1++;
          temp1+=hoang;
        }
        else{
          line3.push_back(hoang);
          length3++;
          temp3+=hoang;
        }
      }
      else if (length3>length2 && length3>length1 && length2!=length1){
        int hoang=line3.back();
        temp3-=hoang;
        length3--;
        line3.pop_back();
        if (length2>length1){
          line1.push_back(hoang);
          length1++;
          temp1+=hoang;
        }
        else{
          line2.push_back(hoang);
          length2++;
          temp2+=hoang;
        }
      }
    }
    second=30;
    total+=second;
  }
  total+=max(max(temp1,temp2),max(temp2,temp3));
  printf("%d",total);
}