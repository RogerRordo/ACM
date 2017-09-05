/*
	Time: 161104
	Prob: CF732F
	By RogerRo
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 400100
#define maxm 800100
using namespace std;
struct edge{int x,y,pre;} a[maxm],b[maxm];
int n,am,ah[maxn],ds,dfn[maxn],low[maxn],ss,sta[maxn],gs,group[maxn];
int bm,bh[maxn],gsize[maxn],gdep[maxn];
bool insta[maxn],dir[maxm];
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
void writeb(int x){write(x); putchar(' ');}
void writeln(int x){write(x); putchar('\n');}
void newedgea(int x,int y)
{
    am++; a[am].x=x; a[am].y=y; a[am].pre=ah[x]; ah[x]=am;
    am++; a[am].x=y; a[am].y=x; a[am].pre=ah[y]; ah[y]=am;
}
void newedgeb(int x,int y)
{
    bm++; b[bm].x=x; b[bm].y=y; b[bm].pre=bh[x]; bh[x]=bm;
    bm++; b[bm].x=y; b[bm].y=x; b[bm].pre=bh[y]; bh[y]=bm;
}
void init()
{
    int i,m,x,y;
    n=read(); m=read();
    memset(ah,-1,sizeof(ah)); am=-1;
    memset(bh,-1,sizeof(bh)); bm=-1;
    tr(i,1,m)
    {
        x=read(); y=read(); newedgea(x,y);
    }
}
void tarjan(int x,int la)
{
    int e,y;
    dfn[x]=low[x]=++ds;
    insta[x]=1; sta[++ss]=x;
    for(e=ah[x];e>-1;e=a[e].pre)
        if ((la^1)!=e)
        {
            if (!dfn[y=a[e].y]) {dir[e]=1; tarjan(y,e); if (low[y]<low[x]) low[x]=low[y];}
            else if (insta[y]&&dfn[y]<low[x]) {low[x]=dfn[y]; dir[e]=1;}
        }
    if (dfn[x]==low[x])
    {
        gs++;
        do {
            group[sta[ss]]=gs;
            gsize[gs]++;
        } while (sta[ss--]!=x);
    }
}
void dfs(int x)
{
    int e,y;
    for(e=bh[x];e>-1;e=b[e].pre)
        if (!gdep[y=b[e].y])
        {
            gdep[y]=gdep[x]+1; dfs(y);
        }
}
void work()
{
    int i,t=0,root=0,x,y;
    tarjan(1,-1);
    tr(i,0,am/2)
        if ((x=group[a[2*i].x])!=(y=group[a[2*i].y]))
            newedgeb(x,y);
    tr(i,1,gs) if (gsize[i]>t) {t=gsize[i]; root=i;}
    gdep[root]=1; dfs(root);
    writeln(gsize[root]);
    tr(i,0,am/2)
    {
        if ((gdep[group[x=a[2*i].x]]<gdep[group[y=a[2*i].y]])||
        ((gdep[group[x=a[2*i].x]]==gdep[group[y=a[2*i].y]])&&!dir[2*i]))
        swap(x,y);
        writeb(x); writeln(y);
    }
}
int main()
{
    init();
    work();
    return 0;
}
