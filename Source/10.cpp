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
#define maxl 100005
using namespace std;
int n,ii;
char a[maxl],c;
void work()
{
	int m=0,i;

	c=getchar();
	while (c!='\n')
	{
		if (c==' ')
		{
			for (i=m;i;i--) printf("%c",a[i]);
			printf(" ");
			m=0;
		}
		else a[++m]=c;
		c=getchar();
	}
	for (i=m;i;i--) printf("%c",a[i]);
	printf("\n");
}
int main()
{
	while(cin>>n && n>0) {c=getchar(); tr(ii,1,n) work();}
	return 0;
}
