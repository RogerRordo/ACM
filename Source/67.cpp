#include<cstdio>
#include<cstring>
#define maxn 1005
#define maxm 110005
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
struct edge{int y,pre;} a[maxm];
int n,m,ah[maxn],d[maxn];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void newedge(int x,int y)
{a[++m].y=y; a[m].pre=ah[x]; ah[x]=m; d[y]++;}
void init()
{
    int mm,i,x,y;
    n=read(); mm=read();
    tr(i,1,mm){x=read(); y=read(); newedge(x,y);}
}
void work()
{
    int i,t,e;
    tr(i,1,n)
    {
        t=read();
        if (d[t]) {printf("NO\n"); return ;}
        for(e=ah[t];e;e=a[e].pre) d[a[e].y]--;
    }
    printf("YES\n");
}
int main()
{
    init();
    work();
    return 0;
}
