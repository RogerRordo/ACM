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
#include<bitset>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 1005
#define mod 1000000007
using namespace std;
int dats,dat,n,m,k,a[maxn],f[maxn],f0[maxn],s[maxn];
map<int,int> b;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void init()
{
    int i,ta[maxn],s=0;
    b.clear();
    n=read(); m=read();
    tr(i,1,n) {a[i]=read(); ta[i]=a[i];}
    sort(ta+1,ta+n+1);
    b.insert(make_pair(ta[1],++s));
    tr(i,2,n) if (ta[i]!=ta[i-1]) b.insert(make_pair(ta[i],++s));
    tr(i,1,n) a[i]=b.at(a[i]);
}
void add(int x,int y)
{
    while (x<=n)
    {
        s[x]=(s[x]+y)%mod;
        x+=x&(-x);
    }
}
int sum(int x)
{
    int ans=0;
    while (x)
    {
        ans=(ans+s[x])%mod;
        x-=x&(-x);
    }
    return ans;
}
void dp()
{
    int i,j,ans;
    tr(j,1,n) f[j]=1;
    tr(i,2,m)
    {
        tr(j,1,n) f0[j]=f[j];
        memset(s,0,sizeof(s));
        tr(j,1,n)
        {
            f[j]=sum(a[j]-1);
            add(a[j],f0[j]);
        }
    }
    ans=0;
    tr(j,1,n) ans=(ans+f[j])%mod;
    printf("Case #%d: %d\n",dat,ans);
}
int main()
{
    dats=read();
    tr(dat,1,dats)
    {
        init();
        dp();
    }
    return 0;
}
