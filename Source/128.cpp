#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<bitset>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define rtr(i,r,l) for((i)=(r);(i)>=(l);--i)
#define oo 1000000000000000000
#define maxm 102
using namespace std;
ll n,m,a[maxm],f[maxm][maxm],mi[maxm];
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void write(ll x)
{
    char a[25],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(ll x){write(x); putchar('\n');}
void init()
{
	char ch;
	n=read();
    while ((ch=getchar())!=EOF&&ch>='0'&&ch<='9') a[++m]=ch-'0';
}
void getmi()
{
	mi[0]=1;
	ll i=0;
	while (1.0*mi[i]*n<=5*1E18) {i++; mi[i]=mi[i-1]*n;}
}
void dp()
{
	ll i,j,k,t,ans;
	memset(f,-1,sizeof(f));
	rtr(i,m,1)
	{
		t=a[i];
		j=i;
		while (j<m)
		{
			if (t>=n) break;
			tr(k,1,m-j) if (f[j+1][k]>=0) 
			{
				if (mi[k]==0) break;
				if (1.0*f[j+1][k]+1.0*t*mi[k]>5*1E18) continue;
				if (f[i][k+1]==-1||(f[j+1][k]+t*mi[k]<f[i][k+1]))
					f[i][k+1]=f[j+1][k]+t*mi[k];
			}
			j++;
			t=t*10+a[j];
			if (a[i]==0) break;
		}
		if ((a[i]!=0||i==m)&&t<n) f[i][1]=t;
	}
	ans=oo+2;
	tr(i,1,m) if (f[1][i]>=0) ans=min(ans,f[1][i]);
	//tr(i,1,m) writeln(f[3][i]);
	writeln(ans);
}
int main()
{
    #ifdef DEBUG
    	freopen("in.txt","r",stdin);
    #endif
    init();
    getmi();
    dp();
    return 0;
}
