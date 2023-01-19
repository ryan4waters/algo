int main(){
  int n,m;
  cin>>n>>m;
  string s1="+---";
  string s2="|   ";

  for(int j=0;j<(2*n+1);j++){

  if((j%2)==0){
  for(int i=0;i<m;i++){
    cout<<s1;
  }
  cout<<"+"<<endl;
  }

  else{
    for(int k=0;k<m;k++){
    cout<<s2;
    }
    cout<<"|"<<endl;
  }
    
  }
  return 0;
}
