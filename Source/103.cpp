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
using namespace std;

#define maxpn 100010
#define nonx 1E100
#define eps 1E-15
//===========================================================
int cmp(long double x)
{
    if (x>eps) return 1;
    if (x<-eps) return -1;
    return 0;
}
long double sqr(long double a){return a*a;}
//===========================================================
struct point
{
    long double x,y;
    point(){}
    point(long double a,long double b){x=a;y=b;}
    
    friend point operator+(point a,point b){return point(a.x+b.x,a.y+b.y);}
    friend point operator-(point a,point b){return point(a.x-b.x,a.y-b.y);}
    friend point operator-(point a){return point(-a.x,-a.y);}
    friend long double operator*(point a,point b){return a.x*b.x+a.y*b.y;}
    friend point operator*(long double a,point b){return point(a*b.x,a*b.y);}
    friend point operator*(point a,long double b){return point(a.x*b,a.y*b);}
    friend point operator/(point a,long double b){return point(a.x/b,a.y/b);}
    friend long double operator^(point a,point b){return a.x*b.y-a.y*b.x;}
    friend bool operator==(point a,point b){return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;}
    friend bool operator!=(point a,point b){return cmp(a.x-b.x)!=0||cmp(a.y-b.y)!=0;}
} ;
const point nonp=point(nonx,nonx);
struct polygon
{
    int n; point a[maxpn];  //逆时针！
    polygon(){}
    point& operator[](int _){return a[_];}
} ;
//===========================================================
pair<long double,int> c1[maxpn],c2[maxpn];
int c1s,c2s;
bool __cmpconvex(point a,point b){return cmp(a.x-b.x)<0||(cmp(a.x-b.x)==0&&cmp(a.y-b.y)<0);}
void convex_hull(polygon &b,polygon &a) //a只是点集 O(nlogn)
{
    int i,t;
    sort(a.a+1,a.a+a.n+1,__cmpconvex);
    b.n=0;
    tr(i,1,a.n)
    {
        while (b.n>=2&&cmp((b[b.n]-b[b.n-1])^(a[i]-b[b.n-1]))<=0) b.n--;
        b[++b.n]=a[i];
    }
    
        tr(i,2,b.n)
        {
            long double slo;
            if (cmp(b[i].x-b[i-1].x)==0) slo=nonx;
            else slo=(b[i].y-b[i-1].y)/(b[i].x-b[i-1].x);
            c1[++c1s]=make_pair(slo,i);
        }
    
    
    t=b.n;
    rtr(i,a.n-1,1)
    {
        while (b.n>t&&cmp((b[b.n]-b[b.n-1])^(a[i]-b[b.n-1]))<=0) b.n--;
        b[++b.n]=a[i];
    }
    
    
        tr(i,t+1,b.n)
        {
            long double slo;
            if (cmp(b[i].x-b[i-1].x)==0) slo=nonx;
            else slo=(b[i].y-b[i-1].y)/(b[i].x-b[i-1].x);
            if (i<b.n) c2[++c2s]=make_pair(slo,i); else c2[++c2s]=make_pair(slo,1);
        }
    
    b.n--;
}
int read()
{
    int x=0; bool f=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') {f|=ch=='-'; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0'; ch=getchar();}
    return (x^-f)+f;
}
//==========================================================
polygon a,b;
void init()
{
    int i;
    a.n=read();
    tr(i,1,a.n){a[i].x=read();a[i].y=read();}
}
int ef1(long double slo)
{
    int l=0,r=c1s+1,mid;
    while (l+1<r)
    {
        mid=(l+r)>>1;
        if (c1[mid].first<=slo) l=mid; else r=mid;
    }
    return l;
}
int ef2(long double slo)
{
    int l=0,r=c2s+1,mid;
    while (l+1<r)
    {
        mid=(l+r)>>1;
        if (c2[mid].first<=slo) l=mid; else r=mid;
    }
    return l;
}
void work()
{
    int i,t; long double slo,ans=0;
    tr(i,1,a.n)
    {
        if (cmp(a[i].x)==0) slo=nonx; else slo=a[i].y/a[i].x;
        t=ef1(slo);
        if (t) ans=max(ans,abs(a[i]^b[c1[t].second]));
        else ans=max(ans,abs(a[i]^b[c1[c1s].second]));
        t=ef2(slo);
        if (t) ans=max(ans,abs(a[i]^b[c2[t].second]));
        else ans=max(ans,abs(a[i]^b[c2[c2s].second]));
    }
    printf("%.Lf\n",ans);
}
int main()
{
    init();
    convex_hull(b,a);
    work();
    return 0;
}
