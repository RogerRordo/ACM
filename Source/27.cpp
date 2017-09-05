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
#define maxn 1000005
#define maxm 1000005
#define ll long long
#define oo 0x7F7F7F7F
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int dats,p[maxm],n,m;
bool pp[maxn];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (!(ch>='0' && ch<='9')) {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
void EulerPrime()
{
	int i,j;
	tr(i,2,maxn) pp[i]=1;
	tr(i,2,maxn)
	{
		if (pp[i]) p[++m]=i;
		tr(j,1,m)
		{
			if (i*p[j]>maxn) break;
			pp[i*p[j]]=0;
			if (i%p[j]==0) break;
		}
	}
}
void work()
{
	int i,t,ans=1;
	tr(i,1,m)
	{
		if (n==1) break;
		t=0;
		while (n%p[i]==0) {t++; n=n/p[i];}
		ans=max(ans,t);
	}
	printf("%d\n",ans);
}
int main()
{
	EulerPrime();
	dats=read();
	while (dats)
	{
		n=read();
		work();	
		dats--;
	}
	return 0;
}


