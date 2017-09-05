#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
#define oo 2147483647
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 100005
#define maxm 100005
using namespace std;
struct edge{int x,y;} a[maxm];
int n,m,q,fa[maxn],b[maxm],ans[maxm];
bool c[maxm];
int gfa(int x){return(fa[x]==x?x:fa[x]=gfa(fa[x]));}
void init()
{
	int i;
	scanf("%d%d",&n,&m);
	tr(i,1,m) scanf("%d%d",&a[i].x,&a[i].y);
	scanf("%d",&q);
	tr(i,1,q) scanf("%d",&b[i]);
}
void work()
{
	int i,fx,fy,s;
	tr(i,1,q) c[b[i]]=1;
	tr(i,1,n) fa[i]=i;
	s=n;
	tr(i,1,m)
		if (!c[i])
		{
			fx=gfa(a[i].x);
			fy=gfa(a[i].y);
			if (fx!=fy)
			{
				fa[fx]=fy;
				s--;
			}
		}
	ans[q]=s;
	for (i=q;i>1;i--)
	{
		fx=gfa(a[b[i]].x);
		fy=gfa(a[b[i]].y);
		if (fx!=fy)
		{
			fa[fx]=fy;
			s--;
		}
		ans[i-1]=s;
	}
	tr(i,1,q-1) printf("%d ",ans[i]);
	printf("%d\n",ans[q]);
}
int main()
{
	init();
	work();
	return 0;
}
