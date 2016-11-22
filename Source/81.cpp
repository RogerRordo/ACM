/*
	Time: 161122
	Prob: POJ1258
	By RogerRo
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#define oo 0x7f7f7f7f
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 105
#define maxm 100005
using namespace std;
struct edge{int x,y,z,pre;} a[maxm];
int n,m,ah[maxn],d[maxn];
bool p[maxn];
void newedge(int x,int y,int z)
{
    m++; a[m].x=x; a[m].y=y; a[m].z=z;
    a[m].pre=ah[x]; ah[x]=m;
}
void init()
{
    int i,j,t;
    m=-1;
    memset(ah,-1,sizeof(ah));
    tr(i,1,n) tr(j,1,n)
    {
        scanf("%d",&t);
        newedge(i,j,t);
    }
}
void prim()
{
	int i,j,x,y,e,ans=0;
	memset(d,0x7f,sizeof(d)); d[1]=0;
	memset(p,0,sizeof(p));
	tr(i,1,n)
	{
		x=0;
		tr(j,1,n) if (!p[j]&&d[j]<d[x]) x=j;
		ans+=d[x];
		p[x]=1;
		for(e=ah[x];e>-1;e=a[e].pre)
			if (!p[y=a[e].y]) d[y]=min(d[y],a[e].z);
	}
	printf("%d\n",ans);
}
int main()
{
	while (~scanf("%d",&n))
	{
		init();
		prim();
	}
	return 0;
}
