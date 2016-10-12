/*
	Time: 161012
	Prob: HDU2586
	By RogerRo
 */
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxq 205
#define maxn 40005
using namespace std;
struct query{int x,y,pre,lca;} b[2*maxq];
struct edge{int x,y,pre,d;} a[2*maxn];
int dats,n,q,am,bm,ah[maxn],bh[maxn],fa[maxn],dep[maxn];
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
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
void newedge(int x,int y,int d)
{
    am++;
    a[am].x=x; a[am].y=y; a[am].d=d;
    a[am].pre=ah[x]; ah[x]=am;
}
void newquery(int x,int y)
{
    bm++;
    b[bm].x=x; b[bm].y=y;
    b[bm].pre=bh[x]; bh[x]=bm;
}
int gfa(int x){return fa[x]==x?x:fa[x]=gfa(fa[x]);}
void init()
{
    int i,x,y,d;
    am=-1; bm=-1;
    memset(ah,-1,sizeof(ah));
    memset(bh,-1,sizeof(bh));
    memset(dep,0,sizeof(dep));
    memset(p,0,sizeof(p));
    n=read(); q=read();
    tr(i,1,n) fa[i]=i;
    tr(i,1,n-1)
    {
        x=read(); y=read(); d=read();
        newedge(x,y,d); newedge(y,x,d);
    }
    tr(i,1,q)
    {
        x=read(); y=read();
        newquery(x,y); newquery(y,x);
    }
}
void tarjan(int x,int depth)
{
    int tmp,y;
    p[x]=1;
    dep[x]=depth;
    for(tmp=ah[x];tmp>-1;tmp=a[tmp].pre)
        if (!p[y=a[tmp].y])
        {
            tarjan(y,depth+a[tmp].d);
            fa[y]=x;
        }
    for(tmp=bh[x];tmp>-1;tmp=b[tmp].pre)
        if (p[y=b[tmp].y]) b[tmp].lca=b[tmp^1].lca=gfa(y);
}
void print()
{
    int i;
    tr(i,0,q-1) writeln(dep[b[2*i].x]+dep[b[2*i].y]-2*dep[b[2*i].lca]);
}
int main()
{
    dats=read();
    while (dats--)
    {
        init();
        tarjan(1,0);
        print();
    }
    return 0;
}
