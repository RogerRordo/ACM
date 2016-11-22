/*
	Time: 161122
	Prob: POJ1258
	By RogerRo
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#define oo 0x7f7f7f7f
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 105
#define maxm 100005
using namespace std;
struct edge{int x,y,z,pre;} a[maxm];
typedef pair<int,int> pa;
priority_queue<pa,vector<pa>,greater<pa> >d;
int n,m,ah[maxn];
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
	int i,x,y,e,ans=0;
	pa t;
	while (!d.empty()) d.pop();
	d.push(make_pair(0,1));
	memset(p,0,sizeof(p));
	tr(i,1,n)
	{
        while (!d.empty()&&p[d.top().second]) d.pop();
		t=d.top();
		ans+=t.first;
		p[x=t.second]=1;
		for(e=ah[x];e>-1;e=a[e].pre)
			if (!p[y=a[e].y]) d.push(make_pair(a[e].z,y));
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
