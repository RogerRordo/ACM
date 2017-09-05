/*
	Time: 160720
	Prob: POJ1258
	By RogerRo
*/
#include<iostream>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 105
using namespace std;
struct edge{int x,y,d;} a[maxn*maxn];
bool cmp(edge a,edge b){return a.d<b.d;}
int n,i,j,m,fa[maxn];
int gfa(int x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}
void kruskal()
{
	int s;
	sort(a+1,a+m+1,cmp);
	tr(i,1,n) fa[i]=i;
	s=0;
	tr(i,1,m)
		if (gfa(a[i].x)!=gfa(a[i].y))
		{
			fa[gfa(a[i].x)]=gfa(a[i].y);
			s+=a[i].d;
		}
	cout<<s<<endl;
}
int main()
{
	while (cin>>n)
	{
		m=0;
		tr(i,1,n) tr(j,1,n) 
		{
			m++;
			a[m].x=i;
			a[m].y=j;
			cin>>a[m].d;
			if (a[m].d==0) m--;
		}
		kruskal();
	}
	return 0;
}
