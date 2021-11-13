#include<cstdlib>
#include<cstdio>
class Solution {
public:
    string addBinary(string a, string b) {

  int alen=a.size();
  int blen=b.size();
  if (a.size()>b.size()) {
    for(int m=0;m<alen-blen;m++){b='0'+b;}
    }
  if (b.size()>a.size()) {
    for(int n=0;n<blen-alen;n++){a='0'+a;}
    }
    
  for (int i=(a.size()-1);i>=1;i--){
        a[i]=a[i]-'0'+b[i];
        if ((a[i]-'0')>1){a[i]=(a[i]-'0')%2+'0';a[i-1]+=1;}//I replace 1 with (a[i]-'0')/2 and the result would be wrong
    }
   a[0]=a[0]-'0'+b[0];

   if (a[0]-'0'==2) {a[0]='0';a='1'+a;}
   if (a[0]-'0'==3) {a[0]='1';a='1'+a;}

   return a;
    }
};
