#include<bits/stdc++.h>
#define tr(i,l,r) for((i)=(l);(i)<=(r);++i)
#define maxn 1005
#define N 4000
using namespace std;
const double pi=acos(-1.0);
struct point
{
	double x,y;
	point(){}
	point(double xx,double yy):x(xx),y(yy){}
};
point operator+(point a,point b){return point(a.x+b.x,a.y+b.y);}
double len(point t){return sqrt(t.x*t.x+t.y*t.y);}

int n;
point a[maxn];
double ans[maxn];
pair<double,int> b[maxn];	//for sort

void init()
{
	int i;
	scanf("%d",&n);
	tr(i,1,n) scanf("%lf%lf",&a[i].x,&a[i].y);
}
void work()
{
	int i,j;
	double tx,ty,l;
	tr(i,0,N-1)
	{
		tx=cos(2*pi*i/N); ty=sin(2*pi*i/N);
		tr(j,1,n) b[j]=make_pair(tx*a[j].x+ty*a[j].y,j);
		sort(b+1,b+n+1,greater<pair<double,int> >());
		point t=point(0,0);
		tr(j,1,n)
		{
			t=t+a[b[j].second]; l=len(t); 
			if (l>ans[j]) ans[j]=l;
		}
	}
	tr(i,1,n) printf("%.6lf\n",ans[i]);
}
int main()
{
    init();
    work();
    return 0;
}
