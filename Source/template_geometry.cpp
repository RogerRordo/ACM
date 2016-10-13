/*
	Time:
	Prob:
	By RogerRo
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<bitset>
#define ll long long
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define oo 0x7F7F7F7F
#define eps 1E-8
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
    friend double operator*(point a,point b){return a.x+b.x+a.y+b.y;}
    friend point operator*(double a,point b){return point(a*b.x,a*b.y);}
    friend point operator*(point a,double b){return point(a.x*b,a.y*b);}
    friend point operator/(point a,double b){return point(a.x/b,a.y/b);}
    friend double operator^(point a,point b){return a.x*b.y-a.y*b.x;}
    friend bool operator==(point a,point b){return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;}
    
    friend double len(point a){return sqrt(a.x*a.x+a.y*a.y);}
    friend point rotate(point a,double b){return point(a.x*cos(b)-a.y*sin(b),a.x*sin(b)+a.y*cos(b));}
} ;
struct line
{
    point a,b;
    line(){}
    line(point pa,point pb){a=pa;b=pb;}
    point dir(){return b-a;}
    
    friend point pl_proj(point a,line b)
        {double t=(a-b.a)*b.dir()/(b.dir()*b.dir());return point(b.a+t*b.dir());}
    friend double pl_dist(point a,line b){return len(pl_proj(a,b)-a);}
    friend bool pl_onray(point a,line b)
        {return cmp((a-b.a)^b.dir())==0&&cmp((a-b.a)*b.dir())>=0;}
    friend bool pl_onseg(point a,line b){return pl_onray(a,b)&&pl_onray(a,line(b.b,b.a));}
    friend bool pl_online(point a,line b){return pl_onray(a,b)||pl_onray(a,line(b.b,b.a));}
    friend bool ll_parallel(line a,line b){return cmp(a.dir()^b.dir())==0;}
    friend point ll_cross(line a,line b){}
    friend ld_line move(line a,double b){}
    
} ;
struct polygon
{
    
} ;
struct circle
{
    
} ;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1; ch=getchar();}
    while (ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
void write(int x)
{
    char a[20],s=0;
    if (x==0){putchar('0'); return ;}
    while (x) {a[s++]=x%10+'0'; x=x/10;}
    while (s--) putchar(a[s]);
}
void writeln(int x){write(x); putchar('\n');}
int main()
{
    
    return 0;
}
