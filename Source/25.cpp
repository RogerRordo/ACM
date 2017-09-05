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
#define maxn 100005
#define maxl 100005
using namespace std;
const ll oo=100000000000005;
int n,i;
ll a[maxn],f[maxn][2];
char s1[maxl],s2[maxl];
bool b[maxn][4];
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
char *reverse(char *s)
{
	int i,l=strlen(s);
	char *t=new char[l+1];
	tr(i,0,l-1) t[l-1-i]=s[i];
	t[l]='\0';
	return t;
}
int main()
{
	n=read();
	tr(i,1,n) a[i]=read();
	scanf("%s",s1);
	tr(i,2,n)
	{
		scanf("%s",s2);
		b[i][0]=(strcmp(s2,s1)>=0);
		b[i][1]=(strcmp(reverse(s2),s1)>=0);
		b[i][2]=(strcmp(s2,reverse(s1))>=0);
		b[i][3]=(strcmp(reverse(s2),reverse(s1))>=0);
		strcpy(s1,s2);
	}
	f[1][0]=0;
	f[1][1]=a[1];
	tr(i,2,n)
	{
		f[i][0]=oo;
		f[i][1]=oo;
		if (f[i-1][0]<oo && b[i][0]) f[i][0]=min(f[i][0],f[i-1][0]);
		if (f[i-1][0]<oo && b[i][1]) f[i][1]=min(f[i][1],f[i-1][0]+a[i]);
		if (f[i-1][1]<oo && b[i][2]) f[i][0]=min(f[i][0],f[i-1][1]);
		if (f[i-1][1]<oo && b[i][3]) f[i][1]=min(f[i][1],f[i-1][1]+a[i]);
	}
	if (f[n][0]==oo && f[n][1]==oo) printf("-1\n");
	else if (f[n][0]==oo) printf("%I64d\n",f[n][1]);
	else if (f[n][1]==oo) printf("%I64d\n",f[n][0]);
	else printf("%I64d\n",min(f[n][0],f[n][1]));
	return 0;
}
