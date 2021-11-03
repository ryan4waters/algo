 int main(){
   int x;
   cin>>x;

   if (x<0){cout<<"false";}
   else if (x==0){cout<<"true";}

   else {
   int len=log10(x)+1;
   string s=to_string(x);
   int j=0;

   for (int i=0;i<(len/2);i++){
     if (s[i]==s[len-i-1]){j++;}
   }
    if (j==(len/2)){cout<<"true";}
    else {cout<<"flase";}
   }

   system ("pause");
 }
