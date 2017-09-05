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
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
#define maxm 200005 //40005
#define maxn 32
#define maxk 22
using namespace std;
int n,m,k,a[maxn][maxn],tb[maxk],ans,anssta;
bool p[maxn];
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
void newedge(int x,int y,int z)
{
    a[x][y]=a[x][y]|tb[z];
    a[y][x]=a[y][x]|tb[z];
}
void inittb(){int i; tb[1]=1; tr(i,2,k) tb[i]=tb[i-1]<<1;}
void init()
{
    int i,x,y,z;
    k=read(); n=read(); m=read();
    inittb();
    tr(i,1,m)
    {
        x=read()+1; y=read()+1; z=read()+1;
        newedge(x,y,z);
    }
}
bool dfs(int x,int sta)
{
    int y;
    p[x]=1;
    if (x==2) return 1;
    tr(y,1,n)
        if ((!p[y])&&((sta&a[x][y])>0))
            if (dfs(y,sta)) return 1;
    return 0;
}
void print()
{
    int s=0,i;
    tr(i,1,k) if (tb[i]&anssta)
    {
        if (++s==ans) writeln(i-1);
        else writeb(i-1);
    }
}
int cnt(int x)
{
    int i,s=0;
    tr(i,1,k) if (tb[i]&x) s++;
    return s;
}
void work()
{
    int i,t;
    ans=k+1;
    tr(i,1,(tb[k]<<1)-1)
    {
        if ((t=cnt(i))>ans) continue;
        memset(p,0,sizeof(p));
        if (dfs(1,i)) {ans=t; anssta=i;}
    }
    writeln(ans);
    print();
}
int main()
{
    init();
    work();
    return 0;
}
