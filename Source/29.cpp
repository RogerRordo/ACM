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
#define maxn 20005
#define ll long long
#define oo 0x7F7F7F7F
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int dats,i,n,m,ans,a[maxn];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (!(ch>='0' && ch<='9')) {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

int main()
{
	dats=read();
	while (dats)
	{
		dats--;
		n=read(); m=read();
		tr(i,1,n) a[i]=read();
		if (m==1) {printf("0\n"); continue;}
		sort(a+1,a+n+1);
		ans=oo;
		tr(i,m,n) ans=min(ans,a[i]-a[i-m+1]);
		printf("%d\n",ans);
	}
	return 0;
}


