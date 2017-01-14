#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
#define rtr(i,r,l) for(i=(r);i>=(l);i--)
#define maxn 105
using namespace std;
int n,m,i,j,a[7][maxn][maxn];
int main()
{
	scanf("%d",&n);
	tr(i,1,n) tr(j,1,n) a[1][i][j]=++m;
	tr(i,1,n) tr(j,1,n) a[2][i][j]=++m;
	tr(i,1,n) tr(j,1,n) a[3][i][j]=++m;
	rtr(i,n,1) tr(j,1,n) a[5][i][j]=++m;
	rtr(i,n,1) tr(j,1,n) a[4][i][j]=++m;
	tr(i,1,n) rtr(j,n,1) a[6][i][j]=++m;
	//
	tr(i,1,n)
	{
		tr(j,1,n-1) printf("%d ",a[1][i][j]);
		printf("%d\n",a[1][i][n]);
	}
	tr(i,1,n)
	{
		tr(j,1,n) printf("%d ",a[2][i][j]);
		tr(j,1,n) printf("%d ",a[3][i][j]);
		tr(j,1,n) printf("%d ",a[4][i][j]);
		tr(j,1,n-1) printf("%d ",a[5][i][j]);
		printf("%d\n",a[5][i][n]);
	}
	tr(i,1,n)
	{
		tr(j,1,n-1) printf("%d ",a[6][i][j]);
		printf("%d\n",a[6][i][n]);
	}
	return 0;
}
