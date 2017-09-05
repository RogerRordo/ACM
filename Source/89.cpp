#include<cstdio>
#include<cmath>
using namespace std;
int dats; double x,y,r,d;
int main()
{
    scanf("%d",&dats);
    while (dats--)
    {
        scanf("%lf%lf%lf",&x,&y,&r);
        d=sqrt(x*x+y*y);
        printf("%.2lf %.2lf\n",r-d,r+d);
    }
    return 0;
}