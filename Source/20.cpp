/*
	Time: 160812
	Prob: POJ1273
	By RogerRo
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define oo 0x7F7F7F7F
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 5005
#define maxm 10000005
using namespace std;
struct edge{int x,y,c,f,pre;} a[2*maxm];
int n,mm,m,last[maxn],d[maxn],gap[maxn],cur[maxn],ans;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
void newedge(int x,int y,int c,int f)
{
	m++;
	a[m].x=x; a[m].y=y; a[m].c=c; a[m].f=f;
	a[m].pre=last[x]; last[x]=m;
}
void init()
{
	int i,x,y,c;
	m=-1;
	memset(last,-1,sizeof(last));
	memset(d,0,sizeof(d));
	memset(gap,0,sizeof(gap));
	gap[0]=n;
	ans=0;
	tr(i,1,mm)
	{
		x=read(); y=read(); c=read();
		newedge(x,y,c,0);
		newedge(y,x,c,c);
	}
	tr(i,1,n) cur[i]=last[i];
}
int sap(int x,int flow)
{
	int e,t;
	if (x==n) return flow;
	for (e=cur[x];e!=-1;e=a[e].pre)
		if (a[e].f<a[e].c && d[a[e].y]+1==d[x])
		{
			cur[x]=e;
			if (t=sap(a[e].y,min(flow,a[e].c-a[e].f)))
			{
				a[e].f+=t; a[e^1].f-=t; return t;
			}
		}
	if (--gap[d[x]]==0) d[n]=n;
	d[x]=n;
	for (e=last[x];e!=-1;e=a[e].pre)
		if (a[e].f<a[e].c) d[x]=min(d[x],d[a[e].y]+1);
	cur[x]=last[x];	
	++gap[d[x]];
	return 0;
}
int main()
{
	while (~scanf("%d%d",&mm,&n)) 
	{
		init();
		while (d[n]<n) ans+=sap(1,oo);
		printf("%d\n",ans);
	}
	return 0;
}
