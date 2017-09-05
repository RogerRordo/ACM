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
#define maxn 1005
using namespace std;
int n,m,i,fa[maxn],x,y,fx,fy,s[maxn],s1[maxn],ans;
bool b[maxn],p;
int gfa(int x)
{
	int t;
	if (fa[x]==x) return x;
	t=gfa(fa[x]);
	b[x]=b[x]^b[fa[x]];
	return(fa[x]=t);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out2.txt","w",stdout);
	while (cin>>n>>m)
	{
		p=0;
		tr(i,1,n) fa[i]=i;
		memset(b,0,sizeof(b));
		memset(s,0,sizeof(s));
		memset(s1,0,sizeof(s1));
		tr(i,1,m)
		{
			scanf("%d%d",&x,&y);
			fx=gfa(x);
			fy=gfa(y);
			if (fx==fy)
			{
				if (b[x]==b[y]) p=1;
				continue;
			}
			fa[fx]=y;
			b[fx]=!b[x];
		}
		if (p) {printf("Impossible\n"); continue;}
		tr(i,1,n) s[gfa(i)]++;
		tr(i,1,n) s1[fa[i]]+=b[i];
		ans=0;
		tr(i,1,n) ans+=(s[i]>2*s1[i]?s1[i]:(s[i]-s1[i]));
		printf("%d\n",ans);
	}
	return 0;
}
