int main() {
int f;
int res=0;
while (x!=0){
    if (res<(pow(-2,31)/10)||res>((pow(2,31)-1)/10)){return 0;}//if not divided by 10, after the if-loop,res would overload
    f=x%10;
    res=res*10+f;
    x/=10;
}
return res;
}
