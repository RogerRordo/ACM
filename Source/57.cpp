#include<cstdio>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int n,s,i,x;
int main()
{
    scanf("%d%d",&n,&s);
    tr(i,1,n)
    {
        scanf("%d",&x);
        printf("%d ",s/x-1);
        s=x;
    }
    return 0;
}
