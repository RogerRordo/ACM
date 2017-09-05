/*
	Time: 160811
	Prob: POJ2387
	By RogerRo
*/
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 1005
#define maxm 4005
using namespace std;
struct edge{int pre,x,y,d;} a[maxm];
int n,m,last[maxn],d[maxn],b[maxn];
bool p[maxn];
void newedge(int x,int y,int d)
{
	m++;
	a[m].x=x; a[m].y=y; a[m].d=d;
	a[m].pre=last[x]; last[x]=m;
}
void init()
{
	int i,mm,x,y,z;
	scanf("%d%d",&mm,&n);	
	tr(i,1,mm)
	{
		scanf("%d%d%d",&x,&y,&z);
		newedge(x,y,z);
		newedge(y,x,z);
	}
}
void spfa()
{
	int h,t,e;
	memset(d,0x7F,sizeof(d));
	b[0]=1; p[1]=1; d[1]=0;
	h=n-1; t=0;
	while (h!=t)
	{
		h=(h+1)%n;
		for (e=last[b[h]];e;e=a[e].pre)
			if (d[a[e].x]+a[e].d<d[a[e].y])
			{
				d[a[e].y]=d[a[e].x]+a[e].d;
				if (!p[a[e].y])
				{
					t=(t+1)%n;
					b[t]=a[e].y;
					p[a[e].y]=1;
				}
			}
		p[b[h]]=0;
	}
	printf("%d\n",d[n]);
}
int main()
{
	init();
	spfa();
	return 0;
}
