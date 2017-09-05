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
#define maxn 12
#define maxp 102
using namespace std;
int n,m,w,bl[maxp],ans[28],dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[maxn][maxn],b[maxp][maxn*maxn];
bool p[maxn][maxn];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
char rch()
{
    char ch=getchar();
    while (ch<'A'||ch>'Z') ch=getchar();
    return ch;
}
void init()
{
    int i,j;
    n=read(); m=read(); w=read();
    tr(i,1,n) tr(j,1,m) a[i][j]=rch();
    getchar();
    tr(i,1,w)
    {
        while (1)
        {
            bl[i]++;
            if ((b[i][bl[i]]=getchar())=='\n')
            {
                bl[i]--;
                break;
            }
        }
    }
}
bool dfs(int x,int y,int k,int d)
{
    int i,tx,ty;
    p[x][y]=1;
    if (d>bl[k]) return 1;
    tr(i,0,3)
    {
        tx=x+dir[i][0];
        ty=y+dir[i][1];
        if ((tx<1)||(tx>n)||(ty<1)||(ty>m)||
            (p[tx][ty])||(a[tx][ty]!=b[k][d])) continue;
        if (dfs(tx,ty,k,d+1)) return 1;
    }
    p[x][y]=0;
    return 0;
}
void work()
{
    int i,j,k;
    tr(i,1,n) tr(j,1,m) tr(k,1,w)
        if (!p[i][j] && a[i][j]==b[k][1]) dfs(i,j,k,2);
    tr(i,1,n) tr(j,1,m)
        if (!p[i][j]) ans[int(a[i][j]-'A')]++;
    tr(i,0,25) tr(j,1,ans[i]) printf("%c",i+'A');
    printf("\n");
    
    //tr(i,1,n) {tr(j,1,m) printf("%d",p[i][j]); printf("\n");}
}
int main()
{
    init();
    work();
    return 0;
}
