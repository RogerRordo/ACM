/*
	Time: 160720
	Prob: POJ1258
	By RogerRo
*/
#include<iostream>
#include<cstring>
#define oo 2147483647
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 105
using namespace std;
int n,i,j,a[maxn][maxn],d[maxn];
bool p[maxn];
void prim()
{
	int t,s;
	memcpy(d,a[1],sizeof(d));
	d[0]=oo;
	memset(p,0,sizeof(p));
	p[1]=true;
	s=0;
	tr(i,2,n)
	{
		t=0;
		tr(j,1,n) if (!p[j] && d[j]<d[t]) t=j;
		s+=d[t];
		p[t]=true;
		tr(j,1,n) 
			if (!p[j]) d[j]=min(d[j],a[t][j]);
	}
	cout<<s<<endl;
}
int main()
{
	while (cin>>n)
	{
		tr(i,1,n) tr(j,1,n) cin>>a[i][j];
		prim();
	}
	return 0;
}
