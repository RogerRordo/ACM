#include<cstdio>
#include<cmath>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int dats;
long double v1,v2,r,d;
int main()
{
    scanf("%d",&dats);
    while (dats--)
    {
        scanf("%Lf %Lf %Lf %Lf",&v1,&v2,&r,&d);
        //printf("%Lf\n",asin(v1/v2)*r*v2/v1);
        if (asin(v1/v2)*r*v2/v1-d<=1e-15) printf("Wake up to code\n");
        else printf("Why give up treatment\n");
    }
    return 0;
}
