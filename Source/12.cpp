/*
	Time: 160809
	Prob: POJ2387
	By RogerRo
*/
#include<cstdio>
#include<queue>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 1005
#define maxm 4005
using namespace std;
typedef pair<int,int> pa;
struct edge{int pre,x,y,d;} a[maxm];
int n,m,last[maxn],ans[maxn];
priority_queue<pa,vector<pa>,greater<pa> >d;
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
void dijkstra()
{
	int v,s,e;
	d.push(make_pair(0,1));
	while(!d.empty())
	{
		v=d.top().second;
		s=d.top().first;
		d.pop();
		if (p[v]) continue;
		p[v]=1;
		ans[v]=s;
		for(e=last[v];e;e=a[e].pre)
			if (!p[a[e].y]) d.push(make_pair(s+a[e].d,a[e].y));
	}
	printf("%d\n",ans[n]);
}
int main()
{
	init();
	dijkstra();
	return 0;
}
