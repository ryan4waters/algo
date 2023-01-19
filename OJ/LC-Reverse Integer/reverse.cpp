int main(){
  int x;
  cin>>x;
  vector<char> vec;

  if (x==0){cout<<x;}

  else {
    int y=abs(x);
    string s=to_string(y);
    reverse(s.begin(),s.end());
    if ((y%10)!=0){
      if (x<0){cout<<"-"+s;}
      else {cout<<s;}
    }
    else {
    int loc=0;

    while ((y%10)==0){loc++;y/=10;}
    
    string res=s.substr(loc);
    if(x<0){cout<<"-"+res;}
    else {cout<<res;}
    }
  }

  system ("pause");
}
