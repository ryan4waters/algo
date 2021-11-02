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
  return res;
}
int main(){
  int x;
  cin>>x;
  if (x==0){cout<<x;}

  else if (x>0){cout<<mystack(x);}

  else{cout<<"-"<<mystack(x);}

  system ("pause");
}
