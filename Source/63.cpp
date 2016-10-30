/*
	Time:
	Prob:
	By RogerRo
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<bitset>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
using namespace std;
ll x,y,z;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
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
int main()
{
    x=read(); y=read(); z=read();
    if (x<y) swap(x,y);
    if (x<z) swap(x,z);
    if (y<z) swap(y,z);
    writeln(max(x-y-1,(ll)(0))+max(x-z-1,(ll)(0)));
    return 0;
}
