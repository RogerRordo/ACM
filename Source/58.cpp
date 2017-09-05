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
#define maxn 105
using namespace std;
int n,m,a[maxn][maxn],my[maxn][maxn][2],ans[maxn][maxn],anss[maxn][maxn],d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool tp[maxn],p[maxn][maxn];
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
void init()
{
    int i,j,t;
    n=read(); m=read();
    tr(i,1,n) tr(j,1,m)
    {
        t=read();
        if (!tp[t]) {tp[t]=1; t=t*2;} else t=t*2+1;
        a[i][j]=t;
    }
}
int dfs(int x,int y)
{
    int i,tx,ty;
    tr(i,0,3)
    {
        tx=x+d[i][0]; ty=y+d[i][1];
        if (!p[tx][ty]&&1<=tx&&tx<=n&&1<=ty&&ty<=m&&(a[tx][ty]^a[x][y])!=1)
        {
            p[tx][ty]=1;
            if (!my[tx][ty][0]||dfs(my[tx][ty][0],my[tx][ty][1]))
            {
                my[tx][ty][0]=x; my[tx][ty][1]=y;
                ans[x][y]=i+1;
                return 1;
            }
        }
    }
    return 0;
}
void work()
{
    int i,j,t,ss=0;
    memset(my,0,sizeof(my));
    tr(i,1,n) tr(j,1,m) if ((i+j)%2==0)
    {
        memset(p,0,sizeof(p));
        if (dfs(i,j)) ss++;
    }
    if (ss<n*m/2) {printf("-1\n"); return ;}
    t=0;
    tr(i,1,n) tr(j,1,m)
        if (ans[i][j])
        {
            anss[i][j]=++t;
            anss[i+d[ans[i][j]-1][0]][j+d[ans[i][j]-1][1]]=t;
        }
    tr(i,1,n)
    {
        tr(j,1,m-1) printf("%d ",anss[i][j]);
        printf("%d\n",anss[i][m]);
    }
}
int main()
{
    init();
    work();
    return 0;
}
