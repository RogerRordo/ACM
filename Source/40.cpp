#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 105
#define mind 1E-8
#define maxr 1E5
using namespace std;
int n;
double a[maxn],l,r,mid,minl;
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
    int i;
    n=read();
    tr(i,1,n)
    {
        a[i]=read();
        minl=max(minl,a[i]);
    }
}
double get(double x,double ra)
{
    return 2*asin(x/(2*ra));
}
bool check(double ra)
{
    int i;
    double s=0;
    tr(i,1,n) s+=get(a[i],ra);
    if (s>=2*M_PI) return 1;
    return 0;
}
bool check2(double ra)
{
    int i;
    double s1=0,s2=get(minl,ra);
    tr(i,1,n) if (a[i]!=minl) s1+=get(a[i],ra);
    if (s1<=s2) return 1;
    return 0;
}
double sq(double ra)
{
    int i;
    double p,s=0;
    tr(i,1,n)
    {
        p=r+a[i]/2;
        s+=sqrt(p*(p-ra)*(p-ra)*(p-a[i]));
    }
    return s;
}
double sq2(double ra)
{
    int i;
    double p,s=0;
    tr(i,1,n)
    {
        p=r+a[i]/2;
        if (a[i]!=minl) s+=sqrt(p*(p-ra)*(p-ra)*(p-a[i]));
        else s-=sqrt(p*(p-ra)*(p-ra)*(p-a[i]));
    }
    return s;
}
int main()
{
    init();
    
    l=minl/2; r=maxr;
    while (l+mind<r) if (check(mid=(l+r)/2)) l=mid; else r=mid;
    if (l!=minl/2) {printf("%.2lf\n",sq(l)); return 0;}
    
    l=minl/2; r=maxr;
    while (l+mind<r) if (check2(mid=(l+r)/2)) l=mid; else r=mid;
    if (r==maxr) {printf("0.00\n"); return 0;}
    //printf("l=%.2lf\n",l);printf("r=%.2lf\n",r);
    printf("%.2lf\n",sq2(l));
    return 0;
}
