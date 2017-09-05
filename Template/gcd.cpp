int __gcd(int x,int y)  //<algorithm>且g++才能用
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int gcd(int x,int y){while(y){int z=x%y; x=y; y=z;}return x;}
