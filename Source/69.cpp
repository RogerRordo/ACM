/*
	Time: 161104
	Prob: HDU4773
	By RogerRo
 */
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define eps 1E-8
using namespace std;
const double pi=acos(-1.0);
int cmp(double x)
{
    if (x>eps) return 1;
    if (x<-eps) return -1;
    return 0;
}
double sqr(double x){return x*x;}
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
    
    friend double sqr(point a){return a*a;}
    friend double len(point a){return sqrt(sqr(a));}
    friend point rotate(point a,double b){return point(a.x*cos(b)-a.y*sin(b),a.x*sin(b)+a.y*cos(b));}
    friend double angle(point a,point b){return acos(a*b/len(a)/len(b));}
    friend point reflect(point a,point b){return 2*a-b;}
} a,b,c,o;
int dats,s;
double ra,rb,rota,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,ta,tb,x,y,r,ans[5][4];
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void print(double x,double y,double r)
{
    point t(x,y);
    t=rotate(t,-rota)+o;
    printf("%.6lf %.6lf %.6lf\n",t.x,t.y,r);
}
void addans(double x,double y,double r)
{
    ans[s][1]=x;ans[s][2]=y;ans[s][3]=r;
    if (cmp(ans[s][3])>0) s++;
}
int main()
{
    dats=read();
    while (dats--)
    {
        s=0;
        a.x=read();a.y=read();ra=read();
        b.x=read();b.y=read();rb=read();
        c.x=read();c.y=read();
        o=(a+b)/2;
        a=a-o; b=b-o; c=c-o;
        if (cmp(b.x)==0) rota=0; else rota=pi/2-atan(b.y/b.x);
        a=rotate(a,rota); b=rotate(b,rota); c=rotate(c,rota);
        if (cmp(ra-rb)<0) {swap(a,b); swap(ra,rb);}
        t1=c.x/ra; t2=(c.y+b.y)/ra; t3=(sqr(b.y)-sqr(ra)-sqr(c.x)-sqr(c.y))/(2*ra);
        t4=t1-c.x/rb; t5=t2-(c.y-b.y)/rb; t6=t3-(sqr(b.y)-sqr(rb)-sqr(c.x)-sqr(c.y))/(2*rb);
        if (cmp(t4)==0)
        {
            t7=sqr(t1)-1; t8=2*t1*t3+2*ra*t1; t9=sqr(ra+t3)-sqr(b.y); t10=sqr(t8)-4*t7*t9;
            if (cmp(t7)==0)
            {
                if (cmp(t8)!=0){x=-t9/t8; y=0; r=t1*x+t2*y+t3; addans(x,y,r);}
            }
            else if (cmp(t10)==0){x=-t8/(2*t7); y=0; r=t1*x+t2*y+t3; addans(x,y,r);}
            else if (cmp(t10)>0)
            {
                x=(-t8-sqrt(t10))/(2*t7); y=0; r=t1*x+t2*y+t3; addans(x,y,r);
                x=(-t8+sqrt(t10))/(2*t7); y=0; r=t1*x+t2*y+t3; addans(x,y,r);
            }
        } else
        {
            ta=1/sqr((ra-rb)/2); tb=-1/(sqr(b.y)-1/ta);
            if (cmp(t5)==0)
            {
                t7=(1-tb*sqr(t6/t4))/ta;
                if (cmp(t7)>=0)
                {
                    x=-t6/t4; y=sqrt(t7); r=t1*x+t2*y+t3; addans(x,y,r);
                    if (cmp(t7)>0){x=-t6/t4; y=-sqrt(t7); r=t1*x+t2*y+t3; addans(x,y,r);}
                }
            } else
            {
                t7=-t4/t5; t8=-t6/t5;
                t9=ta*sqr(t7)+tb; t10=2*ta*t7*t8; t11=ta*sqr(t8)-1; t12=sqr(t10)-4*t9*t11;
                if (cmp(t9)==0)
                {
                    if (cmp(t10)!=0){x=-t11/t10; y=t7*x+t8; r=t1*x+t2*y+t3; addans(x,y,r);}
                }
                else if (cmp(t12)==0){x=-t10/(2*t9); y=t7*x+t8; r=t1*x+t2*y+t3; addans(x,y,r);}
                else if (cmp(t12)>0)
                {
                    x=(-t10-sqrt(t12))/(2*t9); y=t7*x+t8; r=t1*x+t2*y+t3; addans(x,y,r);
                    x=(-t10+sqrt(t12))/(2*t9); y=t7*x+t8; r=t1*x+t2*y+t3; addans(x,y,r);
                }
            }
        }
        printf("%d\n",s);
        while (s--) print(ans[s][1],ans[s][2],ans[s][3]);
    }
    return 0;
}
