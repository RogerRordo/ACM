/*
	Time: 160812
	Prob: POJ1273
	By RogerRo
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 50005
#define maxm 10000005
using namespace std;
int n,mm,m,ans,last[maxn],cur[maxn],pre[maxn],d[maxn],gap[maxn],b[maxn];
bool p[maxn];
struct edge{int x,y,c,f,pre;} a[2*maxm];
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
	tr(i,1,mm)
	{
		x=read(); y=read(); c=read();
		newedge(x,y,c,0);
		newedge(y,x,c,c);
	}
}
int aug()
{
	int x,flow=a[cur[1]].c-a[cur[1]].f;
	for (x=pre[n];x>1;x=pre[x]) flow=min(flow,a[cur[x]].c-a[cur[x]].f);
	return flow;
}
void bfs()
{
	int h,t,e;
	memset(p,0,sizeof(p));
	b[1]=n; p[n]=1;
	h=0; t=1;
	while (h<t)
	{
		h++;
		for (e=last[b[h]];e!=-1;e=a[e].pre)
			if (a[e].c==a[e].f && !p[a[e].y])
			{
				b[++t]=a[e].y;
				p[a[e].y]=1;
				d[a[e].y]=d[a[e].x]+1;
			}
	}
}
void sap()
{
	int x,e,flow;
	memset(d,0,sizeof(d));
	memset(gap,0,sizeof(gap));
	//gap[0]=n;
	bfs();
	tr(x,1,n) gap[d[x]]++;
	ans=0;
	tr(x,1,n) cur[x]=last[x];
	x=1; pre[1]=1; 
	while (d[1]<n)
	{
		for (e=cur[x];e!=-1;e=a[e].pre)
			if (d[x]==d[a[e].y]+1 && a[e].f<a[e].c)
			{
				cur[x]=e;
				pre[a[e].y]=x;
				x=a[e].y;
				break;
			}
		if (e==-1)
		{
			if (!(--gap[d[x]])) return;
			cur[x]=last[x];
			d[x]=n;
			for (e=last[x];e!=-1;e=a[e].pre)
				if (a[e].f<a[e].c) d[x]=min(d[x],d[a[e].y]+1);
			gap[d[x]]++;
			x=pre[x];
		}
		if (x==n){
			flow=aug();
			for (x=pre[x];x>1;x=pre[x])
			{
				a[cur[x]].f+=flow; a[cur[x]^1].f-=flow;
			}
			a[cur[x]].f+=flow; a[cur[x]^1].f-=flow;
			ans+=flow;
			x=1;
		}
	}
}
int main(){
	while (~scanf("%d%d",&mm,&n))
	{
		init();
		sap();
		printf("%d\n",ans);
	}
	return 0;
}