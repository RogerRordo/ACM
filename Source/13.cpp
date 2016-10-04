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
#define oo 0x7F7F7F7F
#define n 10000005
#define maxm 700005
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int l,r,m,prime[maxm],a[n];
bool pprime[n];
void EulerPrime()
{
	int i,j;
	tr(i,2,n) pprime[i]=1;
	tr(i,2,n)
	{
		if (pprime[i]) prime[++m]=i;
		tr(j,1,m)
		{
			if (i*prime[j]>n) break;
			pprime[i*prime[j]]=0;
			if (i%prime[j]==0) break;
		}
	}
}
void work()
{
	int i;
	tr(i,1,n) a[i]=a[i-1]+pprime[i];
	scanf("%d%d",&l,&r); printf("%d\n",a[r]-a[l-1]);
	while (~scanf("%d%d",&l,&r)) printf("\n%d\n",a[r]-a[l-1]);
}
int main()
{
	EulerPrime();
	work();
	return 0;
}