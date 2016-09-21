/*
	Time: 160720
	Prob: POJ1125
	By RogerRo
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define oo 2147483647
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 105
using namespace std;
int n,a[maxn][maxn];
void init()
{
	int i,j,k,t1,t2;
	memset(a,0,sizeof(a));
	tr(i,1,n)
	{
		cin>>k;
		tr(j,1,k)
		{
			cin>>t1>>t2;
			if (t1!=i &&(!a[i][t1] || t2<a[i][t1])) a[i][t1]=t2;
		}
	}
}
void floyd()
{
	int i,j,k;
	tr(k,1,n) tr(i,1,n)
		if (a[i][k]) tr(j,1,n)
			if (i!=j && a[k][j] && (!a[i][j] ||(a[i][j] && a[i][k]+a[k][j]<a[i][j])))
			a[i][j]=a[i][k]+a[k][j];
}
void print()
{	
	int i,j,k,ans1,ans2;
	bool p;
	ans2=oo;
	tr(i,1,n)
	{
		k=0;
		p=true;
		tr(j,1,n)
			if (i!=j)
			{
				if (!a[i][j]) {p=false; break;}
				if (k==0 || a[i][j]>a[i][k]) k=j;
			}
		if (p && a[i][k]<ans2) {ans1=i; ans2=a[i][k];}
	}
	if (ans2==oo) cout<<"disjoint"<<endl;
	else cout<<ans1<<' '<<ans2<<endl;
	
}
int main()
{
	cin>>n;
	while (n!=0)
	{
		init();
		floyd();
		print();
		cin>>n;
	}
	return 0;
}
