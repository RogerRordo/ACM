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
#define oo 0x7F7F7F7F
using namespace std;
ll dats,m,n,a0,a1,x[50],y[50],a[1005],b[1005],i,j,s;
ll p[1005];
bool pprime[1005];
ll read()
{
    ll x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
}
void EulerPrime()
{
	int i,j;
	tr(i,2,1000) pprime[i]=1;
	tr(i,2,1000)
	{
		if (pprime[i]) p[m++]=i;
		tr(j,0,m-1)
		{
			if (i*p[j]>1000) break;
			pprime[i*p[j]]=0;
			if (i%p[j]==0) break;
		}
	}
}

int main()
{
    EulerPrime();
    x[0]=1; y[1]=1;
    tr(i,2,40) {x[i]=x[i-1]+x[i-2]; y[i]=y[i-1]+y[i-2];}
    dats=read();
    while (dats--)
    {
        n=read(); a0=read(); a1=read();
        memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
        tr(i,0,m-1) while(a0%p[i]==0){a0/=p[i];a[i]++;}
        tr(i,0,m-1) while(a1%p[i]==0){a1/=p[i];b[i]++;}
        tr(i,0,m-1)
            if (s=a[i]*x[n]+b[i]*y[n]) printf("%d %d\n",p[i],s);
        printf("\n");
    }
    return 0;
}
