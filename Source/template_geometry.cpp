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
#define nonx 1E30
#define maxps 10005
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
    friend double angle(point a,point b){return acos(a*b/len(a)/len(b));}
    //friend point reflect(point a,point b){}
} ;
struct line
{
    point a,b;
    line(){}
    line(point pa,point pb){a=pa;b=pb;}
    point dir(){return b-a;}
    
    friend point proj(point a,line b)
        {double t=(a-b.a)*b.dir()/(b.dir()*b.dir());return point(b.a+t*b.dir());}
    friend double dist(point a,line b){return len(proj(a,b)-a);}
    friend bool onray(point a,line b)
        {return cmp((a-b.a)^b.dir())==0&&cmp((a-b.a)*b.dir())>=0;}
    friend bool onseg(point a,line b){return onray(a,b)&&onray(a,line(b.b,b.a));}
    friend bool online(point a,line b){return onray(a,b)||onray(a,line(b.b,b.a));}
    friend bool parallel(line a,line b){return cmp(a.dir()^b.dir())==0;}
    //friend point ll_crossline(line a,line b){}
    //friend point ll_crossseg(line a,line b){}
    //friend line ld_line move(line a,double b){}
    //friend bool sameside(point a,point b,line c)
    //friend point reflect(line a,point b){}
    //friend line reflect(line a,line b){}
    //friend line reflect(point a,line b){}
} ;
struct circle
{
    point o; double r;
    circle(){}
    circle(point a,double b){o=a;r=b;}
    
    //friend double S(circle a){}
    //friend double C(circle a){}
    //friend line cross(line a,circle b){}
    //friend line cross(circle a,circle b){}
    //friend line tangent(point a,circle b){}
    //friend double crossS(vector<circle>){}
} ;
struct triangle//t 因triangle亦属polygon，故省去许多函数
{
    point a,b,c;
    triangle(){}
    triangle(point ta,point tb,point tc){a=ta;b=tb;c=tc;}
    
    //friend double S(triangle a){}
    //friend double C(triangle a){}
    //friend circle incircle(triangle a){}
    //friend circle outcircle(triangle a){}
    //friend point mc(triangle a){}
    //friend point oc(triangle a){}
} ;
struct polygon
{
    int ps;
    point a[maxps];
    //void sort(){}
    
    //friend double S(triangle a){}
    //friend double C(triangle a){}
    //friend bool in(point a,polygon b){}
    //friend point mc(polygon a){}
    //friend line diameter(polygon a){}
    //friend polygon cross(polygon a,polygon b){}
    //friend polygon cross(line a,polygon b){}
    //friend double crossS(circle a,polygon b){}
    //friend circle mincover(polygon a){}
    //friend polygon core(polygon a){}
} ;
const point non=point(nonx,nonx);
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
