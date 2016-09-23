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
#define maxn 72
#define maxm 52
#define ll long long
#define oo 0x7F7F7F7F
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int dats,n,m;
ll p[maxm],mod;
bool pp[maxn];
map<ll,int> a;
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
	m=1;
	tr(i,2,maxn) pp[i]=1;
	tr(i,2,maxn)
	{
		if (pp[i]) p[++m]=i;
		tr(j,2,m)
		{
			if (i*p[j]>maxn) break;
			pp[i*p[j]]=0;
			if (i%p[j]==0) break;
		}
	}
	p[1]=1;
}
void dfs(int x,int y,ll z)
{
	if (y==0) a.insert(make_pair(z,0));
	if (y<p[x]) return ;
	dfs(x,y-p[x],(z*p[x])%mod);
	dfs(x+1,y,z);
}
int main()
{
	EulerPrime();
	dats=read();
	while (dats)
	{
		n=read(); mod=read();
		a.clear();
		dfs(1,n,1);
		printf("%d\n",int(a.size()));
		dats--;
	}
	return 0;
}

