#include<cstdio>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
#define maxn 105
using namespace std;
int n,a[maxn][maxn],i,j,k,s,ans=-oo;;
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
    n=read();
    tr(i,1,n) tr(j,1,n) a[i][j]=read()+a[i-1][j];
    tr(i,1,n) tr(j,i,n)
    {
        s=0;
        tr(k,1,n)
        {
            ans=max(ans,s+=a[j][k]-a[i-1][k]);
            s=max(s,0);
        }
    }
    printf("%d\n",ans);
    return 0;
}
