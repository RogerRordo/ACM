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
#define rtr(i,r,l) for((i)=(r);(i)>=(l);--i)
#define oo 0x7F7F7F7F
#define maxn 105
using namespace std;
int read()
{
    int x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
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
int n,q,i,x,y,z,a[maxn],j,s,ans;
int main()
{
    n=read(); q=read();
    tr(i,1,q)
    {
    	x=read(); y=read(); z=read();
    	s=0;
    	tr(j,1,n)
    		if (a[j]<x) s++;
    	if (s<y) {writeln(-1); continue;}
    	
    	s=0; ans=0;
    	tr(j,1,n)
    		if (a[j]<x)
			{
				s++; ans+=j;
				a[j]=x+z-1;
				if (s==y) break;
    		}
    	writeln(ans);
    }
    return 0;
}