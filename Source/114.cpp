#include <bits/stdc++.h>
#define tr(i,l,r) for(i=(l);i<=(r);i++)
#define eps 1E-8
#define nonx 1E100
#define maxn 205
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
    friend bool operator!=(point a,point b){return cmp(a.x-b.x)!=0||cmp(a.y-b.y)!=0;}
} ;
const point nonp=point(nonx,nonx);
struct line
{
    point a,b;
    line(){}
    line(point pa,point pb){a=pa;b=pb;}
    point dir(){return b-a;}
} ;
const line nonl=line(nonp,nonp);
bool onseg(point a,line b)
{
	return cmp((a-b.a)^b.dir())==0&&cmp((a-b.a)*(a-b.b))<=0;
}
point cross(line a,line b)
{
    double t;
    if (cmp(t=a.dir()^b.dir())==0) return nonp;
    return a.a+((b.a-a.a)^b.dir())/t*a.dir();
}

point a[maxn];
int n,m,f[maxn],b[maxn][2];
int gfa(int x){return x==f[x]?x:f[x]=gfa(f[x]);}
void init()
{
	int i;
	scanf("%d%d",&n,&m);
	tr(i,1,n) scanf("%lf%lf",&a[i].x,&a[i].y);
	tr(i,1,m) scanf("%d%d",&b[i][0],&b[i][1]);
	tr(i,1,n) f[i]=i;
}
void work()
{
	int i,j,fx,fy;
	point t;
	line l1,l2;
	tr(i,1,n) tr(j,1,m)
		if (onseg(a[i],line(a[b[j][0]],a[b[j][1]])))
		{
			fx=gfa(i); fy=gfa(b[j][0]); f[fy]=fx;
			fx=gfa(i); fy=gfa(b[j][1]); f[fy]=fx;
		}
	tr(i,1,m-1) tr(j,i+1,m)
	{
		l1=line(a[b[i][0]],a[b[i][1]]);
		l2=line(a[b[j][0]],a[b[j][1]]);
		if ((t=cross(l1,l2))!=nonp&&onseg(t,l1)&&onseg(t,l2))
		{
			fx=gfa(b[i][0]); fy=gfa(b[j][0]); f[fy]=fx;
		}
	}
	//tr(i,1,n) cout<<gfa(i)<<' '; cout<<endl;
	tr(i,2,n)
		if (gfa(i)!=gfa(1))
		{
			printf("NO\n"); return;
		}
	printf("YES\n");
}
int main()
{
	//freopen("f.in","r",stdin);
	init();
	work();
	return 0;
}
