#include<cstdio>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 10005
using namespace std;
int n,i,l,r,a[maxn];
bool p[maxn];
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
    tr(i,1,n) a[i]=a[i-1]+read();
    tr(r,0,n) if (p[a[r]%n]) break; else p[a[r]%n]=1;
    tr(l,0,n) if (a[l]%n==a[r]%n) break;
    l++;
    printf("%d\n",r-l+1);
    tr(i,l,r) printf("%d\n",a[i]-a[i-1]);
    return 0;
}
