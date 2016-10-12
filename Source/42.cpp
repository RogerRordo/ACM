/*
	Time: 161012
	Prob: POJ3264
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
#include<bitset>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
#define maxn 50005
#define maxln 20
using namespace std;
int n,q,mn[maxn][maxln],mx[maxn][maxln];
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
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x)
{
    write(x);
    putchar('\n');
}
void init()
{
    int i;
    n=read(); q=read();
    tr(i,1,n) mn[i][0]=mx[i][0]=read();
}
void st()
{
    int i,j,ln;
    ln=log(n)/log(2);
    tr(i,1,ln) tr(j,1,n-(1<<i)+1)
    {
        mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
        mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
    }
}
void work()
{
    int i,x,y,t;
    tr(i,1,q)
    {
        x=read(); y=read();
        t=log(y-x+1)/log(2);
        writeln
        (
         max(mx[x][t],mx[y-(1<<t)+1][t])-
         min(mn[x][t],mn[y-(1<<t)+1][t])
         );
    }
}
int main()
{
    init();
    st();
    work();
    return 0;
}
