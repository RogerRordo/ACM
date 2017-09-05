#include<cstdio>
#include<algorithm>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 2005
using namespace std;
struct point
{
    ll x,y,da,db;
    friend bool operator<(point a,point b){return a.da>b.da;}
} a[maxn];
int n;
ll xa,ya,xb,yb;
ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void init()
{
    int i;
    scanf("%d\n",&n);
    xa=read(); ya=read();
    xb=read(); yb=read();
    tr(i,1,n)
    {
        a[i].x=read(); a[i].y=read();
        a[i].da=(a[i].x-xa)*(a[i].x-xa)+(a[i].y-ya)*(a[i].y-ya);
        a[i].db=(a[i].x-xb)*(a[i].x-xb)+(a[i].y-yb)*(a[i].y-yb);
    }
}
void work()
{
    int i;
    ll r1=a[1].da,r2=0,ans=a[1].da;
    tr(i,2,n)
    {
        r1=a[i].da; r2=max(r2,a[i-1].db);
        ans=min(ans,r1+r2);
    }
    r1=0; r2=max(r2,a[n].db);
    ans=min(ans,r1+r2);
    printf("%lld\n",ans);
}
int main()
{
    init();
    sort(a+1,a+n+1);
    work();
    return 0;
}
