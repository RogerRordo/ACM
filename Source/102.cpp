/*
ans=\frac{2}{n (n+1)}\left(\frac{1}{4} \sum _{i=1}^n i (n-i) (-i+n+1)+\frac{1}{2} (n (n+1)) F(n)-\sum _{1\leq i<j\leq n,\text{Null}a_i>a_j} i (-j+n+1)\right)
*/
/*
	Time: 161220
	Prob: CF749E
	By RogerRo
 */
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
#define maxn 100005
using namespace std;
ll n,a[maxn],f[maxn];
ll read()
{
    ll x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
}
void init()
{
    ll i;
    n=read(); tr(i,1,n) a[i]=read();
}
void add(ll x,ll y)
{
    while (x<=n)
    {
        f[x]+=y;
        x+=x&-x;
    }
}
ll sum(ll x)
{
    ll res=0;
    while (x)
    {
        res+=f[x];
        x-=x&-x;
    }
    return res;
}
void work()
{
    double ans=0,s; ll i;
    s=0;
    tr(i,1,n) s+=i*(n-i)*(n-i+1);
    ans+=s/(2.0*n*(n+1));
    //
    s=0;
    rtr(i,n,1)
    {
        s+=sum(a[i]);
        add(a[i],1);
    }
    ans+=s;
    //
    s=0;
    memset(f,0,sizeof(ll)*(n+1));
    rtr(i,n,1)
    {
        s+=i*sum(a[i]);
        add(a[i],n-i+1);
    }
    ans-=2.0*s/(n*(n+1));
    printf("%.10lf\n",ans);
}
int main()
{
    init();
    work();
    return 0;
}
