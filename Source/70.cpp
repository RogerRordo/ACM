/*
	Time: 161104
	Prob: POJ2186
	By RogerRo
 */
#include<cstdio>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 10005
#define maxm 50005
using namespace std;
struct edge{int x,y,pre;} a[maxm];
int n,m,ah[maxn],ds,dfn[maxn],low[maxn],ss,sta[maxn],gs,group[maxn],
size[maxn],od[maxn];
bool insta[maxn];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void newedge(int x,int y)
{
    a[++m].x=x; a[m].y=y;
    a[m].pre=ah[x];ah[x]=m;
}
void init()
{
    int mm,i,x,y;
    n=read(); mm=read();
    tr(i,1,mm)
    {
        x=read(); y=read(); newedge(x,y);
    }
}
void tarjan(int x)
{
    int e,y,t;
    dfn[x]=low[x]=++ds;
    sta[++ss]=x; insta[x]=1;
    for(e=ah[x];e;e=a[e].pre)
    {
        if (!dfn[y=a[e].y]) tarjan(y);
        if (insta[y]) low[x]=min(low[x],low[y]);
    }
    if (low[x]==dfn[x])
        for(gs++,t=0;t!=x;t=sta[ss--]) {group[sta[ss]]=gs; size[gs]++;}
}
void work()
{
    int i,j;
    tr(i,1,n) if (!dfn[i]) tarjan(i);
    tr(i,1,m) if (group[a[i].x]!=group[a[i].y]) od[group[a[i].x]]++;
    tr(i,1,gs) if (!od[i]) break;
    if (i<gs)
        tr(j,i+1,gs) if (!od[j]) {printf("0\n"); return ;}
    printf("%d\n",size[i]);
}
int main()
{
    init();
    work();
    return 0;
}
