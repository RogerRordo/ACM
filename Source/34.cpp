#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define n 9
using namespace std;
bool p[n+4][n+4],pp[n+4][n+4];
int dats,dat,a[n+4][n+4],s;
int c[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int rch()
{
    char ch=getchar();
    while (!((ch=='.')||(ch=='x')||(ch=='o'))) ch=getchar();
    if (ch=='.') return 1;
    if (ch=='x') return 2;
    return 3;
}
void init()
{
    int i,j;
    memset(p,0,sizeof(p));
    tr(i,1,n) tr(j,1,n) a[i][j]=rch();
}
void dfs(int x,int y)
{
    int i,tx,ty;
    p[x][y]=1;
    tr(i,0,3)
    {
        tx=x+c[i][0]; ty=y+c[i][1];
        if (a[tx][ty]==1 && !pp[tx][ty]) {s++; pp[tx][ty]=1;}
        if (a[tx][ty]==3 && !p[tx][ty]) dfs(tx,ty);
    }
}
void work()
{
    int x,y;
    tr(x,1,n) tr(y,1,n)
    if (a[x][y]==3 && !p[x][y])
    {
        s=0;
        memset(pp,0,sizeof(pp));
        dfs(x,y);
        if (s==1)
        {
            puts("Can kill in one move!!!");
            return ;
        }
    }
    puts("Can not kill in one move!!!");
}
int main()
{
    scanf("%d",&dats);
    tr(dat,1,dats)
    {
        init();
        printf("Case #%d: ",dat);
        work();
    }
    return 0;
}
