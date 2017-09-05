/*
	Time: 161019
	Prob: HDU3007
	By RogerRo
 */
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define eps 1E-8
#define maxn 505
using namespace std;
int cmp(double x)
{
    if (x>eps) return 1;
    if (x<-eps) return -1;
    return 0;
}
struct point
{
    double x,y;
    point(){}
    point(double a,double b){x=a;y=b;}
    friend point operator+(point a,point b){return point(a.x+b.x,a.y+b.y);}
    friend point operator-(point a,point b){return point(a.x-b.x,a.y-b.y);}
    friend point operator-(point a){return point(-a.x,-a.y);}
    friend double operator*(point a,point b){return a.x*b.x+a.y*b.y;}
    friend point operator*(double a,point b){return point(a*b.x,a*b.y);}
    friend point operator*(point a,double b){return point(a.x*b,a.y*b);}
    friend point operator/(point a,double b){return point(a.x/b,a.y/b);}
    friend double operator^(point a,point b){return a.x*b.y-a.y*b.x;}
    friend bool operator==(point a,point b){return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;}
    friend double len(point a){return sqrt(a*a);}
} a[maxn];
struct line
{
    point a,b;
    line(){}
    line(point pa,point pb){a=pa;b=pb;}
    point dir(){return b-a;}
} ;
struct circle
{
    point o; double r;
    circle(){}
    circle(point a,double b){o=a;r=b;}
} ;
int n;
void init(){int i; tr(i,1,n) scanf("%lf%lf",&a[i].x,&a[i].y);}
bool out(point a,circle b){return cmp(len(a-b.o)-b.r)==1;}
circle get(point a){return circle(a,0);}
circle get(point a,point b){return circle((a+b)/2,len(a-b)/2);}
circle get(point a,point b,point c)
{
    circle res;
    point t1=b-a,t2=c-a;
    double t=2*t1^t2;
    res.o.x=a.x+(t1*t1*t2.y-t2*t2*t1.y)/t;
    res.o.y=a.y+(t2*t2*t1.x-t1*t1*t2.x)/t;
    res.r=len(res.o-a);
    return res;
}
void work()
{
    int i,j,k;
    circle t;
    random_shuffle(a+1,a+n+1);
    for(i=2,t=get(a[1]);i<=n;i++) if (out(a[i],t))
        for(j=1,t=get(a[i]);j<i;j++) if (out(a[j],t))
            for(k=1,t=get(a[i],a[j]);k<j;k++) if (out(a[k],t))
                t=get(a[i],a[j],a[k]);
    printf("%.2lf %.2lf %.2lf\n",t.o.x,t.o.y,t.r);
}
int main()
{
    srand(time(0));
    while (scanf("%d",&n)&&n!=0) {init(); work();}
    return 0;
}
