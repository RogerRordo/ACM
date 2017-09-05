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
#define maxn 105
using namespace std;
ll n,m,k,x,y,t,T,a[maxn][maxn],i,j,smx,smn;
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
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    if (x<0) {putchar('-'); x=-x;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(ll x){write(x); putchar('\n');}
int main()
{

    #ifdef DEBUG
    	freopen("in.txt","r",stdin);
    #endif
    
    n=read(); m=read(); k=read(); x=read(); y=read();
    
    if (n>1) t=(2*n-2)*m; else t=m;
    T=k/t; k=k%t;
    tr(i,2,n-1) tr(j,1,m) a[i][j]=2*T;
    tr(j,1,m) a[1][j]=a[n][j]=T;
    
    if (k!=0)
    {
		tr(i,1,n)
		{
			tr(j,1,m)
			{
				a[i][j]++;
				k--;
				if (k==0) break;
			}
			if (k==0) break;
		}
    }
    if (k!=0)
    {
		rtr(i,n-1,1)
		{
			tr(j,1,m)
			{
				a[i][j]++;
				k--;
				if (k==0) break;
			}
			if (k==0) break;
    	}
    }
    
    smn=1000000000000000002; smx=0;
    tr(i,1,n) tr(j,1,m)
    {
    	smx=max(smx,a[i][j]);
    	smn=min(smn,a[i][j]);
    }
    printf("%I64d %I64d %I64d\n",smx,smn,a[x][y]);
    
    //tr(i,1,n) {tr(j,1,m) printf("%lld ",a[i][j]); printf("\n");}
    
    return 0;
}
