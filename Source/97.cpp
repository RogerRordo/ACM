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
#define oo 200005000000000
#define maxn 200005
using namespace std;
struct edge{ll y,pre;} a[2*maxn];
ll n,b[maxn],c[maxn],ah[maxn],m,ans=-oo,s=-oo;
ll read()
{
    ll x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
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
void newedge(ll x,ll y)
{
    a[++m].y=y; a[m].pre=ah[x]; ah[x]=m;
    a[++m].y=x; a[m].pre=ah[y]; ah[y]=m;
}
void init()
{
    ll i,x,y;
    n=read();
    tr(i,1,n) b[i]=read();
    tr(i,1,n-1)
    {
        x=read(); y=read(); newedge(x,y);
    }
}
ll dfs(ll x,ll fa)
{
    ll e,y;
    c[x]+=b[x];
    for(e=ah[x];e;e=a[e].pre) if ((y=a[e].y)!=fa) c[x]+=dfs(y,x);
    return c[x];
}
void dfs2(ll x,ll fa)
{
    ll e,y;
    if (s>-oo) ans=max(ans,s+c[x]);
    for(e=ah[x];e;e=a[e].pre) if ((y=a[e].y)!=fa)
    {
        dfs2(y,x);
        s=max(s,c[y]);
    }
}
int main()
{
    init();
    c[1]=dfs(1,0);
    dfs2(1,0);
    if (ans==-oo) printf("Impossible\n");
    else printf("%I64d\n",ans);
    return 0;
}
