#include<cstdio>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 50
using namespace std;
int n,i;
long long f[maxn];
int main()
{
    scanf("%d",&n);
    f[1]=f[2]=2;
    tr(i,3,n) f[i]=f[i-1]+f[i-2];
    printf("%lld\n",f[n]);
    return 0;
}
