#include<cstdio>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 105
using namespace std;
int n,m,ss,ta[maxn][maxn],d[maxn][maxn],ans[maxn][maxn];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool a[maxn][maxn][4];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void init()
{
    int x,y,t,tx,ty;
    n=read(); m=read();
    tr(x,1,n) tr(y,1,m) ta[x][y]=read();
    tr(x,1,n) tr(y,1,m) tr(t,0,3)
    {
        tx=x+dir[t][0]; ty=y+dir[t][1];
        if (1<=tx&&tx<=n&&1<=ty&&ty<=m&&ta[tx][ty]!=ta[x][y])
        {
            a[x][y][t]=1;
            d[x][y]++;
        }
    }
}
void clear(int x,int y)
{
    int t,tx,ty;
    tr(t,0,3) if (a[x][y][t])
    {
        tx=x+dir[t][0]; ty=y+dir[t][1];
        a[x][y][t]=0; a[tx][ty][t^1]=0;
        d[x][y]--; d[tx][ty]--;
    }
}
void match(int x,int y)
{
    int t,tx,ty;
    tr(t,0,3) if (a[x][y][t]) break;
    tx=x+dir[t][0]; ty=y+dir[t][1];
    ss++;
    ans[x][y]=ss; ans[tx][ty]=ss;
    clear(x,y); clear(tx,ty);
}
void work()
{
    int i,j,k,tx,ty,sss=n*m/2;
    tr(k,1,sss)
    {
        tx=ty=0;
        tr(i,1,n) tr(j,1,m)
        if (!ans[i][j])
        {
            if (tx==0||d[i][j]<d[tx][ty])
            {
                tx=i; ty=j;
                if (d[tx][ty]==1) break;
            }
        }
        match(tx,ty);
    }
    tr(i,1,n)
    {
        tr(j,1,m-1) printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][m]);
    }
}
int main()
{
    init();
    work();
    return 0;
}
