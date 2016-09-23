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
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int i,n,m,c,x,y;
int main()
{
	scanf("%d%d%d",&n,&c,&x);
	m=1;
	tr(i,2,n)
	{
		scanf("%d",&y);
		m++;
		if (y-x>c) m=1;
		x=y;
	}
	printf("%d\n",m);
	return 0;	
}
