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
#define maxn 1005
#define maxm 15005
using namespace std;
struct edge
{
    int x,y,z;
} a[maxm];
inline bool operator<(edge a,edge b)
{
    return a.z<b.z;
}
int n,m,fa[maxn];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int find(int x){return(fa[x]==x?x:fa[x]=find(fa[x]));}
void init()
{
    int i;
    n=read(); m=read();
    tr(i,1,m)
    {
        a[i].x=read();
        a[i].y=read();
        a[i].z=read();
    }
    sort(a+1,a+m+1);
}
void work()
{
    int i,j,fx,fy,s=n;
    tr(i,1,n) fa[i]=i;
    tr(i,1,m)
    {
        fx=find(a[i].x);
        fy=find(a[i].y);
        if (fx!=fy)
        {
            fa[fx]=fy;
            s--;
            if (s==1) break;
        }
    }
    printf("%d\n%d\n",a[i].z,i);
    tr(j,1,i) printf("%d %d\n",a[j].x,a[j].y);
}
int main()
{
    init();
    work();
    return 0;
}
