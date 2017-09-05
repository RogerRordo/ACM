#include<cstdio>
#include<cmath>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
using namespace std;
int dats,dat;
bool eq(double x,double y){return abs(x-y)<1E-6;}
struct point
{
    double x,y;
    bool operator ==(point t)
    {
        return eq(x,t.x)&&eq(y,t.y);
    }
    point operator +(point t)
    {
        point ans;
        ans.x=x+t.x;
        ans.y=y+t.y;
        return ans;
    }

    point operator -(point t)
    {
        point ans;
        ans.x=x-t.x;
        ans.y=y-t.y;
        return ans;
    }
    double operator *(point t)
    {
        return x*t.x+y*t.y;
    }
    double X(point t)
    {
        return x*t.y-y*t.x;
    }
    point mulnum(double t)
    {
        point ans;
        ans.x=x*t;
        ans.y=y*t;
        return ans;
    }
} a,b,c,d,t,o;
double r;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
bool inseg(point a,point l1,point l2)
{
    if (!eq((a-l1).X(a-l2),0)) return false;
    if ((a-l1)*(a-l2)>0) return false;
    return true;
}
bool inbeam(point a,point l1,point l2)
{
    return inseg(a,l1,l2)||inseg(l2,l1,a);
}
point cross(point a,point b,point o,double r)
{
    point pa,pb;
    double da,db,dc,delta,ans1,ans2;
    pa=b-a;
    pb=a-o;
    da=pa*pa;
    db=2*(pa*pb);
    dc=pb*pb-r*r;
    delta=db*db-4*da*dc;
    if (delta<0) return o;
    ans1=(-db-sqrt(delta))/(2*da);
    ans2=(-db+sqrt(delta))/(2*da);
    if (abs(ans1)<abs(ans2)) return a+pa.mulnum(ans1);
    else return a+pa.mulnum(ans2);
}
point reflect(point a,point l1,point l2)
{
    point pt0,pt;
    double t;
    pt0=l2-l1;
    pt.x=pt0.y;
    pt.y=-pt0.x;
    t=(-2*(pt*(a-l2)))/(pt*pt);
    return a+pt.mulnum(t);
}
int main()
{
    dats=read();
    tr(dat,1,dats)
    {
        double vx,vy;
        o.x=read(); o.y=read(); r=read();
        a.x=read(); a.y=read();
        vx=read(); vy=read();
        b.x=read(); b.y=read();
        t.x=a.x+vx; t.y=a.y+vy;
        printf("Case #%d: ",dat);
        c=cross(a,t,o,r);
        if (!(c==o) && inbeam(c,a,t)) d=reflect(a,o,c);
        else {c=a; d=t;}
        if (inseg(b,a,c)||inbeam(b,c,d)) puts("Yes"); else puts("No");
    }
    return 0;
}
