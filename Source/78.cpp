/*
	Time: 161106
	Prob: URAL1503
	By RogerRo
 */
#include<cstdio>
#include<cmath>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define rtr(i,r,l) for((i)=(r);(i)>=(l);--i)
#define oo 1E5
#define eps 1E-15
#define maxn 10
using namespace std;
double a[maxn][maxn],ans[maxn][maxn];
int n,anss[maxn];
int cmp(double x)
{
    if (x>eps) return 1;
    if (x<-eps) return -1;
    return 0;
}
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void init(){int i;n=read();rtr(i,n,0) a[n][i]=read();}
double get(int x,double y)
{
    int i; double res=0;
    rtr(i,x,0) res=res*y+a[x][i];
    return res;
}
void ef(int x,double ll,double rr)
{
    if (cmp(get(x,ll))==0){ans[x][++anss[x]]=ll;return;}
    if (cmp(get(x,rr))==0){ans[x][++anss[x]]=rr;return;}
    if (cmp(get(x,ll)*get(x,rr))>0) return;
    double l=ll,r=rr,mid;
    while (l+eps<r)
    {
        int tl=cmp(get(x,l)),tm=cmp(get(x,mid=(l+r)/2));
        if (tl==0) break;
        if (tl*tm>=0) l=mid; else r=mid;
    }
    ans[x][++anss[x]]=l;
}
void work()
{
    int i,j; double l,r;
    rtr(i,n-1,1) tr(j,0,i) a[i][j]=a[i+1][j+1]*(j+1);
    tr(i,0,n-1)
    {
        l=-oo;
        tr(j,1,anss[i]){ef(i+1,l,r=ans[i][j]); l=r;}
        ef(i+1,l,oo);
    }
    tr(i,1,anss[n]) printf("%.10lf\n",ans[n][i]);
}
int main()
{
    init();
    work();
    return 0;
}
