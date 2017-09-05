/*
	Time: 160812
	Prob: POJ1469
	By RogerRo
*/
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 305
using namespace std;
struct edge{int x,y,pre;} a[maxn*maxn];
int dats,nx,ny,m,last[maxn],my[maxn];
bool p[maxn];
int read()
{
    int x=0,f=1;
	char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void newedge(int x,int y)
{
	m++;
	a[m].x=x; a[m].y=y;
	a[m].pre=last[x]; last[x]=m;
}
void init()
{
	int i,x,y,t;
	m=0;
	memset(last,0,sizeof(last));
	nx=read(); ny=read();
	tr(x,1,nx)
	{
		t=read();
		tr(i,1,t)
		{
			y=read();
			newedge(x,y);
		}
	}
}
int dfs(int x)
{
	for (int e=last[x];e;e=a[e].pre)
		if (!p[a[e].y])
		{
			int y=a[e].y;
			p[y]=1;
			if (!my[y] || dfs(my[y])) return my[y]=x;
		}
	return 0;
}
void hungary()
{
	int i,ans=0;
	memset(my,0,sizeof(my));
	tr(i,1,nx)
	{
		memset(p,0,sizeof(p));
		if (dfs(i)) ans++;
	}
	printf(ans==nx?"YES\n":"NO\n");
}
int main()
{
	dats=read();
	while (dats--)
	{
		init();
		hungary();
	}
	return 0;
}
