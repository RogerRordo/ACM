/*
	Time: 160811
	Prob: HDU2196
	By RogerRo
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 10005
using namespace std;
struct edge{int x,y,d,pre;} a[2*maxn];
int n,m,last[maxn],d0[maxn],d1[maxn],d2[maxn],b[maxn];
bool p[maxn];
void newedge(int x,int y,int d)
{
	m++;
	a[m].x=x; a[m].y=y; a[m].d=d;
	a[m].pre=last[x]; last[x]=m;
}
void init()
{
	int x,y,d;
	m=0;
	memset(last,0,sizeof(last));
	memset(d0,0,sizeof(d0));
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
	tr(x,2,n)
	{
		scanf("%d%d",&y,&d);
		newedge(x,y,d);
		newedge(y,x,d);
	}
}
void bfs(int root,int *d)
{
	int h,t;
	edge tmp;
	memset(p,0,sizeof(p));
	h=0; t=1;
	b[1]=root;
	p[root]=1;
	while (h<t)
	{
		h++;
		for (tmp=a[last[b[h]]];tmp.x;tmp=a[tmp.pre])
			if (!p[tmp.y])
			{
				b[++t]=tmp.y;
				p[tmp.y]=1;
				d[tmp.y]=d[tmp.x]+tmp.d;
			}
	}
}
void work()
{
	int i,s1,s2;
	bfs(1,d0);
	s1=1;
	tr(i,1,n) if (d0[i]>d0[s1]) s1=i;
	bfs(s1,d1);
	s2=1;
	tr(i,1,n) if (d1[i]>d1[s2]) s2=i;
	bfs(s2,d2);
	tr(i,1,n) printf("%d\n",max(d1[i],d2[i]));
}
int main()
{
	while (~scanf("%d",&n))
	{
		init();
		work();
	}
	return 0;
}
