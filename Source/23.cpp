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
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int sx,sy,n,x,y,s;
double ans;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
double dis(double x,double y)
{
	return sqrt(x*x+y*y);
}
int main()
{
	sx=read(); sy=read();
	n=read();
	ans=1e30;
	while (n--)
	{
		x=read(); y=read(); s=read();
		ans=min(ans,dis(abs(sx-x),abs(sy-y))/s);
	}
	printf("%.9lf",ans);
	return 0;
}
