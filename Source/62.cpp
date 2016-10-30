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
#define maxn 505
using namespace std;
int i,n,k,a[maxn],s;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
void writeb(int x){write(x); putchar(' ');}
int main()
{
    n=read(); k=read();
    a[1]=read();
    tr(i,2,n) 
    {
    	a[i]=read();
		if (a[i-1]+a[i]<k) 
		{
			s+=k-a[i-1]-a[i];
			a[i]=k-a[i-1];
		}
	}
    writeln(s);
    tr(i,1,n-1) writeb(a[i]);
    writeln(a[n]);
    return 0;
}
