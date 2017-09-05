/*
	Time: 160718
	Prob: HDU1285
	By RogerRo
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define tr(i,l,r) for((i)=(l);(i)<=(r);i++)
#define maxn 505
using namespace std;
struct edge{int x,y,pre;} a[maxn*maxn];
int n,m,last[maxn],d[maxn];
void init()
{
	int i;
	memset(last,0,sizeof(last));
	memset(d,0,sizeof(d));
	memset(a,0,sizeof(a));
	tr(i,1,m)
	{
		cin>>a[i].x>>a[i].y;
		d[a[i].y]++;
		a[i].pre=last[a[i].x];
		last[a[i].x]=i;
	}
}
void top()
{
	int i,j;
	tr(j,1,n)
	{
		tr(i,1,n) if (d[i]==0) break;
		if(i>n) break;
		d[i]=-1;
		cout<<i;
		if(j<n) cout<<' ';
		for(;last[i]>0;last[i]=a[last[i]].pre) d[a[last[i]].y]--;
	}
	cout<<endl;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		top();
	}
	return 0;
}
