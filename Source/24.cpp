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
#define maxx 100005
using namespace std;
int n,m,i,t,a[maxx];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int main()
{
	n=read();
	tr(i,1,n) a[read()]++;
	tr(i,1,maxx) a[i]+=a[i-1];
	m=read();
	tr(i,1,m) printf("%d\n",a[min(read(),maxx)]);
	return 0;
}
