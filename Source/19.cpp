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
	int e,h,t,sum,num;
	memset(d,0x7F,sizeof(d));
	b[0]=1; p[1]=1; d[1]=0;
	sum=0; num=1;
	h=0; t=0;
	while (num)
	{
		while (d[h]*num>sum)
		{
			t=(t+1)%n;
			b[t]=b[h];
			h=(h+1)%n;
		}
		e=last[b[h]];
		p[b[h]]=0;
		num--;
		sum-=d[a[e].x];
		h=(h+1)%n;
		for (;a[e].x;e=a[e].pre)
			if (d[a[e].x]+a[e].d<d[a[e].y])
			{
				if (p[a[e].y]) sum-=d[a[e].y];
				d[a[e].y]=d[a[e].x]+a[e].d;
				sum+=d[a[e].y];
				if (!p[a[e].y])
				{
					if (num && d[a[e].y]<d[b[h]])
					{
						h=(h+n-1)%n;
						b[h]=a[e].y;
					} else
					{
						t=(t+1)%n;
						b[t]=a[e].y;
					}
					p[a[e].y]=1;
					num++;
				}
			}
	}
	printf("%d\n",d[n]);
}
int main()
{
	init();
	spfa();
	return 0;
}
