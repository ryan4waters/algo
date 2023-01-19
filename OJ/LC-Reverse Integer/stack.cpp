  string mystack(int a){
  stack<char> tmp;
  int b=abs(a);
  string s=to_string(b);
  string res;
  int len=s.size();
  for (int i=0;i<len;i++){tmp.push(s[i]);}
  while (!tmp.empty()) {
    res+=tmp.top();
    tmp.pop();
  }

  int loc=0;
  for (int i=0;(res[i]-'0')==0;i++){
    loc++;
  }
  string fres=res.substr(loc);
  return fres;
}

  int main(){
  int x;
  cin>>x;
  if (x==0){cout<<x;}

  else if (x>0){cout<<mystack(x);}

  else{cout<<"-"<<mystack(x);}

  system ("pause");
}
