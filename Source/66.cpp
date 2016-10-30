#include<cstdio>
#include<cmath>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 10005
using namespace std;
int n,m,k,i,ans,a[maxn];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
int main()
{
    n=read(); m=read(); k=read();
    n=n*m;
    tr(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    tr(i,2,n)
    {
        k-=(i-1)*(a[i]-a[i-1]);
        if (k<=0) break;
    }
    if (i>n) ans=a[n]+int(ceil(double(k)/double(n)));
    else ans=a[i]-int(ceil(double(-k)/double(i-1)));
    printf("%d\n",ans);
    return 0;
}
