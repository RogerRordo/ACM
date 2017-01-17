#include<bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
#define maxn 105
using namespace std;
int n,m,a[maxn][maxn];
void init()
{
	int i,j;
	scanf("%d%d",&n,&m);
	tr(i,1,n) tr(j,1,m) scanf("%d",&a[i][j]);
}
void work()
{
	int i,j,k,s=0;
	bool p;
	tr(i,1,n) tr(j,1,m)
	{
		p=1;
		tr(k,1,i-1) if (a[k][j]>=a[i][j])
		{
			p=0; break;
		}
		if (p) s++;
		
		p=1;
		tr(k,i+1,n) if (a[k][j]>=a[i][j])
		{
			p=0; break;
		}
		if (p) s++;
		
		p=1;
		tr(k,1,j-1) if (a[i][k]>=a[i][j])
		{
			p=0; break;
		}
		if (p) s++;
		
		p=1;
		tr(k,j+1,m) if (a[i][k]>=a[i][j])
		{
			p=0; break;
		}
		if (p) s++;
		//printf("%d ",s);
	}
	//printf("\n");
	printf("%d\n",s);
}
int main()
{
	freopen("l.in","r",stdin);
	freopen("l.out","w",stdout);
	init();
	work();
	return 0;
}
