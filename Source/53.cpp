#include<cstdio>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
long long x,y,s;
int main()
{
    scanf("%lld%lld",&x,&y);
    s=2*min(x,y)-2; if (x>y) s++;
    printf("%lld\n",s);
    return 0;
}
