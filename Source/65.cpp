#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
char ch,op;
ll a1,a2,a3,b1,b2,b3;
ll read()
{
    ll x=0,f=1;
    ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void write(ll x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(ll x){write(x); putchar('\n');}
void init()
{
    a1=read();
    if (ch=='\n') {a2=a1; a3=1; a1=0;}
    else {
        a2=read();
        if (ch=='/') a3=read();
        else {a3=a2; a2=a1; a1=0;}
    }
    if (a1<0) a2=-a2;
    while (ch!='+'&&ch!='-'&&ch!='*'&&ch!='/') ch=getchar();
    op=ch;
    b1=read();
    if (ch=='\n') {b2=b1; b3=1; b1=0;}
    else {
        b2=read();
        if (ch=='/') b3=read();
        else {b3=b2; b2=b1; b1=0;}
    }
    if (b1<0) b2=-b2;
    
    a2+=a1*a3;
    b2+=b1*b3;
}
ll gcd(ll x,ll y)
{
    while (ll t=x%y){x=y;y=t;}
    return y;
}
void work()
{
    ll x1,x2,t;
    if (op=='+'){x1=a2*b3+a3*b2;x2=a3*b3;}
    else if (op=='-'){x1=a2*b3-a3*b2;x2=a3*b3;}
    else if (op=='*'){x1=a2*b2;x2=a3*b3;}
    else {x1=a2*b3;x2=a3*b2;}
    
    if (x1==0) {write(0); return ;}
    if (x2<0) {x1=-x1; x2=-x2;}
    if (x1<0) {putchar('-'); x1=-x1;}
    t=x1/x2;
    if (t) {write(t); putchar(' ');}
    x1-=x2*t;
    if (x1==0) return ;
    t=gcd(x1,x2);
    x1/=t; x2/=t;
    write(x1);
    putchar('/');
    write(x2);
}
int main()
{
    init();
    work();
    putchar('\n');
    return 0;
}
