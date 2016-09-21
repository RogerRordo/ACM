/*
	Time: 160801
	Prob: POJ2387
	By RogerRo
*/
#include<cstdio>
#define oo 2147483647
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 1005
#define maxm 4005
using namespace std;
struct edge{int pre,x,y,d;} a[maxm];
int n,m,last[maxn],d[maxn];
bool p[maxn];
void init()
{
	int i,mm;
	scanf("%d%d",&mm,&n);	
	m=0;
	tr(i,1,mm)
	{
		m++;
		scanf("%d%d%d",&a[m].x,&a[m].y,&a[m].d);
		a[m].pre=last[a[m].x];
		last[a[m].x]=m;
		m++;
		a[m].x=a[m-1].y;
		a[m].y=a[m-1].x;
		a[m].d=a[m-1].d;
		a[m].pre=last[a[m].x];
		last[a[m].x]=m;
	}
}
void update(int x)
{
	int e;
	p[x]=true;
	e=last[x];
	while (e>0) 
	{
		if (!p[a[e].y] && (!d[a[e].y] || a[e].d+d[x]<d[a[e].y]))
			d[a[e].y]=a[e].d+d[x];
		e=a[e].pre;
	}
}
void dijkstra()
{
	int i,j,t;
	update(1);
	d[0]=oo;
	tr(i,2,n)
	{
		t=0;
		tr(j,1,n) if (!p[j] && d[j] && d[j]<d[t]) t=j;
		update(t);
	}
	printf("%d\n",d[n]);
}
int main()
{
	init();
	dijkstra();
	return 0;
}
