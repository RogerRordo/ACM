#define maxpn 20//100010
#define nonx 1E100
#define eps 1E-8
const double pi=acos(-1.0);
//===========================================================
int cmp(double x)
{
    if (x>eps) return 1;
    if (x<-eps) return -1;
    return 0;
}
double sqr(double a){return a*a;}
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}
//===========================================================
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
struct circle
{
    point o; double r;
    circle(){}
    circle(point a,double b){o=a;r=b;}
} ;
struct triangle//t 因triangle亦属polygon，故省去许多函数
{
    point a,b,c;
    triangle(){}
    triangle(point ta,point tb,point tc){a=ta;b=tb;c=tc;}
} ;
struct polygon
{
    int n; point a[maxpn];  //逆时针！
    polygon(){}
    polygon(triangle t){n=3;a[1]=t.a;a[2]=t.b;a[3]=t.c;}
    point& operator[](int _){return a[_];}
} ;
//===========================================================
double sqr(point a){return a*a;}
double len(point a){return sqrt(sqr(a));}    //模长
point rotate(point a,double b){return point(a.x*cos(b)-a.y*sin(b),a.x*sin(b)+a.y*cos(b));}   //逆时针旋转
double angle(point a,point b){return acos(a*b/len(a)/len(b));}   //夹角
point reflect(point a,point b){return 2*a-b;}    //以a为中心对称
//===========================================================
point quad(double A,double B,double C)
{
    double delta=sqr(B)-4*A*C;
    if (delta<0) return nonp;
    return point((-B-sqrt(delta))/(2*A),(-B+sqrt(delta))/(2*A));
}
point proj(point a,line b){double t=(a-b.a)*b.dir()/sqr(b.dir());return point(b.a+t*b.dir());}   //垂足
double dist(point a,line b){return ((a-b.a)^(b.b-b.a))/len(b.dir());}    //点到线距离
bool onray(point a,line b){return cmp((a-b.a)^b.dir())==0&&cmp((a-b.a)*b.dir())>=0;} //判断点在射线上
bool onseg(point a,line b){return cmp((a-b.a)^b.dir())==0&&cmp((a-b.a)*(a-b.b))<=0;} //判断点在线段上
bool online(point a,line b){return cmp((a-b.a)^b.dir())==0;} //判断点在直线上
bool parallel(line a,line b){return cmp(a.dir()^b.dir())==0;}    //判断两线平行
point cross(line a,line b)   //线交
{
    double t;
    if (cmp(t=a.dir()^b.dir())==0) return nonp;
    return a.a+((b.a-a.a)^b.dir())/t*a.dir();
}
//===========================================================
double S(circle a){return pi*sqr(a.r);}  //面积
double C(circle a){return 2*pi*a.r;} //周长
line cross(line a,circle b)  //线圆交
{
    point t=quad(sqr(a.dir()),2*a.dir()*(a.a-b.o),sqr(a.a-b.o)-sqr(b.r));
    if (t==nonp) return nonl;
    return line(a.a+t.x*a.dir(),a.a+t.y*a.dir());
}
int in(point a,circle b){double t=len(a-b.o);return t==b.r?2:t<b.r;} //点与圆位置关系 0外 1内 2上
line cross(circle a,circle b)
{
    double d=len(a.o-b.o);
    if (cmp(abs(a.r-b.r)-d)>0||cmp(d-(a.r+b.r))>0) return nonl;
    double c=acos((sqr(a.r)+sqr(d)-sqr(b.r))/(2.0*a.r*d));
    point v=(b.o-a.o)/d*a.r;
    return line(a.o+rotate(v,-c),a.o+rotate(v,c));
}
//line tangent(point a,circle b){}
//pair<line,line> tangent(circle a,circle b){}
//double unionS(int n,circle*a) //圆面积并
//{}
//===========================================================
double S(triangle a){return abs((a.b-a.a)^(a.c-a.a))/2;} //面积
double C(triangle a){return len(a.a-a.b)+len(a.a-a.c)+len(a.a-a.c);} //周长
circle outcircle(triangle a) //外接圆
{
    circle res; point t1=a.b-a.a,t2=a.c-a.a;
    double t=2*t1^t2;
    res.o.x=a.a.x+(sqr(t1)*t2.y-sqr(t2)*t1.y)/t;
    res.o.y=a.a.y+(sqr(t2)*t1.x-sqr(t1)*t2.x)/t;
    res.r=len(res.o-a.a);
    return res;
}
circle incircle(triangle a)  //内切圆
{
    circle res; double x=len(a.b-a.c),y=len(a.c-a.a),z=len(a.a-a.b);
    res.o=(a.a*x+a.b*y+a.c*z)/(x+y+z);
    res.r=dist(res.o,line(a.a,a.b));
    return res;
}
point gc(triangle a){return (a.a+a.b+a.c)/3;}    //重心
point hc(triangle a){return 3*gc(a)-2*outcircle(a).o;}   //垂心
//===========================================================
double S(polygon&a)  //面积 O(n)
{
    int i; double res=0;
    a[a.n+1]=a[1];
    tr(i,1,a.n) res+=a[i]^a[i+1];
    return res/2;
}
double C(polygon&a) //周长 O(n)
{
    int i; double res=0;
    a[a.n+1]=a[1];
    tr(i,1,a.n) res+=len(a[i+1]-a[i]);
    return res;
}
int in(point a,polygon&b)  //点与多边形位置关系 0外 1内 2上 O(n)
{
    int s=0,i,d1,d2,k;
    b[b.n+1]=b[1];
    tr(i,1,b.n)
    {
        if (onseg(a,line(b[i],b[i+1]))) return 2;
        k=cmp((b[i+1]-b[i])^(b[i]-a));
        d1=cmp(b[i].y-a.y);
        d2=cmp(b[i+1].y-a.y);
        s=s+(k>0&&d2<=0&&d1>0)-(k<0&&d1<=0&&d2>0);
    }
    return s!=0;
}
point gc(polygon&a)  //重心 O(n)
{
    double s=S(a); point t(0,0); int i;
    if (cmp(s)==0) return nonp;
    a[a.n+1]=a[1];
    tr(i,1,a.n) t=t+(a[i]+a[i+1])*(a[i]^a[i+1]);
    return t/s/6;
}
int pick_on(polygon&a)  //皮克求边上格点数 O(n)
{
    int s=0,i;
    a[a.n+1]=a[1];
    tr(i,1,a.n) s+=gcd(abs(int(a[i+1].x-a[i].x)),abs(int(a[i+1].y-a[i].y)));
    return s;
}
int pick_in(polygon&a){return int(S(a))+1-pick_on(a)/2;} //皮克求多边形内格点数 O(n)

bool __cmpx(point a,point b){return cmp(a.x-b.x)<0;}
bool __cmpy(point a,point b){return cmp(a.y-b.y)<0;}
double __mindist(point *a,int l,int r)
{
    double ans=nonx;
    if (l==r) return ans;
    int i,j,tl,tr,mid=(l+r)/2;
    ans=min(__mindist(a,l,mid),__mindist(a,mid+1,r));
    for(tl=mid;tl>=l&&a[tl].x>=a[mid].x-ans;tl--); tl++;
    for(tr=mid+1;tr<=r&&a[tr].x<=a[mid].x+ans;tr++); tr--;
    sort(a+tl+1,a+tr+1,__cmpy);
    tr(i,tl,tr-1) tr(j,i+1,min(tr,i+4)) ans=min(ans,len(a[i]-a[j]));
    sort(a+tl+1,a+tr+1,__cmpx);
    return ans;
}
double mindist(polygon&a) //a只是点集 O(nlogn)
{
    sort(a.a+1,a.a+a.n+1,__cmpx);
    return __mindist(a.a,1,a.n);
}
//line convex_maxdist(polygon a){}
bool __cmpconvex(point a,point b){return cmp(a.x-b.x)<0||(cmp(a.x-b.x)==0&&cmp(a.y-b.y)<0);}
void convex_hull(polygon&a,polygon&b) //a只是点集 O(nlogn)
{
    int i,t;
    sort(a.a+1,a.a+a.n+1,__cmpconvex);
    b.n=0;
    tr(i,1,a.n)
    {
        while (b.n>=2&&cmp((b[b.n]-b[b.n-1])^(a[i]-b[b.n-1]))<=0) b.n--;
        b[++b.n]=a[i];
    }
    t=b.n;
    rtr(i,a.n-1,1)
    {
        while (b.n>t&&cmp((b[b.n]-b[b.n-1])^(a[i]-b[b.n-1]))<=0) b.n--;
        b[++b.n]=a[i];
    }
    b.n--;
}
//int convex_in(point a,polygon b){} //0外 1内 2上 O(logn)
//polygon cross(polygon a,polygon b){}
//polygon cross(line a,polygon b){}
//double unionS(circle a,polygon b){}
circle mincovercircle(polygon&a) //最小圆覆盖 O(n)
{
    circle t; int i,j,k;
    srand(time(0));
    random_shuffle(a.a+1,a.a+a.n+1);
    for(i=2,t=circle(a[1],0);i<=a.n;i++) if (!in(a[i],t))
    for(j=1,t=circle(a[i],0);j<i;j++) if (!in(a[j],t))
    for(k=1,t=circle((a[i]+a[j])/2,len(a[i]-a[j])/2);k<j;k++) if (!in(a[k],t))
    t=outcircle(triangle(a[i],a[j],a[k]));
    return t;
}
