#include <algorithm>

int main()
{  
    string a,b;
    while (cin>>a>>b){
        int alen=a.size();
        int blen=b.size();
        int tmp1=0;
        int tmp2=0;
        int tmp3=0;
        if (alen>blen) {
            for (int i=0;i<min(alen,blen);i++){
            if (a[i] != b[i]) {cout<<"NO"<<endl;break;}
                tmp1++;
        }
            if (tmp1 != min(alen,blen)) continue;
            if (count(a.begin(),a.end(),'.') == count(b.begin(),b.end(),'.')){
            if (count(a.begin()+blen,a.end(),'0') != alen-blen) {cout<<"NO"<<endl;}
            else {
                if (tmp1 == min(alen,blen)) {cout<<"YES"<<endl;}
            }}
            else {
                if (count(a.begin()+blen,a.end(),'0') != alen-blen-1) {cout<<"NO"<<endl;}
            else {
                if (tmp1 == min(alen,blen)) {cout<<"YES"<<endl;}
            }
            }
        }
        
        else if (alen<blen) {
            for (int i=0;i<min(alen,blen);i++){
            if (a[i] != b[i]) {cout<<"NO"<<endl;break;}
                tmp2++;
        }
            if (tmp2 != min(alen,blen)) continue;
            if (count(a.begin(),a.end(),'.') == count(b.begin(),b.end(),'.')){
            if (count(b.begin()+alen,b.end(),'0') != blen-alen) {cout<<"NO"<<endl;}
            else {
                if (tmp2 == min(alen,blen)) {cout<<"YES"<<endl;}
            }}
            else {
                if (count(b.begin()+alen,b.end(),'0') != blen-alen-1) {cout<<"NO"<<endl;}
                else {
                if (tmp2 == min(alen,blen)) {cout<<"YES"<<endl;}
            }
            }
        }
        
        else {
        for (int i=0;i<alen;i++){
            if (a[i] != b[i]) {cout<<"NO"<<endl;break;}
            tmp3++;
        }
            if (tmp3 != alen) continue;
            if (tmp3 == alen) {cout<<"YES"<<endl;}
        }
    }
  return 0;
}
